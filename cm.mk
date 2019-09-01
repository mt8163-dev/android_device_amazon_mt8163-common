# Boot animation
TARGET_SCREEN_WIDTH := 1280
TARGET_SCREEN_HEIGHT := 800

$(call inherit-product-if-exists, vendor/cm/config/common_full_tablet_wifionly.mk)

# Inherit device configuration
$(call inherit-product, device/amazon/douglas/full_douglas.mk)

## Device identifier. This must come after all inclusions
PRODUCT_DEVICE := douglas
PRODUCT_NAME := cm_douglas
PRODUCT_BRAND := google
PRODUCT_MODEL := KFDOWI
PRODUCT_MANUFACTURER := amzn
