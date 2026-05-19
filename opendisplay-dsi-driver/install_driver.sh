#!/bin/bash
set -e

# ================== PARAMS ==================
SIZE="$1"        # 5 or 7 inch
DSI="$2"         # dsi0 or dsi1 
ROTATION=270

if [[ -z "$SIZE" || -z "$DSI" ]]; then
    echo "Usage: $0 <5|7> <0|1>"
    echo "Example: $0 7 0"
    exit 1
fi

if [[ "$SIZE" != "5" && "$SIZE" != "7" ]]; then
    echo "ERROR: SIZE must be 5 or 7"
    exit 1
fi

if [[ "$DSI" != "0" && "$DSI" != "1" ]]; then
    echo "ERROR: DSI must be 0 or 1"
    exit 1
fi

PANEL="${SIZE}_0_inch"
DSI_PORT="dsi${DSI}"

# ================== PATHS ==================
KERNEL_VER=$(uname -r)
MODULE_NAME=opendisplay-dsi-driver
MODULE_PATH=/lib/modules/$KERNEL_VER/$MODULE_NAME.ko
CONFIG=/boot/firmware/config.txt

echo "Panel: ${PANEL}, ${DSI_PORT}, rotation=${ROTATION}"

echo "=== STEP 1: Remove old kernel module (ignore if not exist) ==="
sudo rm -f $MODULE_PATH

echo
echo "=== STEP 2: Build kernel module ==="
make clean || true
make

echo
echo "=== STEP 3: Install kernel module ==="
sudo cp $MODULE_NAME.ko /lib/modules/$KERNEL_VER/

echo
echo "=== STEP 4: depmod & modprobe ==="
sudo depmod
sudo modprobe $MODULE_NAME || true

echo
echo "=== STEP 5: Build device tree overlay ==="
dtc -I dts -O dtb \
    -o opendisplay-dsi-panel-overlay.dtbo \
    opendisplay-dsi-panel-overlay.dts

sudo cp opendisplay-dsi-panel-overlay.dtbo /boot/overlays/

echo
echo "=== STEP 6: Update /boot/firmware/config.txt ==="

# Ensure [all] exists
sudo grep -qxF "[all]" "$CONFIG" || echo "[all]" | sudo tee -a "$CONFIG" > /dev/null

# Ensure vc4-kms-v3d exists
sudo grep -qxF "dtoverlay=vc4-kms-v3d" "$CONFIG" || \
    echo "dtoverlay=vc4-kms-v3d" | sudo tee -a "$CONFIG" > /dev/null

# Remove ALL old opendisplay-dsi-panel-overlay lines
sudo sed -i '/^dtoverlay=opendisplay-dsi-panel-overlay/d' "$CONFIG"

# Add selected overlay
if [[ "$DSI" == "0" ]]; then
    OVERLAY_LINE="dtoverlay=opendisplay-dsi-panel-overlay,${PANEL},dsi0,rotation=${ROTATION}"
else
    OVERLAY_LINE="dtoverlay=opendisplay-dsi-panel-overlay,${PANEL},rotation=${ROTATION}"
fi
echo "$OVERLAY_LINE" | sudo tee -a "$CONFIG" > /dev/null
