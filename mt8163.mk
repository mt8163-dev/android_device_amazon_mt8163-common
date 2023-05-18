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

# Inherit go optimizations for MT8163
$(call inherit-product, device/amazon/mt8163-common/go_opt.mk)

# Audio
PRODUCT_PACKAGES += \
    audio.a2dp.default \
    audio.r_submix.default \
    audio.usb.default \
    audio_policy.stub

PRODUCT_PACKAGES += \
    headsetd \
    libalsautils \
    libaudio-resampler \
    libtinyalsa \
    libtinycompress \
    libtinyxml \
    libaudioroute

PRODUCT_PACKAGES += \
    android.hardware.audio@2.0-impl \
    android.hardware.audio@2.0-service \
    android.hardware.audio.effect@2.0-impl

PRODUCT_COPY_FILES += \
    $(LOCAL_PATH)/configs/audio/audio_device.xml:$(TARGET_COPY_OUT_SYSTEM)/etc/audio_device.xml \
    $(LOCAL_PATH)/configs/audio/audio_policy_configuration.xml:$(TARGET_COPY_OUT_VENDOR)/etc/audio_policy_configuration.xml \
    $(LOCAL_PATH)/configs/audio/audio_policy_volumes.xml:$(TARGET_COPY_OUT_VENDOR)/etc/audio_policy_volumes.xml

PRODUCT_COPY_FILES += \
    frameworks/av/services/audiopolicy/config/r_submix_audio_policy_configuration.xml:$(TARGET_COPY_OUT_VENDOR)/etc/r_submix_audio_policy_configuration.xml \
    frameworks/av/services/audiopolicy/config/usb_audio_policy_configuration.xml:$(TARGET_COPY_OUT_VENDOR)/etc/usb_audio_policy_configuration.xml \
    frameworks/av/services/audiopolicy/config/a2dp_audio_policy_configuration.xml:$(TARGET_COPY_OUT_VENDOR)/etc/a2dp_audio_policy_configuration.xml \
    frameworks/av/services/audiopolicy/config/a2dp_in_audio_policy_configuration.xml:$(TARGET_COPY_OUT_VENDOR)/etc/a2dp_in_audio_policy_configuration.xml \
    frameworks/av/services/audiopolicy/config/default_volume_tables.xml:$(TARGET_COPY_OUT_VENDOR)/etc/default_volume_tables.xml \
    frameworks/av/services/audiopolicy/enginedefault/config/example/phone/audio_policy_engine_configuration.xml:$(TARGET_COPY_OUT_VENDOR)/etc/audio_policy_engine_configuration.xml \
    frameworks/av/services/audiopolicy/enginedefault/config/example/phone/audio_policy_engine_default_stream_volumes.xml:$(TARGET_COPY_OUT_VENDOR)/etc/audio_policy_engine_default_stream_volumes.xml \
    frameworks/av/services/audiopolicy/enginedefault/config/example/phone/audio_policy_engine_product_strategies.xml:$(TARGET_COPY_OUT_VENDOR)/etc/audio_policy_engine_product_strategies.xml \
    frameworks/av/services/audiopolicy/enginedefault/config/example/phone/audio_policy_engine_stream_volumes.xml:$(TARGET_COPY_OUT_VENDOR)/etc/audio_policy_engine_stream_volumes.xml

# APEX
PRODUCT_COPY_FILES += \
    $(LOCAL_PATH)/configs/ld/ld.config.txt:$(TARGET_COPY_OUT_SYSTEM)/etc/swcodec/ld.config.txt

# Bluetooth
PRODUCT_PACKAGES += \
    mac_idme.sh

PRODUCT_PACKAGES += \
    android.hardware.bluetooth@1.0-impl \
    android.hardware.bluetooth@1.0-service \
    libbluetooth_mtk \
    libbt-vendor

# Bootanimation
TARGET_BOOTANIMATION_HALF_RES := true

# Camera
PRODUCT_PACKAGES += \
    libcam.client

PRODUCT_PACKAGES += \
    android.hardware.camera.provider@2.4-impl-legacy

PRODUCT_PACKAGES += \
    Snap

# Characteristics
PRODUCT_CHARACTERISTICS := tablet

# DRM
PRODUCT_PACKAGES += \
    move_widevine_data.sh

PRODUCT_PACKAGES += \
    android.hardware.drm@1.0-service \
    android.hardware.drm@1.0-impl \
    android.hardware.drm@1.2-service.clearkey

# Enable DM file pre-opting to reduce first boot time
PRODUCT_DEX_PREOPT_GENERATE_DM_FILES := true

# Gatekeeper
PRODUCT_PACKAGES += \
    android.hardware.gatekeeper@1.0-service.software

# Graphics
PRODUCT_PACKAGES += \
    libion \
    libui_ext \
    libgui_ext \
    libgralloc_extra

