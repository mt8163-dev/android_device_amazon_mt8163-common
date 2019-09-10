DEVICE_COMMON := device/amazon/douglas
VENDOR_COMMON := vendor/amazon/douglas

# headers
TARGET_SPECIFIC_HEADER_PATH := $(DEVICE_COMMON)/include

# inherit from the proprietary version
-include $(VENDOR_COMMON)/BoardConfigVendor.mk

# Platform
TARGET_BOARD_PLATFORM := mt8163
TARGET_BOARD_PLATFORM_GPU := mali-720mp2
BOARD_USES_MTK_AUDIO := true

# Project Config
MTK_PROJECT_CONFIG ?= $(DEVICE_COMMON)/ProjectConfig.mk
include $(MTK_PROJECT_CONFIG)

# Flags
TARGET_GLOBAL_CFLAGS += -mfpu=neon -mfloat-abi=softfp
TARGET_GLOBAL_CPPFLAGS += -DMTK_HARDWARE -mfpu=neon -mfloat-abi=softfp
COMMON_GLOBAL_CFLAGS += -DMTK_HARDWARE -DREFRESH_RATE=60
COMMON_GLOBAL_CFLAGS += -DAMAZON_LOG -DADD_LEGACY_ACQUIRE_BUFFER_SYMBOL
COMMON_GLOBAL_CFLAGS += -DNO_SECURE_DISCARD

# Bootloader
TARGET_NO_BOOTLOADER := true

# Mediatek support
BOARD_USES_MTK_HARDWARE := true
MTK_HARDWARE := true

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
#BOARD_KERNEL_IMAGE_NAME := Image.gz-dtb
#TARGET_KERNEL_SOURCE := kernel/amazon/douglas
#TARGET_KERNEL_CONFIG := douglas_defconfig
BOARD_KERNEL_CMDLINE := bootopt=64S3,32N2,64N2
BOARD_KERNEL_CMDLINE += androidboot.selinux=permissive


# Binder API version
TARGET_USES_64_BIT_BINDER := true
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
TARGET_USES_C2D_COMPOSITION := true
TARGET_USES_OVERLAY := true
TARGET_USES_OVERLAY := true
NUM_FRAMEBUFFER_SURFACE_BUFFERS := 3
TARGET_RUNNING_WITHOUT_SYNC_FRAMEWORK := true
TARGET_FORCE_HWC_FOR_VIRTUAL_DISPLAYS := true
MAX_VIRTUAL_DISPLAY_DIMENSION := 1
MAX_EGL_CACHE_KEY_SIZE := 12*1024
MAX_EGL_CACHE_SIZE := 1024*1024

# VSYNC
SF_VSYNC_EVENT_PHASE_OFFSET_NS := -8000000
VSYNC_EVENT_PHASE_OFFSET_NS := -8000000
PRESENT_TIME_OFFSET_FROM_VSYNC_NS := 0
MTK_HWC_SUPPORT := yes
MTK_HWC_VERSION := 1.4.1

# Bootanimation
TARGET_BOOTANIMATION_MULTITHREAD_DECODE := true
TARGET_BOOTANIMATION_PRELOAD := true
TARGET_BOOTANIMATION_TEXTURE_CACHE := true
TARGET_SCREEN_WIDTH := 800
TARGET_SCREEN_HEIGHT := 1280


# Surfaceflinger
TARGET_FORCE_HWC_FOR_VIRTUAL_DISPLAYS := true
NUM_FRAMEBUFFER_SURFACE_BUFFERS := 3

# Filesystem
BOARD_BOOTIMAGE_PARTITION_SIZE := 16777216
BOARD_RECOVERYIMAGE_PARTITION_SIZE := 20971520
BOARD_SYSTEMIMAGE_PARTITION_SIZE := 1692925952
BOARD_USERDATAIMAGE_PARTITION_SIZE := 11633933824
BOARD_CACHEIMAGE_PARTITION_SIZE := 499261440
BOARD_FLASH_BLOCK_SIZE := 131072

TARGET_USERIMAGES_USE_EXT4 := true


# OTA Stuff
BLOCK_BASED_OTA := true
TARGET_OTA_ASSERT_DEVICE:= douglas

# Vold
TARGET_USE_CUSTOM_LUN_FILE_PATH := /sys/devices/platform/mt_usb/musb-hdrc.0.auto/gadget/lun%d/file

# Shims
# Are we using modified cutils & liblog? Shims are a bit weird on LP.
#TARGET_LD_SHIM_LIBS := \
    #/system/lib/libasp.so|libshim_liblog.so \
    #/system/lib64/libasp.so|libshim_liblog.so \
    #/system/lib/liblog.so|libshim_liblog.so \
    #/system/lib64/liblog.so|libshim_liblog.so \
    #/system/lib/libcutils.so|libshim_liblog.so \
    #/system/lib64/libcutils.so|libshim_liblog.so \
    #/system/lib/libtz_uree.so|libshim_tz_uree.so \
    #/system/lib64/litz_uree.so|libshim_tz_uree.so \
    #/system/lib/libgralloc_extra.so|libshim_gralloc_extra.so \
    #/system/lib64/libgralloc_extra.so|libshim_gralloc_extra.so

# Dexpreopt
ifeq ($(HOST_OS),linux)
  ifeq ($(TARGET_BUILD_VARIANT),user)
		WITH_DEXPREOPT ?= true
  endif
endif


# TWRP
TARGET_RECOVERY_FSTAB := device/amazon/douglas/recovery.fstab
TARGET_RECOVERY_PIXEL_FORMAT := "RGBX_8888"
BOARD_HAS_NO_SELECT_BUTTON := true
BOARD_USE_CUSTOM_RECOVERY_FONT := \"roboto_23x41.h\"
MALLOC_SVELTE := true

# BACKLIGHT
TARGET_PROVIDES_LIBLIGHT := true

# Disable API check
WITHOUT_CHECK_API := true

# Little hack for build with prebuilt kernel. Not needed if using kernel source.
$(shell mkdir -p $(OUT)/obj/KERNEL_OBJ/usr)

