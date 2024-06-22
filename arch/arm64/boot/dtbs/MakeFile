DTC = dtc
DTC_FLAGS = -@ -O dtb -o
DTBO_IMG = dtbo.img
DTB_DIR = ..

DTBO_SOURCES = $(srctree)/arch/arm64/boot/dts/samsung/a12s/a12s_eur_open_w00_r00.dts $(srctree)/arch/arm64/boot/dts/samsung/a12s/a12s_eur_open_w00_r01.dts
DTB_SOURCE = $(srctree)/arch/arm64/boot/dts/exynos/exynos3830.dtb

DTBO_FILES = $(patsubst %.dts,$(DTB_DIR)/%.dtbo,$(DTBO_SOURCES))
DTB_FILE = $(DTB_DIR)/$(patsubst %.dts,%.dtb,$(DTB_SOURCE))
DTBO_IMG_FILE = $(DTB_DIR)/$(DTBO_IMG)

all: $(DTBO_IMG_FILE)

$(DTB_DIR)/%.dtbo: %.dts  | $(DTB_DIR)
	$(DTC) $(DTC_FLAGS) $@ $<

$(DTB_FILE): $(DTB_SOURCE) | $(DTB_DIR)
	$(DTC) $(DTC_FLAGS) $@ $<

$(DTBO_IMG_FILE): $(DTBO_FILES) | $(DTB_DIR)
	python3 merge_dtbo.py $@ $(DTBO_FILES)
	rm -f $(DTBO_FILES)

$(DTB_DIR):
	mkdir -p $(DTB_DIR)

clean:
	rm -rf $(DTB_DIR)

.PHONY: all clean