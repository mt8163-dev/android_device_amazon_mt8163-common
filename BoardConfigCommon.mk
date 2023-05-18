#
# Copyright (C) 2023 The LineageOS Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

COMMON_PATH := device/amazon/mt8163-common

# Broken rules
BUILD_BROKEN_DUP_RULES := true

# Platform
BOARD_VENDOR := amazon
TARGET_BOARD_PLATFORM := mt8163
TARGET_NO_BOOTLOADER := true

# Architecture
TARGET_ARCH := arm64
TARGET_ARCH_VARIANT := armv8-a
TARGET_CPU_ABI := arm64-v8a
TARGET_CPU_ABI2 :=
TARGET_CPU_VARIANT := generic
TARGET_CPU_VARIANT_RUNTIME := cortex-a53

TARGET_2ND_ARCH := arm
TARGET_2ND_ARCH_VARIANT := armv8-a
TARGET_2ND_CPU_ABI := armeabi-v7a
TARGET_2ND_CPU_ABI2 := armeabi
TARGET_2ND_CPU_VARIANT := generic
TARGET_2ND_CPU_VARIANT_RUNTIME := cortex-a53

# Malloc
MALLOC_SVELTE := true

# Fonts
EXCLUDE_SERIF_FONTS := true
SMALLER_FONT_FOOTPRINT := true
USE_REDUCED_CJK_FONT_WEIGHTS := true

# Headers
TARGET_SPECIFIC_HEADER_PATH := $(COMMON_PATH)/include

# Boot
BOARD_KERNEL_BASE := 0x40078000
BOARD_KERNEL_OFFSET := 0x00008000
BOARD_KERNEL_TAGS_OFFSET := 0x07f88000
BOARD_RAMDISK_OFFSET := 0x03f88000
BOARD_SECOND_OFFSET := 0x00e88000
BOARD_KERNEL_PAGESIZE := 2048
BOARD_BOOTIMG_HEADER_VERSION := 0
BOARD_HASH_TYPE := sha1

BOARD_MKBOOTIMG_ARGS := --ramdisk_offset $(BOARD_RAMDISK_OFFSET)
BOARD_MKBOOTIMG_ARGS += --second_offset $(BOARD_SECOND_OFFSET)
BOARD_MKBOOTIMG_ARGS += --tags_offset $(BOARD_KERNEL_TAGS_OFFSET)
BOARD_MKBOOTIMG_ARGS += --header_version $(BOARD_BOOTIMG_HEADER_VERSION)
BOARD_MKBOOTIMG_ARGS += --board ""

BOARD_KERNEL_CMDLINE := bootopt=64S3,32N2,64N2
BOARD_KERNEL_CMDLINE += loop.max_part=7
BOARD_KERNEL_CMDLINE += androidboot.selinux=permissive
BOARD_KERNEL_CMDLINE += androidboot.init_fatal_reboot_target=recovery

# Kernel
TARGET_KERNEL_ARCH := arm64
TARGET_KERNEL_HEADER_ARCH := arm64
TARGET_KERNEL_SOURCE := kernel/amazon/mt8163
BOARD_KERNEL_IMAGE_NAME := Image.gz-dtb

TARGET_KERNEL_CLANG_COMPILE := false
TARGET_KERNEL_CROSS_COMPILE_PREFIX := aarch64-linux-android-
KERNEL_TOOLCHAIN := $(shell pwd)/prebuilts/gcc/$(HOST_OS)-x86/aarch64/aarch64-linux-android-4.9/bin
TARGET_LINUX_KERNEL_VERSION := 3.18

# Properties
TARGET_SYSTEM_PROP += $(COMMON_PATH)/configs/props/system.prop

# Vintf
DEVICE_MANIFEST_FILE := $(COMMON_PATH)/configs/vintf/manifest.xml
DEVICE_MATRIX_FILE := $(COMMON_PATH)/configs/vintf/compatibility_matrix.xml

# Apexes
TARGET_FLATTEN_APEX := true

# Low memory killer
TARGET_LMKD_STATS_LOG := true

# Bluetooth
BOARD_HAVE_BLUETOOTH := true
BOARD_HAVE_BLUETOOTH_MTK := true
BOARD_BLUETOOTH_DOES_NOT_USE_RFKILL := true
BOARD_BLUETOOTH_BDROID_BUILDCFG_INCLUDE_DIR := $(COMMON_PATH)/bluetooth