PRODUCT_PACKAGES += \
    android.hardware.graphics.allocator@2.0-impl \
    android.hardware.graphics.allocator@2.0-service \
    android.hardware.graphics.composer@2.1-impl \
    android.hardware.graphics.composer@2.1-service \
    android.hardware.graphics.mapper@2.0-impl \
    android.hardware.renderscript@1.0-impl

# Health
PRODUCT_PACKAGES += \
    android.hardware.health@2.0-impl \
    android.hardware.health@2.0-service

# Keymaster
PRODUCT_PACKAGES += \
    libkeystore-engine-wifi-hidl \
    libkeystore-wifi-hidl

PRODUCT_PACKAGES += \
    android.hardware.keymaster@3.0-service \
    android.hardware.keymaster@3.0-impl

# Light
PRODUCT_PACKAGES += \
    android.hardware.light@2.0-service.mt8163

# LiveDisplay
ifneq ($(wildcard vendor/lineage/.),)
    PRODUCT_PACKAGES += vendor.lineage.livedisplay@2.0-service-mediatek
endif

# Media
PRODUCT_COPY_FILES += \
    $(LOCAL_PATH)/configs/media/mtk_omx_core.cfg:$(TARGET_COPY_OUT_VENDOR)/etc/mtk_omx_core.cfg \
    $(LOCAL_PATH)/configs/media/media_profiles_V1_0.xml:$(TARGET_COPY_OUT_SYSTEM)/etc/media_profiles_V1_0.xml \
    $(LOCAL_PATH)/configs/media/media_codecs.xml:$(TARGET_COPY_OUT_SYSTEM)/etc/media_codecs.xml \
    $(LOCAL_PATH)/configs/media/media_codecs_mediatek_video.xml:$(TARGET_COPY_OUT_SYSTEM)/etc/media_codecs_mediatek_video.xml \
    $(LOCAL_PATH)/configs/media/media_codecs_mediatek_audio.xml:$(TARGET_COPY_OUT_SYSTEM)/etc/media_codecs_mediatek_audio.xml \
    $(LOCAL_PATH)/configs/media/media_codecs_performance.xml:$(TARGET_COPY_OUT_SYSTEM)/etc/media_codecs_performance.xml

PRODUCT_COPY_FILES += \
    frameworks/av/media/libstagefright/data/media_codecs_google_audio.xml:$(TARGET_COPY_OUT_SYSTEM)/etc/media_codecs_google_audio.xml \
    frameworks/av/media/libstagefright/data/media_codecs_google_video.xml:$(TARGET_COPY_OUT_SYSTEM)/etc/media_codecs_google_video.xml \
    frameworks/av/media/libstagefright/data/media_codecs_google_video_le.xml:$(TARGET_COPY_OUT_SYSTEM)/etc/media_codecs_google_video_le.xml

# Memtrack
PRODUCT_PACKAGES += \
    android.hardware.memtrack@1.0-impl \
    android.hardware.memtrack@1.0-service

# Overlays
DEVICE_PACKAGE_OVERLAYS += \
    $(LOCAL_PATH)/overlay \
    $(LOCAL_PATH)/overlay-lineage

# Permissions
PRODUCT_COPY_FILES += \
    frameworks/native/data/etc/android.hardware.bluetooth.xml:$(TARGET_COPY_OUT_VENDOR)/etc/permissions/android.hardware.bluetooth.xml \
    frameworks/native/data/etc/android.hardware.bluetooth_le.xml:$(TARGET_COPY_OUT_VENDOR)/etc/permissions/android.hardware.bluetooth_le.xml \
    frameworks/native/data/etc/android.hardware.camera.xml:$(TARGET_COPY_OUT_VENDOR)/etc/permissions/android.hardware.camera.xml \
    frameworks/native/data/etc/android.hardware.ethernet.xml:$(TARGET_COPY_OUT_VENDOR)/etc/permissions/android.hardware.ethernet.xml \
    frameworks/native/data/etc/android.hardware.faketouch.xml:$(TARGET_COPY_OUT_VENDOR)/etc/permissions/android.hardware.faketouch.xml \
    frameworks/native/data/etc/android.hardware.sensor.accelerometer.xml:$(TARGET_COPY_OUT_VENDOR)/etc/permissions/android.hardware.sensor.accelerometer.xml \
    frameworks/native/data/etc/android.hardware.sensor.light.xml:$(TARGET_COPY_OUT_VENDOR)/etc/permissions/android.hardware.sensor.light.xml \
    frameworks/native/data/etc/android.hardware.touchscreen.multitouch.distinct.xml:$(TARGET_COPY_OUT_VENDOR)/etc/permissions/android.hardware.touchscreen.multitouch.distinct.xml \
    frameworks/native/data/etc/android.hardware.touchscreen.multitouch.jazzhand.xml:$(TARGET_COPY_OUT_VENDOR)/etc/permissions/android.hardware.touchscreen.multitouch.jazzhand.xml \
    frameworks/native/data/etc/android.hardware.touchscreen.multitouch.xml:$(TARGET_COPY_OUT_VENDOR)/etc/permissions/android.hardware.touchscreen.multitouch.xml \
    frameworks/native/data/etc/android.hardware.touchscreen.xml:$(TARGET_COPY_OUT_VENDOR)/etc/permissions/android.hardware.touchscreen.xml  \
    frameworks/native/data/etc/android.hardware.opengles.aep.xml:$(TARGET_COPY_OUT_VENDOR)/etc/permissions/android.hardware.opengles.aep.xml \
    frameworks/native/data/etc/android.hardware.usb.accessory.xml:$(TARGET_COPY_OUT_VENDOR)/etc/permissions/android.hardware.usb.accessory.xml \
    frameworks/native/data/etc/android.hardware.usb.host.xml:$(TARGET_COPY_OUT_VENDOR)/etc/permissions/android.hardware.usb.host.xml \
    frameworks/native/data/etc/android.hardware.wifi.direct.xml:$(TARGET_COPY_OUT_VENDOR)/etc/permissions/android.hardware.wifi.direct.xml \
    frameworks/native/data/etc/android.hardware.wifi.xml:$(TARGET_COPY_OUT_VENDOR)/etc/permissions/android.hardware.wifi.xml \
    frameworks/native/data/etc/android.software.midi.xml:$(TARGET_COPY_OUT_VENDOR)/etc/permissions/android.software.midi.xml \
    frameworks/native/data/etc/tablet_core_hardware.xml:$(TARGET_COPY_OUT_VENDOR)/etc/permissions/tablet_core_hardware.xml

