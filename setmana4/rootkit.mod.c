#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/export-internal.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
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

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif


static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xfcca5424, "register_kprobe" },
	{ 0x63026490, "unregister_kprobe" },
	{ 0xafd744c6, "__x86_indirect_thunk_rbp" },
	{ 0xce543415, "ftrace_set_filter_ip" },
	{ 0xfe202707, "register_ftrace_function" },
	{ 0x92997ed8, "_printk" },
	{ 0xf33c2f36, "unregister_ftrace_function" },
	{ 0x59309edc, "prepare_creds" },
	{ 0x2c179a25, "commit_creds" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x94a9c4ab, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "5597D363BD893DFA707D9B7");