# Wi-Fi
BOARD_WLAN_DEVICE                := MediaTek
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

WIFI_HIDL_FEATURE_AP_MAC_RANDOMIZATION := false
WIFI_HIDL_FEATURE_DISABLE_AP_MAC_RANDOMIZATION := true

# Camera
TARGET_HAS_LEGACY_CAMERA_HAL1 := true

# Audio
USE_XML_AUDIO_POLICY_CONF := 1

# Shim libraries
TARGET_LD_SHIM_LIBS := \
    /system/lib/hw/audio.primary.mt8163.so|libshim_alsa.so \
    /system/lib64/hw/audio.primary.mt8163.so|libshim_alsa.so \
    /system/bin/amzn_dha_hmac|libshim_crypto.so \
    /system/bin/amzn_dha_tool|libshim_crypto.so \
    /system/lib/libdrmmtkutil.so|libshim_icuuc.so \
    /system/lib64/libdrmmtkutil.so|libshim_icuuc.so \
    /system/lib/hw/hwcomposer.mt8163.so|libshim_ui.so \
    /system/lib64/hw/hwcomposer.mt8163.so|libshim_ui.so \
    /system/lib/libcam_utils.so|libshim_ui.so \
    /system/lib64/libcam_utils.so|libshim_ui.so \
    /system/lib/libcam1client.so|libshim_ui.so \
    /system/lib64/libcam1client.so|libshim_ui.so \
    /system/lib/libcam.utils.sensorlistener.so|libshim_gui.so \
    /system/lib64/libcam.utils.sensorlistener.so|libshim_gui.so \
    /system/lib/libmtk_mmutils.so|libshim_ui.so \
    /system/lib64/libmtk_mmutils.so|libshim_ui.so \
    /system/lib/libMtkOmxVdecEx.so|libshim_ui.so \
    /system/lib/libMtkOmxVenc.so|libshim_ui.so \
    /system/lib/libc.so|libshim_pthread.so \
    /system/lib64/libc.so|libshim_pthread.so \
    /system/lib/liblog.so|libshim_log.so \
    /system/lib64/liblog.so|libshim_log.so \
    /system/lib/libcutils.so|libshim_atomic.so \
    /system/lib64/libcutils.so|libshim_atomic.so \
    /system/lib/libbinder.so|libshim_binder.so \
    /system/lib64/libbinder.so|libshim_binder.so \
    /system/lib/libtinyalsa.so|libshim_alsa.so \
    /system/lib64/libtinyalsa.so|libshim_alsa.so \
    /system/bin/app_process32|libshim_zygote.so \
    /system/bin/app_process64|libshim_zygote.so \
    /vendor/lib/libwvm.so|libshim_omx.so \
    /system/lib/libbase.so|libshim_base.so \
    /system/lib64/libbase.so|libshim_base.so

# Legacy blobs
TARGET_PROCESS_SDK_VERSION_OVERRIDE := \
    /system/bin/mediaserver=22

# Display
TARGET_SCREEN_DENSITY := 213

# HWUI
HWUI_COMPILE_FOR_PERF := true

# Don't compile SystemUITests
EXCLUDE_SYSTEMUI_TESTS := true

# Dexpreopt
ifeq ($(HOST_OS),linux)
  ifneq ($(TARGET_BUILD_VARIANT),eng)
    ifeq ($(WITH_DEXPREOPT),)
      WITH_DEXPREOPT := true
      WITH_DEXPREOPT_BOOT_IMG_AND_SYSTEM_SERVER_ONLY := true
    endif
  endif
endif

# Filesystems
TARGET_USERIMAGES_USE_EXT4 := true
TARGET_USERIMAGES_SPARSE_EXT_DISABLED := false
BOARD_SYSTEMIMAGE_FILE_SYSTEM_TYPE := ext4
BOARD_CACHEIMAGE_FILE_SYSTEM_TYPE := ext4
BOARD_USES_METADATA_PARTITION := true

# Recovery
TARGET_RECOVERY_PIXEL_FORMAT := "RGBA_8888"
TARGET_RECOVERY_FSTAB := $(COMMON_PATH)/recovery/root/fstab.mt8163
LZMA_RAMDISK_TARGETS := recovery

# SPL
VENDOR_SECURITY_PATCH := 2019-07-01

# SELinux
SELINUX_IGNORE_NEVERALLOWS := true
