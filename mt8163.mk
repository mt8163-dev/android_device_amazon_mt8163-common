#
# Copyright (C) 2022 The LineageOS Project
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

# Inherit go optimizations for mt8163
$(call inherit-product, device/amazon/mt8163-common/go_opt.mk)

# Soong
PRODUCT_SOONG_NAMESPACES += \
    $(LOCAL_PATH) \
    hardware/mediatek

# Enable DM file pre-opting to reduce first boot time
PRODUCT_DEX_PREOPT_GENERATE_DM_FILES := true

# Bootanimation
TARGET_BOOTANIMATION_HALF_RES := true

# Overlays
DEVICE_PACKAGE_OVERLAYS += \
    $(LOCAL_PATH)/overlay \
    $(LOCAL_PATH)/overlay-lineage

PRODUCT_ENFORCE_RRO_TARGETS := \
    framework-res

# Recovery
PRODUCT_COPY_FILES += \
    $(LOCAL_PATH)/recovery/root/init.recovery.mt8163.rc:recovery/root/init.recovery.mt8163.rc \
    $(LOCAL_PATH)/recovery/root/amonet-fixup.sh:recovery/root/amonet-fixup.sh \
    $(LOCAL_PATH)/recovery/root/fix-symlinks.sh:recovery/root/fix-symlinks.sh \
    $(LOCAL_PATH)/recovery/root/fix-bootpatch.sh:recovery/root/fix-bootpatch.sh

# Ramdisk
PRODUCT_PACKAGES += \
    fstab.mt8163 \
    fstab.mt8163_ramdisk \
    init.mt8163.rc \
    init.mt8163.usb.rc \
    init.project.rc \
    ueventd.mt8163.rc \
    fix-symlinks.sh

# Permissions
PRODUCT_COPY_FILES += \
    frameworks/native/data/etc/android.hardware.bluetooth.xml:$(TARGET_COPY_OUT_VENDOR)/etc/permissions/android.hardware.bluetooth.xml \
    frameworks/native/data/etc/android.hardware.bluetooth_le.xml:$(TARGET_COPY_OUT_VENDOR)/etc/permissions/android.hardware.bluetooth_le.xml \
    frameworks/native/data/etc/android.hardware.camera.xml:$(TARGET_COPY_OUT_VENDOR)/etc/permissions/android.hardware.camera.xml \
    frameworks/native/data/etc/android.hardware.ethernet.xml:$(TARGET_COPY_OUT_VENDOR)/etc/permissions/android.hardware.ethernet.xml \
    frameworks/native/data/etc/android.hardware.faketouch.xml:$(TARGET_COPY_OUT_VENDOR)/etc/permissions/android.hardware.faketouch.xml \
    frameworks/native/data/etc/android.hardware.sensor.accelerometer.xml:$(TARGET_COPY_OUT_VENDOR)/etc/permissions/android.hardware.sensor.accelerometer.xml \
    frameworks/native/data/etc/android.hardware.sensor.light.xml:$(TARGET_COPY_OUT_VENDOR)/etc/permissions/android.hardware.sensor.light.xml \
    frameworks/native/data/etc/android.hardware.sensor.proximity.xml:$(TARGET_COPY_OUT_VENDOR)/etc/permissions/android.hardware.sensor.proximity.xml \
    frameworks/native/data/etc/android.hardware.sensor.proximity.xml:$(TARGET_COPY_OUT_VENDOR)/etc/permissions/android.hardware.sensor.proximity.xml \
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
    frameworks/native/data/etc/handheld_core_hardware.xml:$(TARGET_COPY_OUT_VENDOR)/etc/permissions/handheld_core_hardware.xml

# Remove useless packages
PRODUCT_PACKAGES += \
    RemovePackages

# Audio
PRODUCT_PACKAGES += \
    hp-daemon \
    audio.a2dp.default \
    audio.r_submix.default \
    audio.usb.default \
    audio_policy.stub \
    libalsautils \
    libaudio-resampler \
    libtinyalsa \
    libtinycompress \
    libtinyxml \
    libaudioroute \
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
    frameworks/av/services/audiopolicy/config/default_volume_tables.xml:$(TARGET_COPY_OUT_VENDOR)/etc/default_volume_tables.xml

PRODUCT_COPY_FILES += \
    frameworks/av/services/audiopolicy/enginedefault/config/example/phone/audio_policy_engine_configuration.xml:$(TARGET_COPY_OUT_VENDOR)/etc/audio_policy_engine_configuration.xml \
    frameworks/av/services/audiopolicy/enginedefault/config/example/phone/audio_policy_engine_default_stream_volumes.xml:$(TARGET_COPY_OUT_VENDOR)/etc/audio_policy_engine_default_stream_volumes.xml \
    frameworks/av/services/audiopolicy/enginedefault/config/example/phone/audio_policy_engine_product_strategies.xml:$(TARGET_COPY_OUT_VENDOR)/etc/audio_policy_engine_product_strategies.xml \
    frameworks/av/services/audiopolicy/enginedefault/config/example/phone/audio_policy_engine_stream_volumes.xml:$(TARGET_COPY_OUT_VENDOR)/etc/audio_policy_engine_stream_volumes.xml

