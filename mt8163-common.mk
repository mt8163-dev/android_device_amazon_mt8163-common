COMMON_PATH := device/amazon/mt8163-common

# Include all the languages
$(call inherit-product, $(SRC_TARGET_DIR)/product/languages_full.mk)

# Call the proprietary vendor makefile
$(call inherit-product-if-exists, vendor/amazon/mt8163-common/mt8163-common-vendor.mk)

# Device uses high-density artwork where available
PRODUCT_AAPT_CONFIG := normal mdpi
PRODUCT_AAPT_PREF_CONFIG := mdpi

# Product Characteristics
PRODUCT_CHARACTERISTICS := tablet

# Overlay
DEVICE_PACKAGE_OVERLAYS += \
    $(COMMON_PATH)/overlay \
    $(COMMON_PATH)/overlay-lineage

# Power HAL
PRODUCT_PACKAGES += \
    power.mt8163

# Perf
PRODUCT_PACKAGES += \
    libperfservice \
    libperfservicenative

PRODUCT_COPY_FILES += \
    $(COMMON_PATH)/configs/perf/perfservscntbl.txt:system/etc/perfservscntbl.txt

# Lights HAL
PRODUCT_PACKAGES += \
    lights.mt8163 \
    android.hardware.light@2.0-impl-mediatek \
    android.hardware.light@2.0-service-mediatek

# Camera
PRODUCT_PACKAGES += \
    Snap \
    libcam.client \
    libcam.utils.sensorlistener \
    libcamera_parameters_mtk \
    android.hardware.camera.provider@2.4-impl-legacy

# Audio
PRODUCT_PACKAGES += \
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
    android.hardware.audio.effect@2.0-impl \
    android.hardware.broadcastradio@1.0-impl \
    android.hardware.soundtrigger@2.0-impl \
    android.hardware.soundtrigger@2.0-service

# WFD
PRODUCT_PACKAGES += \
    audio.r_submix.mt8163

# Blisrc
PRODUCT_PACKAGES += \
    libblisrc \
    libblisrc32

# Media Codecs
PRODUCT_COPY_FILES += \
    $(COMMON_PATH)/configs/media/media_codecs.xml:system/etc/media_codecs.xml \
    $(COMMON_PATH)/configs/media/media_profiles.xml:system/etc/media_profiles.xml \
    $(COMMON_PATH)/configs/media/media_codecs_performance.xml:system/etc/media_codecs_performance.xml \
    $(COMMON_PATH)/configs/media/media_codecs_mediatek_audio.xml:system/etc/media_codecs_mediatek_audio.xml \
    $(COMMON_PATH)/configs/media/media_codecs_mediatek_video.xml:system/etc/media_codecs_mediatek_video.xml \
    $(COMMON_PATH)/configs/media/media_codecs_google_audio.xml:system/etc/media_codecs_google_audio.xml \
    $(COMMON_PATH)/configs/media/media_codecs_google_video_le.xml:system/etc/media_codecs_google_video_le.xml \
    $(COMMON_PATH)/configs/media/mtk_omx_core.cfg:system/vendor/etc/mtk_omx_core.cfg

# Media Policy
PRODUCT_COPY_FILES += \
    $(LOCAL_PATH)/seccomp-policy/mediacodec-seccomp.policy:system/vendor/etc/seccomp_policy/mediacodec.policy \
    $(LOCAL_PATH)/seccomp-policy/mediaextractor-seccomp.policy:system/vendor/etc/seccomp_policy/mediaextractor.policy

# Prebuilt Keylayouts
PRODUCT_COPY_FILES += \
    $(COMMON_PATH)/configs/keylayouts/lightning-device.kl:system/usr/keylayout/lightning-device.kl \
    $(COMMON_PATH)/configs/keylayouts/mtk-kpd.kl:system/usr/keylayout/mtk-kpd.kl \
    $(COMMON_PATH)/configs/keylayouts/Vendor_0171_Product_040b.kl:system/usr/keylayout/Vendor_0171_Product_040b.kl \
    $(COMMON_PATH)/configs/keylayouts/Vendor_0171_Product_040c.kl:system/usr/keylayout/Vendor_0171_Product_040c.kl \
    $(COMMON_PATH)/configs/keylayouts/Vendor_0171_Product_0413.kl:system/usr/keylayout/Vendor_0171_Product_0413.kl \
    $(COMMON_PATH)/configs/keylayouts/Vendor_045e_Product_0291.kl:system/usr/keylayout/Vendor_045e_Product_0291.kl \
    $(COMMON_PATH)/configs/keylayouts/Vendor_1949_Product_0402.kl:system/usr/keylayout/Vendor_1949_Product_0402.kl \
    $(COMMON_PATH)/configs/keylayouts/Vendor_1949_Product_0404.kl:system/usr/keylayout/Vendor_1949_Product_0404.kl \
    $(COMMON_PATH)/configs/keylayouts/Vendor_1949_Product_0406.kl:system/usr/keylayout/Vendor_1949_Product_0406.kl \
    $(COMMON_PATH)/configs/keylayouts/Vendor_1949_Product_0407.kl:system/usr/keylayout/Vendor_1949_Product_0407.kl \
    $(COMMON_PATH)/configs/keylayouts/Vendor_1949_Product_0415.kl:system/usr/keylayout/Vendor_1949_Product_0415.kl \
    $(COMMON_PATH)/configs/keylayouts/Vendor_20a0_Product_0004.kl:system/usr/keylayout/Vendor_20a0_Product_0004.kl

