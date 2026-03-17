#include <linux/module.h>
#include <linux/export-internal.h>
#include <linux/compiler.h>

MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};



static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x66413b57, "i2c_register_driver" },
	{ 0x39439cdf, "drm_mode_duplicate" },
	{ 0x4a35d30d, "drm_mode_set_name" },
	{ 0x595ea9b6, "drm_mode_probed_add" },
	{ 0xd4099a0b, "drm_display_info_set_bus_formats" },
	{ 0x3bdb815f, "drm_connector_set_panel_orientation" },
	{ 0xf1b5340a, "drm_mode_vrefresh" },
	{ 0x26ec22df, "_dev_err" },
	{ 0x6f574c97, "i2c_del_driver" },
	{ 0xeaf314ca, "i2c_smbus_write_byte_data" },
	{ 0x10a3bca5, "drm_panel_remove" },
	{ 0x36a78de3, "devm_kmalloc" },
	{ 0xaf639b91, "of_device_get_match_data" },
	{ 0x7e7b9899, "of_drm_get_panel_orientation" },
	{ 0x38b95834, "of_graph_get_next_endpoint" },
	{ 0x3cd4b93b, "of_graph_get_remote_port_parent" },
	{ 0x6485236e, "of_find_mipi_dsi_host_by_node" },
	{ 0x469438cc, "of_node_put" },
	{ 0x292837a4, "of_graph_get_remote_port" },
	{ 0x5b46b83a, "devm_mipi_dsi_device_register_full" },
	{ 0xe9057ca6, "drm_panel_init" },
	{ 0x9716458e, "devm_backlight_device_register" },
	{ 0x4e797082, "drm_panel_add" },
	{ 0x14f71ff0, "devm_mipi_dsi_attach" },
	{ 0xf0fdf6cb, "__stack_chk_fail" },
	{ 0x474e54d2, "module_layout" },
};

MODULE_INFO(depends, "drm,backlight");

MODULE_ALIAS("of:N*T*Copendisplay,2.8inch-panel");
MODULE_ALIAS("of:N*T*Copendisplay,2.8inch-panelC*");
MODULE_ALIAS("of:N*T*Copendisplay,3.4inch-panel");
MODULE_ALIAS("of:N*T*Copendisplay,3.4inch-panelC*");
MODULE_ALIAS("of:N*T*Copendisplay,4.0inch-panel");
MODULE_ALIAS("of:N*T*Copendisplay,4.0inch-panelC*");
MODULE_ALIAS("of:N*T*Copendisplay,7.0inch-c-panel");
MODULE_ALIAS("of:N*T*Copendisplay,7.0inch-c-panelC*");
MODULE_ALIAS("of:N*T*Copendisplay,7.9inch-panel");
MODULE_ALIAS("of:N*T*Copendisplay,7.9inch-panelC*");
MODULE_ALIAS("of:N*T*Copendisplay,8.0inch-panel");
MODULE_ALIAS("of:N*T*Copendisplay,8.0inch-panelC*");
MODULE_ALIAS("of:N*T*Copendisplay,10.1inch-panel");
MODULE_ALIAS("of:N*T*Copendisplay,10.1inch-panelC*");
MODULE_ALIAS("of:N*T*Copendisplay,11.9inch-panel");
MODULE_ALIAS("of:N*T*Copendisplay,11.9inch-panelC*");
MODULE_ALIAS("of:N*T*Copendisplay,4inch-panel");
MODULE_ALIAS("of:N*T*Copendisplay,4inch-panelC*");
MODULE_ALIAS("of:N*T*Copendisplay,5.0inch-panel");
MODULE_ALIAS("of:N*T*Copendisplay,5.0inch-panelC*");
MODULE_ALIAS("of:N*T*Copendisplay,6.25inch-panel");
MODULE_ALIAS("of:N*T*Copendisplay,6.25inch-panelC*");
MODULE_ALIAS("of:N*T*Copendisplay,8.8inch-panel");
MODULE_ALIAS("of:N*T*Copendisplay,8.8inch-panelC*");
MODULE_ALIAS("of:N*T*Copendisplay,13.3inch-4lane-panel");
MODULE_ALIAS("of:N*T*Copendisplay,13.3inch-4lane-panelC*");
MODULE_ALIAS("of:N*T*Copendisplay,13.3inch-2lane-panel");
MODULE_ALIAS("of:N*T*Copendisplay,13.3inch-2lane-panelC*");
MODULE_ALIAS("of:N*T*Copendisplay,7.0inch-h-panel");
MODULE_ALIAS("of:N*T*Copendisplay,7.0inch-h-panelC*");

MODULE_INFO(srcversion, "E85D1DBAEE10EB9C3BF1275");
