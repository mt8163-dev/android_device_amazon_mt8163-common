DEVICE_COMMON := device/amazon/mt8163-common
KERNEL_COMMON := kernel/amazon/mt8163
VENDOR_COMMON := vendor/amazon/mt8163-common

# inherit from the proprietary version
-include $(VENDOR_COMMON)/BoardConfigVendor.mk

# Platform
TARGET_BOARD_PLATFORM := mt8163
TARGET_NO_BOOTLOADER := true

# GPU
TARGET_BOARD_PLATFORM_GPU := mali-720mp2

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
TARGET_CPU_SMP := true

# Bootloader
TARGET_BOOTLOADER_BOARD_NAME := mt8163

# Filesystems
TARGET_USERIMAGES_USE_EXT4:= true
TARGET_USERIMAGES_SPARSE_EXT_DISABLED := false
BOARD_CACHEIMAGE_FILE_SYSTEM_TYPE := ext4

# Kernel
BOARD_KERNEL_CMDLINE := bootopt=64S3,32N2,64N2
BOARD_KERNEL_CMDLINE += androidboot.selinux=permissive
BOARD_KERNEL_BASE := 0x40078000
BOARD_KERNEL_PAGESIZE := 2048
BOARD_MKBOOTIMG_ARGS := \
	--base 0x40078000 \
	--pagesize 2048 \
	--kernel_offset 0x00008000 \
	--ramdisk_offset 0x03f88000 \
	--second_offset 0x00e88000 \
	--tags_offset 0x07f88000

TARGET_KERNEL_SOURCE := $(KERNEL_COMMON)
TARGET_KERNEL_ARCH := arm64
TARGET_KERNEL_HEADER_ARCH := arm64
TARGET_KERNEL_CROSS_COMPILE_PREFIX := $(shell pwd)/prebuilts/gcc/linux-x86/aarch64/aarch64-linux-android-4.9/bin/aarch64-linux-android-
BOARD_KERNEL_IMAGE_NAME := Image.gz-dtb

# 64 Bit Binder Userspace
TARGET_USES_64_BIT_BINDER := true

# Kernel Modules
TARGET_KMODULES := true

# Disable memcpy opt (for audio libraries)
TARGET_CPU_MEMCPY_OPT_DISABLE := true

# Audio
BOARD_USES_MTK_AUDIO := true
BOARD_SUPPORTS_SOUND_TRIGGER := true
USE_XML_AUDIO_POLICY_CONF := 0

# OMX
TARGET_OMX_LEGACY_RESCALING:= true

# EGL
BOARD_EGL_CFG := $(DEVICE_COMMON)/configs/graphics/egl.cfg
USE_OPENGL_RENDERER := true
BOARD_EGL_WORKAROUND_BUG_10194508 := true
TARGET_USES_C2D_COMPOSITION := true
TARGET_USES_OVERLAY := true
TARGET_RUNNING_WITHOUT_SYNC_FRAMEWORK := true
TARGET_FORCE_HWC_FOR_VIRTUAL_DISPLAYS := true
MAX_VIRTUAL_DISPLAY_DIMENSION := 1
MAX_EGL_CACHE_KEY_SIZE := 12*1024
MAX_EGL_CACHE_SIZE := 1024*1024

# MediaTek Hardware
BOARD_HAS_MTK_HARDWARE := true
MTK_HARDWARE := true

# MediaTek Legacy AV Blob
BOARD_USES_LEGACY_MTK_AV_BLOB := true

# WIFI
BOARD_CONNECTIVITY_VENDOR        := MediaTek
WPA_SUPPLICANT_VERSION           := VER_0_8_X
BOARD_HOSTAPD_DRIVER             := NL80211
BOARD_HOSTAPD_PRIVATE_LIB        := lib_driver_cmd_mt66xx
BOARD_WPA_SUPPLICANT_DRIVER      := NL80211
BOARD_WPA_SUPPLICANT_PRIVATE_LIB := lib_driver_cmd_mt66xx
WIFI_DRIVER_FW_PATH_PARAM        := "/dev/wmtWifi"
WIFI_DRIVER_FW_PATH_STA          := STA
WIFI_DRIVER_FW_PATH_AP           := AP
WIFI_DRIVER_FW_PATH_P2P          := P2P
WIFI_DRIVER_STATE_CTRL_PARAM	 := "/dev/wmtWifi"
WIFI_DRIVER_STATE_ON		 := 1
WIFI_DRIVER_STATE_OFF		 := 0

