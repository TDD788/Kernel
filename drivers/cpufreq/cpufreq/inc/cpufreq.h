/*
 */

/*
 * performance:
 * min: 800 MHz
 * max: 2.2 GHz
 */
#define PERF_BIG_MIN_HZ     801000
#define PERF_BIG_MAX_HZ     2210000
#define PERF_LITTLE_MIN_HZ  801000
#define PERF_LITTLE_MAX_HZ  2210000

/*
 * powersave:
 * min: 110 MHz
 * max: 1.8 GHz
 */
#define PSV_BIG_MIN_HZ    111000
#define PSV_BIG_MAX_HZ    1810000
#define PSV_LITTLE_MIN_HZ 111000
#define PSV_LITTLE_MAX_HZ 1810000


/* 
 * default:
 * min: 546 MHz
 * max: 2.0 GHz
 */
#define DEF_BIG_MIN_HZ    546000
#define DEF_BIG_MAX_HZ    2010000
#define DEF_LITTLE_MIN_HZ 546000
#define DEF_LITTLE_MAX_HZ 2010000

/* declare it as global value */
extern unsigned long big_core_min_hz_val(void);
extern unsigned long big_core_max_hz_val(void);
extern unsigned long little_core_min_hz_val(void);
extern unsigned long little_core_max_hz_val(void);
