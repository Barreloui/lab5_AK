#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>
#include <linux/moduleparam.h>
#include <linux/errno.h>

static uint n = 1;
module_param(n, uint, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
MODULE_PARM_DESC(n, "A parameter that determines the number of messages. Recommended values: 1-5; unwanted values: 0, 6-10; invalid values: >10, <0;");

static int __init hello_init(void)
{
	printk(KERN_EMERG "Parameter values: %u", n);

	if (n <= 10) {
		int i;

		if (n == 0) {
			printk(KERN_WARNING "Warning: low parameter value!\n");
		} else if (n > 5) {
			printk(KERN_WARNING "Warning: values in the range 6-10 are undesirable!\n");
		}
		
		for (i = 0; i < n; i++) {
			printk(KERN_EMERG "Hello, world!\n");
		}
	} else {
		printk(KERN_ERR "Error: parameter value is greater than 10!\n");
		return -EINVAL;
	}
	return 0;
}

static void __exit hello_exit(void)
{
	/* Do nothing here right now */
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_AUTHOR("Max Afanasiev <max_afanasiev@example.cpm>");
MODULE_DESCRIPTION("Hello, world in Linux Kernel Training");
MODULE_LICENSE("Dual BSD/GPL");