# Input
PRODUCT_COPY_FILES += \
    $(COMMON_PATH)/configs/idc/amazon_touch.idc:system/usr/keylayout/amazon_touch.idc

# Wifi
PRODUCT_PACKAGES += \
    libwpa_client \
    hostapd \
    wpa_supplicant \
    wpa_supplicant.conf \
    lib_driver_cmd_mt66xx \
    android.hardware.wifi@1.0-service

# Gatekeeper
PRODUCT_PACKAGES += \
    gatekeeper.mt8163

# Configstore
PRODUCT_PACKAGES += \
    android.hardware.configstore@1.0-service

# Patched Audio Configuration Files
PRODUCT_COPY_FILES += \
    $(COMMON_PATH)/configs/audio/audio_device.xml:system/etc/audio_device.xml \
    $(COMMON_PATH)/configs/audio/audio_policy.conf:system/vendor/etc/audio_policy.conf

# Network
PRODUCT_PACKAGES += \
    netd

# Graphics
PRODUCT_PACKAGES += \
    libion \
    android.hardware.graphics.allocator@2.0-impl \
    android.hardware.graphics.allocator@2.0-service \
    android.hardware.graphics.composer@2.1-impl \
    android.hardware.graphics.mapper@2.0-impl \
    android.hardware.renderscript@1.0-impl

# Health
PRODUCT_PACKAGES += \
    android.hardware.health@1.0-impl \
    android.hardware.health@1.0-service

# Memtrack
PRODUCT_PACKAGES += \
    android.hardware.memtrack@1.0-impl \
    android.hardware.memtrack@1.0-service

# Power
PRODUCT_PACKAGES += \
    android.hardware.power@1.0-impl \
    android.hardware.power@1.0-service

# Sensors
PRODUCT_PACKAGES += \
    android.hardware.sensors@1.0-impl-mediatek \
    android.hardware.sensors@1.0-service-mediatek

# Sensors MultiHAL
PRODUCT_PACKAGES += \
    sensors.mt8163

# MultiHAL config
PRODUCT_COPY_FILES += \
    $(COMMON_PATH)/configs/sensors/_hals.conf:system/vendor/etc/sensors/_hals.conf

# Charger
PRODUCT_PACKAGES += \
    charger_res_images

# Graphics (MTK)
PRODUCT_PACKAGES += \
    libgui_ext \
    libui_ext \
    libgralloc_extra

# Shim Libraries
PRODUCT_PACKAGES += \
    libshim_ui \
    libshim_parcel \
    libshim_camera \
    libshim_drm \
    libshim_audio \
    libshim_atomic \
    libshim_stagefright

# IPv6 tethering
PRODUCT_PACKAGES += \
    ebtables \
    ethertypes

# Headphones
PRODUCT_PACKAGES += \
    audiofix \
    kvolcb

# HIDL
PRODUCT_PACKAGES += \
    android.hidl.base@1.0 \
    android.hidl.manager@1.0

# OMX
PRODUCT_PACKAGES += \
    android.hardware.media.omx@1.0-impl \
    android.hardware.media.omx@1.0-service

# USB
PRODUCT_PACKAGES += \
    android.hardware.usb@1.0-service

# Bluetooth
PRODUCT_PACKAGES += \
    android.hardware.bluetooth@1.0-impl-mediatek \
    android.hardware.bluetooth@1.0-service-mediatek \
    libbt-vendor

