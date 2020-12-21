#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>

#include "hello1.h"

int print_hello(uint n)
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
EXPORT_SYMBOL(print_hello);

static int __init hello1_init(void)
{
	pr_alert("Module \"hello1\" started!\n");
	return 0;
}

static void __exit hello1_exit(void)
{
	pr_alert("Module \"hello1\" closed!\n");
}

module_init(hello1_init);
module_exit(hello1_exit);

MODULE_AUTHOR("Max Afanasiev <max_afanasiev@example.cpm>");
MODULE_DESCRIPTION("Hello, world in Linux Kernel Training. Advanced, module 1.");
MODULE_LICENSE("Dual BSD/GPL");