# Power
PRODUCT_PACKAGES += \
    android.hardware.power@1.3-service.mt8163

# Ramdisk
PRODUCT_PACKAGES += \
    fstab.mt8163 \
    fstab.mt8163_ramdisk \
    init.mt8163.rc \
    init.mt8163.usb.rc \
    init.project.rc \
    ueventd.mt8163.rc \

PRODUCT_PACKAGES += \
    fix-symlinks.sh

# Recovery
PRODUCT_COPY_FILES += \
    $(call find-copy-subdir-files,*,$(LOCAL_PATH)/recovery/root,recovery/root)

# Remove Useless Packages
PRODUCT_PACKAGES += \
    RemovePackages

# Screen
TARGET_SCREEN_WIDTH := 800
TARGET_SCREEN_HEIGHT := 1280

# Seccomp
PRODUCT_COPY_FILES += \
    $(LOCAL_PATH)/configs/seccomp/mediacodec.policy:$(TARGET_COPY_OUT_VENDOR)/etc/seccomp_policy/mediacodec.policy \
    $(LOCAL_PATH)/configs/seccomp/mediaswcodec.policy:$(TARGET_COPY_OUT_VENDOR)/etc/seccomp_policy/mediaswcodec.policy

# Sensors
PRODUCT_PACKAGES += \
    android.hardware.sensors@1.0-impl \
    sensors.mt8163

PRODUCT_COPY_FILES += \
    $(LOCAL_PATH)/configs/sensors/_hals.conf:system/vendor/etc/sensors/_hals.conf

# Shims
PRODUCT_PACKAGES += \
    libshim_alsa \
    libshim_atomic \
    libshim_base \
    libshim_binder \
    libshim_crypto \
    libshim_gui \
    libshim_icuuc \
    libshim_log \
    libshim_omx \
    libshim_pthread \
    libshim_ui \
    libshim_zygote

# Soong
PRODUCT_SOONG_NAMESPACES += \
    $(LOCAL_PATH) \
    hardware/mediatek

# Trust
ifneq ($(wildcard vendor/lineage/.),)
PRODUCT_PACKAGES += \
    vendor.lineage.trust@1.0-service
endif

# USB
PRODUCT_PACKAGES += \
    android.hardware.usb@1.0-service.basic

# Wi-Fi
PRODUCT_PACKAGES += \
    android.hardware.wifi@1.0 \
    android.hardware.wifi@1.1 \
    android.hardware.wifi@1.2 \
    android.hardware.wifi.supplicant@1.0 \
    android.hardware.wifi.supplicant@1.1 \
    android.hardware.wifi.supplicant@1.2

PRODUCT_PACKAGES += \
    libnl \
    wpa_supplicant \
    libwpa_client \
    lib_driver_cmd_mt66xx \
    libwifi-hal-mt66xx \
    libwifi-system-iface

PRODUCT_COPY_FILES += \
    $(LOCAL_PATH)/configs/wifi/p2p_supplicant_overlay.conf:$(TARGET_COPY_OUT_SYSTEM)/etc/wifi/p2p_supplicant_overlay.conf \
    $(LOCAL_PATH)/configs/wifi/wpa_supplicant.conf:$(TARGET_COPY_OUT_SYSTEM)/etc/wifi/wpa_supplicant.conf \
    $(LOCAL_PATH)/configs/wifi/wpa_supplicant_overlay.conf:$(TARGET_COPY_OUT_SYSTEM)/etc/wifi/wpa_supplicant_overlay.conf

# Proprietary
$(call inherit-product, vendor/amazon/mt8163-common/mt8163-common-vendor.mk)