# Ramdisk
PRODUCT_COPY_FILES += \
    $(COMMON_PATH)/rootdir/fstab.mt8163:root/fstab.mt8163 \
    $(COMMON_PATH)/rootdir/init.mt8163.rc:root/init.mt8163.rc \
    $(COMMON_PATH)/rootdir/init.mt8163.usb.rc:root/init.mt8163.usb.rc \
    $(COMMON_PATH)/rootdir/init.recovery.mt8163.rc:root/init.recovery.mt8163.rc \
    $(COMMON_PATH)/rootdir/init.project.rc:root/init.project.rc \
    $(COMMON_PATH)/rootdir/init.wifi.rc:root/init.wifi.rc \
    $(COMMON_PATH)/rootdir/ueventd.mt8163.rc:root/ueventd.mt8163.rc \
    $(COMMON_PATH)/rootdir/bin/reboot-amonet:system/xbin/reboot-amonet

# Permissions
PRODUCT_COPY_FILES += \
    frameworks/native/data/etc/android.hardware.bluetooth_le.xml:system/etc/permissions/android.hardware.bluetooth_le.xml \
    frameworks/native/data/etc/android.hardware.bluetooth.xml:system/etc/permissions/android.hardware.bluetooth.xml \
    frameworks/native/data/etc/android.hardware.camera.front.xml:system/etc/permissions/android.hardware.camera.front.xml \
    frameworks/native/data/etc/android.hardware.camera.xml:system/etc/permissions/android.hardware.camera.xml \
    frameworks/native/data/etc/android.hardware.sensor.accelerometer.xml:system/etc/permissions/android.hardware.sensor.accelerometer.xml \
    frameworks/native/data/etc/android.hardware.sensor.light.xml:system/etc/permissions/android.hardware.sensor.light.xml \
    frameworks/native/data/etc/android.hardware.touchscreen.multitouch.jazzhand.xml:system/etc/permissions/android.hardware.touchscreen.multitouch.jazzhand.xml \
    frameworks/native/data/etc/android.hardware.usb.accessory.xml:system/etc/permissions/android.hardware.usb.accessory.xml \
    frameworks/native/data/etc/android.hardware.usb.host.xml:system/etc/permissions/android.hardware.usb.host.xml \
    frameworks/native/data/etc/android.hardware.wifi.direct.xml:system/etc/permissions/android.hardware.wifi.direct.xml \
    frameworks/native/data/etc/android.hardware.wifi.xml:system/etc/permissions/android.hardware.wifi.xml \
    frameworks/native/data/etc/tablet_core_hardware.xml:system/etc/permissions/tablet_core_hardware.xml

# Default OMX service to non-Treble
PRODUCT_PROPERTY_OVERRIDES += \
    persist.media.treble_omx=false

# Disable cameraserver
PRODUCT_PROPERTY_OVERRIDES += \
    media.stagefright.legacyencoder=true \
    media.stagefright.less-secure=true \

# Override Default Properties
PRODUCT_DEFAULT_PROPERTY_OVERRIDES += \
    ro.secure=0 \
    ro.adb.secure=0 \
    ro.allow.mock.location=0 \
    ro.mount.fs=EXT4 \
    camera.disable_zsl_mode=1 \
    ro.debuggable=1 \
    persist.service.acm.enable=0 \
    service.adb.root=1

# DRM
PRODUCT_PACKAGES += \
    libdrm \
    libfwdlockengine \
    android.hardware.drm@1.0-impl \
    android.hardware.drm@1.0-service \
    android.hardware.drm@1.1-service.clearkey

# Gatekeeper
PRODUCT_PACKAGES += \
    android.hardware.gatekeeper@1.0-impl \
    android.hardware.gatekeeper@1.0-service

# Keymaster
PRODUCT_PACKAGES += \
    android.hardware.keymaster@3.0-impl \
    android.hardware.keymaster@3.0-service

# No RIL
PRODUCT_PROPERTY_OVERRIDES += \
    keyguard.no_require_sim=1 \
    ro.radio.use-ppp=no \
    ro.config.nocheckin=yes \
    ro.radio.noril=1 \
    ro.carrier=wifi-only \
    persist.radio.noril=1

# Limit Background Processes
PRODUCT_PROPERTY_OVERRIDES += \
    ro.sys.fw.bg_apps_limits=5

# Vendor security patch level
PRODUCT_PROPERTY_OVERRIDES += \
    ro.lineage.build.vendor_security_patch=2019-07-01

# Configure dalvik heap
$(call inherit-product, frameworks/native/build/phone-xhdpi-2048-dalvik-heap.mk)

# Call hwui memory config
$(call inherit-product-if-exists, frameworks/native/build/phone-xxhdpi-2048-hwui-memory.mk)
