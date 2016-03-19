#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/init.h>
#include <linux/kallsyms.h>
#include <asm/unistd.h>
#include <linux/uaccess.h>

MODULE_AUTHOR("Oscar Forner Martinez");
MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("This module is to replace the open syscall to our own open syscall. Our own open syscall will replace the opening of all *.mp3 file by the file provided as a parameter (song).");

static char *song = NULL;
static char *pict = NULL;

module_param(song, charp, 0000);
MODULE_PARM_DESC(song, "Path to the song to open always.");

module_param(pict, charp, 0000);
MODULE_PARM_DESC(pict, "Path to the picture to open always.");

static void **sys_call_table = NULL;

static asmlinkage long (*old_open) (const char __user *filename, int flags, umode_t mode);

static asmlinkage long rick_open(const char __user *filename, int flags, umode_t mode)
{
	size_t len = strlen(filename);
	const char *ext = filename + len - 4;
	if (strncmp(ext, ".mp3", 4) == 0 && song != NULL)
	{
		copy_to_user((void *)filename, song, len);
	}
	if (strncmp(ext, ".jpg", 4) == 0 && pict != NULL)
	{
		copy_to_user((void *)filename, pict, len);
	}
	pr_info("Let's play!\n");
	return old_open(filename, flags, mode);
}

static int __init set_rick(void)
{
	if (song == NULL && pict == NULL)
	{
		pr_info("Rickroll module not loaded. You need to provide a song and/or a picture as a parameter\n");
		return -1;
	}
	sys_call_table = (void **)kallsyms_lookup_name("sys_call_table");
	pr_info("Found sys_call_table at %p\n", sys_call_table);
	old_open = sys_call_table[__NR_open];
	sys_call_table[__NR_open] = rick_open;
	pr_info("Old open: %p; Rick open: %p\n", old_open, rick_open);
	return 0;
}

static void __exit unset_rick(void)
{
	pr_info("Party is over :(\n");
	sys_call_table[__NR_open] = old_open;
}

module_init(set_rick);
module_exit(unset_rick);
