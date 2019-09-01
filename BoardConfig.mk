DEVICE_COMMON := device/amazon/douglas
VENDOR_COMMON := vendor/amazon/douglas

# headers
TARGET_SPECIFIC_HEADER_PATH := $(DEVICE_COMMON)/include

# inherit from the proprietary version
-include $(VENDOR_COMMON)/BoardConfigVendor.mk

# Platform
TARGET_BOARD_PLATFORM := mt8163
TARGET_BOARD_PLATFORM_GPU := mali-720mp2


# Bootloader
TARGET_NO_BOOTLOADER := true

# Architecture
TARGET_ARCH := arm64
TARGET_ARCH_VARIANT := armv8-a
TARGET_CPU_ABI := arm64-v8a
TARGET_CPU_VARIANT := generic

TARGET_2ND_ARCH := arm
TARGET_2ND_ARCH_VARIANT := armv7-a-neon
TARGET_2ND_CPU_ABI := armeabi-v7a
TARGET_2ND_CPU_ABI2 := armeabi
TARGET_2ND_CPU_VARIANT := cortex-a15

TARGET_CPU_ABI_LIST := arm64-v8a,armeabi-v7a,armeabi
TARGET_CPU_ABI_LIST_64_BIT := arm64-v8a

# Kernel Config
MTK_APPENDED_DTB_SUPPORT := true
BOARD_KERNEL_BASE := 0x40078000
BOARD_KERNEL_PAGESIZE := 2048
BOARD_KERNEL_OFFSET := 0x00008000
BOARD_KERNEL_TAGS_OFFSET := 0x07f80000
BOARD_RAMDISK_OFFSET := 0x03f00000
BOARD_SECOND_OFFSET := 0x00e80000

BOARD_MKBOOTIMG_ARGS := \
    --kernel_offset $(BOARD_KERNEL_OFFSET) \
    --ramdisk_offset $(BOARD_RAMDISK_OFFSET) \
    --tags_offset $(BOARD_KERNEL_TAGS_OFFSET) \
    --second_offset $(BOARD_SECOND_OFFSET)

TARGET_PREBUILT_KERNEL := device/amazon/douglas/kernel
TARGET_KERNEL_ARCH := arm64

BOARD_KERNEL_CMDLINE := bootopt=64S3,32N2,64N2
BOARD_KERNEL_CMDLINE += androidboot.selinux=permissive

BOARD_HAS_MTK_HARDWARE := true

# Binder API version
TARGET_USES_64_BIT_BINDER := false

BOARD_NO_SECURE_DISCARD := true

# WIFI
WPA_SUPPLICANT_VERSION := VER_0_8_X
BOARD_HOSTAPD_DRIVER := NL80211
BOARD_HOSTAPD_PRIVATE_LIB := lib_driver_cmd_mt66xx
BOARD_WPA_SUPPLICANT_DRIVER := NL80211
BOARD_WPA_SUPPLICANT_PRIVATE_LIB := lib_driver_cmd_mt66xx
WIFI_DRIVER_FW_PATH_PARAM := "/dev/wmtWifi"
WIFI_DRIVER_FW_PATH_STA:=STA
WIFI_DRIVER_FW_PATH_AP:=AP
WIFI_DRIVER_FW_PATH_P2P:=P2P

# BT
BOARD_HAVE_BLUETOOTH := true
BOARD_HAVE_BLUETOOTH_MTK := true
BOARD_BLUETOOTH_DOES_NOT_USE_RFKILL := true
BOARD_BLUETOOTH_BDROID_BUILDCFG_INCLUDE_DIR := $(DEVICE_COMMON)/bluetooth

# Graphics
BOARD_EGL_CFG := $(DEVICE_COMMON)/configs/egl.cfg
USE_OPENGL_RENDERER := true
VSYNC_EVENT_PHASE_OFFSET_NS := 0
TARGET_RUNNING_WITHOUT_SYNC_FRAMEWORK := true
NUM_FRAMEBUFFER_SURFACE_BUFFERS := 3

# Filesystem
BOARD_BOOTIMAGE_PARTITION_SIZE := 16777216
BOARD_RECOVERYIMAGE_PARTITION_SIZE := 20971520
BOARD_SYSTEMIMAGE_PARTITION_SIZE := 3151745024
BOARD_USERDATAIMAGE_PARTITION_SIZE := 11633933824
BOARD_CACHEIMAGE_PARTITION_SIZE := 499261440
BOARD_VENDORIMAGE_PARTITION_SIZE := 224350208
BOARD_FLASH_BLOCK_SIZE := 131072

TARGET_USERIMAGES_USE_EXT4 := true

BLOCK_BASED_OTA := true

# Seccomp filter
BOARD_SECCOMP_POLICY += $(DEVICE_COMMON)/seccomp

# SELinux
BOARD_SEPOLICY_DIRS += $(DEVICE_COMMON)/sepolicy

# Vold
TARGET_USE_CUSTOM_LUN_FILE_PATH := /sys/devices/platform/mt_usb/musb-hdrc.0.auto/gadget/lun%d/file

# Shims
LINKER_FORCED_SHIM_LIBS := \
TARGET_LD_SHIM_LIBS := \
    /system/lib/libasp.so|libshim_liblog.so \
    /system/lib64/libasp.so|libshim_liblog.so \
    /system/lib/liblog.so|libshim_liblog.so \
    /system/lib64/liblog.so|libshim_liblog.so \
    /system/lib/libcutils.so|libshim_liblog.so \
    /system/lib64/libcutils.so|libshim_liblog.so \
    /system/lib/libtz_uree.so|libshim_tz_uree.so \
    /system/lib64/litz_uree.so|libshim_tz_uree.so \
    /system/lib/libgralloc_extra.so|libshim_gralloc_extra.so \
    /system/lib64/libgralloc_extra.so|libshim_gralloc_extra.so

# TWRP
ifneq (,$(strip $(wildcard bootable/recovery-twrp/twrp.cpp)))
RECOVERY_VARIANT := twrp
endif
DEVICE_RESOLUTION := 600x1024
TW_EXCLUDE_MTP := false
RECOVERY_SDCARD_ON_DATA := true
TW_BRIGHTNESS_PATH := /sys/devices/platform/leds-mt65xx/leds/lcd-backlight/brightness
TARGET_RECOVERY_LCD_BACKLIGHT_PATH := /sys/devices/platform/leds-mt65xx/leds/lcd-backlight/brightness
RECOVERY_GRAPHICS_USE_LINELENGTH := true
RECOVERY_FSTAB_VERSION := 2
TW_THEME := landscape_mdpi
#TWRP_EVENT_LOGGING := true
RECOVERY_TOUCHSCREEN_SWAP_XY := true
#RECOVERY_GRAPHICS_USE_LINELENGTH := true
#RECOVERY_TOUCHSCREEN_FLIP_Y := true 
RECOVERY_TOUCHSCREEN_FLIP_X := true
BOARD_HAS_FLIPPED_SCREEN := true

MALLOC_SVELTE := true

# Disable API check
WITHOUT_CHECK_API := true

# Little hack for build with prebuilt kernel
$(shell mkdir -p $(OUT)/obj/KERNEL_OBJ/usr)