# Bluetooth
BOARD_HAVE_BLUETOOTH := true
BOARD_HAVE_BLUETOOTH_MTK := true
BOARD_BLUETOOTH_DOES_NOT_USE_RFKILL := true
BOARD_BLUETOOTH_BDROID_BUILDCFG_INCLUDE_DIR := $(DEVICE_COMMON)/bluetooth

# Camera
TARGET_HAS_LEGACY_CAMERA_HAL1 := true
TARGET_SPECIFIC_CAMERA_PARAMETER_LIBRARY := libcamera_parameters_mtk
TARGET_USES_NON_TREBLE_CAMERA := true

# Digital Restrictions Management (DRM)
MTK_WVDRM_SUPPORT := yes
MTK_WVDRM_L1_SUPPORT := yes

# Recovery Partition Table
TARGET_RECOVERY_FSTAB := $(DEVICE_COMMON)/recovery/etc/recovery.fstab

# Screen/Bootanimation
DEVICE_RESOLUTION := 800x1280
TARGET_SCREEN_WIDTH := 800
TARGET_SCREEN_HEIGHT := 1280
TARGET_BOOTANIMATION_MULTITHREAD_DECODE := true
TARGET_BOOTANIMATION_PRELOAD := true
TARGET_BOOTANIMATION_TEXTURE_CACHE := true
TARGET_BOOTANIMATION_HALF_RES := true

# Enable Minikin Text Layout Engine
USE_MINIKIN := true

# Use dlmalloc Instead of Jemalloc for Mallocs
MALLOC_SVELTE := true

# Sotrage Lun File Path
TARGET_USE_CUSTOM_LUN_FILE_PATH := "/sys/devices/virtual/android_usb/android0/f_mass_storage/lun%d/file"

# Manifest
DEVICE_MANIFEST_FILE := $(DEVICE_COMMON)/manifest.xml

# SELinux
BOARD_SEPOLICY_DIRS += \
    $(DEVICE_COMMON)/sepolicy

# LineageOS Hardware
BOARD_USES_LINEAGE_HARDWARE := true
BOARD_HARDWARE_CLASS := $(DEVICE_COMMON)/lineagehw

# Shim Libraries
TARGET_LD_SHIM_LIBS := \
    /system/lib/libMtkOmxVdecEx.so|libshim_ui.so \
    /system/lib/libMtkOmxVenc.so|libshim_ui.so \
    /system/lib/libasp.so|libshim_parcel.so \
    /system/lib64/libasp.so|libshim_parcel.so \
    /system/lib/libdrmmtkutil.so|libshim_drm.so \
    /system/lib64/libdrmmtkutil.so|libshim_drm.so \
    /system/lib/libui_ext.so|libshim_ui.so \
    /system/lib64/libui_ext.so|libshim_ui.so \
    /system/lib/libcam_utils.so|libshim_ui.so \
    /system/lib64/libcam_utils.so|libshim_ui.so \
    /system/bin/amzn_dha_hmac|libshim_drm.so \
    /system/bin/amzn_dha_tool|libshim_drm.so \
    /system/lib/libcam_utils.so|libshim_camera.so \
    /system/lib64/libcam_utils.so|libshim_camera.so \
    /system/bin/amzn_dha_hmac|libshim_drm.so \
    /system/bin/amzn_dha_tool|libshim_drm.so \
    /system/lib/libcam.utils.sensorlistener.so|libshim_camera.so \
    /system/lib64/libcam.utils.sensorlistener.so|libshim_camera.so \
    /system/lib/libmtk_mmutils.so|libshim_ui.so \
    /system/lib64/libmtk_mmutils.so|libshim_ui.so \
    /system/lib/libMtkOmxAIVPlayer.so|libshim_stagefright.so \
    /system/lib/libaspclient.so|libshim_parcel.so \
    /system/lib64/libaspclient.so|libshim_parcel.so \
    /system/lib/libdrmmtkutil.so|libcrypaz.so \
    /system/lib64/libdrmmtkutil.so|libcrypaz.so

# Common-Specific Headers
TARGET_SPECIFIC_HEADER_PATH := $(DEVICE_COMMON)/include

# Partitions
BOARD_FLASH_BLOCK_SIZE := 131072

# System Stability
TARGET_USES_MKE2FS := true

# LPM
BOARD_CHARGING_MODE_BOOTING_LPM := /sys/class/BOOT/BOOT/boot/boot_mode

# Offline charging
BOARD_CHARGER_DISABLE_INIT_BLANK := true
BACKLIGHT_PATH := /sys/devices/platform/leds-mt65xx/leds/lcd-backlight/brightness

# Block Based OTA
BLOCK_BASED_OTA := false

# System Properties
TARGET_SYSTEM_PROP += $(DEVICE_COMMON)/system.prop
