/*
 */
#include <linux/cpufreq.h>

#include "cpufreq.h"
#include "klog.h"

/* var 1 = performance mode, var 2 = powersave mode, and var 3 is the default, following dtb */

/* make a function to read current governor */
static int read_cpugov(void)
{
    int var;
    int big_min_hz, big_max_hz, little_min_hz, little_max_hz;
    struct cpufreq_policy *policy;
    
    if (strcmp(policy->governor->name, "performance") == 0) {
        big_min_hz = PERF_BIG_MIN_HZ;
        big_max_hz = PERF_BIG_MAX_HZ;
        little_min_hz = PERF_LITTLE_MIN_HZ;
        little_max_hz = PERF_LITTLE_MAX_HZ;
        
        pr_info("governor set to performance\n");
        pr_info("adjusting big_min_hz to %d, big_max_hz to %d, little_min_hz to %d, little_max_hz to %d\n",
            big_min_hz, big_max_hz, little_min_hz, little_max_hz);
        var = 1;
    } else if (strcmp(policy->governor->name, "powersave") == 0) {
        big_min_hz = PSV_BIG_MIN_HZ;
        big_max_hz = PSV_BIG_MAX_HZ;
        little_min_hz = PSV_LITTLE_MIN_HZ;
        little_max_hz = PSV_LITTLE_MAX_HZ;
        
        pr_info("governor set to powersave\n");
        pr_info("adjusting big_min_hz to %d, big_max_hz to %d, little_min_hz to %d, little_max_hz to %d\n",
            big_min_hz, big_max_hz, little_min_hz, little_max_hz);
        var = 2;
    } else {
        big_min_hz = DEF_BIG_MIN_HZ;
        big_max_hz = DEF_BIG_MAX_HZ;
        little_min_hz = DEF_LITTLE_MIN_HZ;
        little_max_hz = DEF_LITTLE_MAX_HZ;
        
        pr_info("governor set to default\n");
        pr_info("adjusting big_min_hz to %d, big_max_hz to %d, little_min_hz to %d, little_max_hz to %d\n",
            big_min_hz, big_max_hz, little_min_hz, little_max_hz);
        var = 3;
    }

    return var;
}

unsigned long big_core_min_hz_val(void)
{
    int case_var = read_cpugov();
    int big_min_hz;

    switch (case_var) {
        case 1:
            big_min_hz = PERF_BIG_MIN_HZ;
            break;
        case 2:
            big_min_hz = PSV_BIG_MIN_HZ;
            break;
        default:
            big_min_hz = DEF_BIG_MIN_HZ;
    }

    return big_min_hz;
}

unsigned long big_core_max_hz_val(void)
{
    int case_var = read_cpugov();
    int big_max_hz;

    switch (case_var) {
        case 1:
            big_max_hz = PERF_BIG_MAX_HZ;
            break;
        case 2:
            big_max_hz = PSV_BIG_MAX_HZ;
            break;
        default:
            big_max_hz = DEF_BIG_MAX_HZ;
    }

    return big_max_hz;
}

unsigned long little_core_min_hz_val(void)
{
    int case_var = read_cpugov();
    int little_min_hz;

    switch (case_var) {
        case 1:
            little_min_hz = PERF_LITTLE_MIN_HZ;
            break;
        case 2:
            little_min_hz = PSV_LITTLE_MIN_HZ;
            break;
        default:
            little_min_hz = DEF_LITTLE_MIN_HZ;
    }

    return little_min_hz;
}

unsigned long little_core_max_hz_val(void)
{
    int case_var = read_cpugov();
    int little_max_hz;

    switch (case_var) {
        case 1:
          little_max_hz = PERF_LITTLE_MAX_HZ;
          break;
        case 2:
          little_max_hz = PSV_LITTLE_MAX_HZ;
          break;
        default:
          little_max_hz = DEF_LITTLE_MAX_HZ;
    }

    return little_max_hz;
}