# Media
PRODUCT_COPY_FILES += \
    $(LOCAL_PATH)/configs/media/mtk_omx_core.cfg:$(TARGET_COPY_OUT_VENDOR)/etc/mtk_omx_core.cfg \
    $(LOCAL_PATH)/configs/media/media_profiles_V1_0.xml:$(TARGET_COPY_OUT_SYSTEM)/etc/media_profiles_V1_0.xml \
    $(LOCAL_PATH)/configs/media/media_codecs.xml:$(TARGET_COPY_OUT_SYSTEM)/etc/media_codecs.xml \
    $(LOCAL_PATH)/configs/media/media_codecs_mediatek_video.xml:$(TARGET_COPY_OUT_SYSTEM)/etc/media_codecs_mediatek_video.xml \
    $(LOCAL_PATH)/configs/media/media_codecs_mediatek_audio.xml:$(TARGET_COPY_OUT_SYSTEM)/etc/media_codecs_mediatek_audio.xml \
    $(LOCAL_PATH)/configs/media/media_codecs_performance.xml:$(TARGET_COPY_OUT_SYSTEM)/etc/media_codecs_performance.xml \
    frameworks/av/media/libstagefright/data/media_codecs_google_audio.xml:$(TARGET_COPY_OUT_SYSTEM)/etc/media_codecs_google_audio.xml \
    frameworks/av/media/libstagefright/data/media_codecs_google_video.xml:$(TARGET_COPY_OUT_SYSTEM)/etc/media_codecs_google_video.xml \
    frameworks/av/media/libstagefright/data/media_codecs_google_video_le.xml:$(TARGET_COPY_OUT_SYSTEM)/etc/media_codecs_google_video_le.xml

# Seccomp
PRODUCT_COPY_FILES += \
    $(LOCAL_PATH)/configs/seccomp/mediacodec.policy:$(TARGET_COPY_OUT_VENDOR)/etc/seccomp_policy/mediacodec.policy

# Apex
PRODUCT_COPY_FILES += \
    $(LOCAL_PATH)/configs/ld/ld.config.txt:$(TARGET_COPY_OUT_SYSTEM)/etc/swcodec/ld.config.txt

# Wi-Fi
PRODUCT_PACKAGES += \
    wpa_supplicant \
    libwpa_client \
    lib_driver_cmd_mt66xx \
    libwifi-hal-mt66xx \
    android.hardware.wifi@1.0-service.legacy

PRODUCT_COPY_FILES += \
    $(LOCAL_PATH)/configs/wifi/p2p_supplicant_overlay.conf:$(TARGET_COPY_OUT_SYSTEM)/etc/wifi/p2p_supplicant_overlay.conf \
    $(LOCAL_PATH)/configs/wifi/wpa_supplicant.conf:$(TARGET_COPY_OUT_SYSTEM)/etc/wifi/wpa_supplicant.conf \
    $(LOCAL_PATH)/configs/wifi/wpa_supplicant_overlay.conf:$(TARGET_COPY_OUT_SYSTEM)/etc/wifi/wpa_supplicant_overlay.conf

# Power
PRODUCT_PACKAGES += \
    power.mt8163 \
    android.hardware.power@1.0-impl \
    android.hardware.power@1.0-service

# Light
PRODUCT_PACKAGES += \
    lights.mt8163 \
    android.hardware.light@2.0-impl \
    android.hardware.light@2.0-service

# Health
PRODUCT_PACKAGES += \
    android.hardware.health@2.0-impl \
    android.hardware.health@2.0-service

# Sensors
PRODUCT_PACKAGES += \
    sensors.mt8163 \
    android.hardware.sensors@1.0-impl \
    android.hardware.sensors@1.0-service

PRODUCT_COPY_FILES += \
    $(LOCAL_PATH)/configs/sensors/_hals.conf:system/vendor/etc/sensors/_hals.conf

# Bluetooth
PRODUCT_PACKAGES += \
    mac_idme \
    libbluetooth_mtk \
    libbt-vendor \
    android.hardware.bluetooth@1.0-impl \
    android.hardware.bluetooth@1.0-service

# DRM
PRODUCT_PACKAGES += \
    move_widevine_data.sh \
    android.hardware.drm@1.0-service \
    android.hardware.drm@1.0-impl \
    android.hardware.drm@1.2-service.clearkey

# LiveDisplay
ifneq ($(wildcard vendor/lineage/.),)
    PRODUCT_PACKAGES += vendor.lineage.livedisplay@2.0-service-mediatek
endif

# Camera
PRODUCT_PACKAGES += \
    libcam.client \
    android.hardware.camera.provider@2.4-impl-legacy

PRODUCT_PACKAGES += \
    Snap

# Trust HAL
PRODUCT_PACKAGES += \
    vendor.lineage.trust@1.0-service

# USB
PRODUCT_PACKAGES += \
    android.hardware.usb@1.0-service.basic

# Keymaster
PRODUCT_PACKAGES += \
    android.hardware.keymaster@3.0-service \
    android.hardware.keymaster@3.0-impl

PRODUCT_PACKAGES += \
    libkeystore-engine-wifi-hidl \
    libkeystore-wifi-hidl

# Gatekeeper
PRODUCT_PACKAGES += \
    gatekeeper.mt8163 \
    android.hardware.gatekeeper@1.0-impl \
    android.hardware.gatekeeper@1.0-service

# Graphics
PRODUCT_PACKAGES += \
    libion \
    libgralloc_extra \
    libui_ext \
    libgui_ext \
    android.hardware.memtrack@1.0-impl \
    android.hardware.memtrack@1.0-service \
    android.hardware.graphics.allocator@2.0-impl \
    android.hardware.graphics.allocator@2.0-service \
    android.hardware.graphics.composer@2.1-impl \
    android.hardware.graphics.mapper@2.0-impl \
    android.hardware.renderscript@1.0-impl

# Shim libraries
PRODUCT_PACKAGES += \
    libshim_log \
    libshim_crypto \
    libshim_icuuc \
    libshim_binder \
    libshim_ui \
    libshim_atomic \
    libshim_alsa \
    libshim_zygote \
    libshim_pthread \
    libshim_omx

# Proprietary
$(call inherit-product, vendor/amazon/mt8163-common/mt8163-common-vendor.mk)
