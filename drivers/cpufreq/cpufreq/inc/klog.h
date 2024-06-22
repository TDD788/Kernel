// Rissu: logger
#include <linux/printk.h>

#ifndef pr_fmt
#define pr_fmt(fmt) "dev_cpu: " fmt
#else
#undef pr_fmt
#define pr_fmt(fmt) "dev_cpu: " fmt
#endif
