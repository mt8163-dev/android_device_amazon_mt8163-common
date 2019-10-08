$(call inherit-product-if-exists, vendor/cm/config/common_full_tablet_wifionly.mk)

$(call inherit-product, device/amazon/douglas/full_douglas.mk)


TARGET_SCREEN_WIDTH := 1280
TARGET_SCREEN_HEIGHT := 800

PRODUCT_CHARACTERISTICS := tablet

PRODUCT_NAME := cm_douglas
PRODUCT_RELEASE_NAME := douglas

# Override the fingerprint for SafetyNet
PRODUCT_BUILD_PROP_OVERRIDES += \
    BUILD_FINGERPRINT=google/douglas/douglas:5.1.1/LVY48F/50.6.3.6_user_636558520:user/release-keys \
    BUILD_FINGERPRINT=Amazon/douglas/douglas:5.1.1/LVY48F/50.6.3.6_user_636558520:user/release-keys \
    PRIVATE_BUILD_DESC="douglas-user 5.1.1 LVY48F 50.6.3.6_user_636558520 release-keys"
    PRIVATE_BUILD_DESC="douglas-user 5.1.1 LVY48F 50.6.3.6_user_636558520 release-keys"
