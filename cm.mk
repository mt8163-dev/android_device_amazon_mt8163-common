# Intherit from tablet
$(call inherit-product-if-exists, vendor/cm/config/common_full_tablet_wifionly.mk)

# Inherit from device
$(call inherit-product, device/amazon/douglas/full_douglas.mk)

# Product
TARGET_SCREEN_WIDTH := 1280
TARGET_SCREEN_HEIGHT := 800
PRODUCT_CHARACTERISTICS := tablet
PRODUCT_NAME := cm_douglas
PRODUCT_RELEASE_NAME := douglas

# Override the fingerprint for SafetyNet
PRODUCT_BUILD_PROP_OVERRIDES += \
    BUILD_FINGERPRINT=google/mantaray/manta:5.1.1/LMY49J/2640980:user/release-keys \
    PRIVATE_BUILD_DESC="mantaray-user 5.1.1 LMY49J 2640980 release-keys"
