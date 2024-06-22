ccflags-y := -I$(srctree)/drivers/cpufreq -I$(srctree)/$(src)/inc

exynos_acme-objs += src/cpufreq.o
exynos_acme-objs += src/exynos-acme.o

obj-$(CONFIG_USE_RSUNTK_EXYNOS_ACME) += exynos_acme.o
