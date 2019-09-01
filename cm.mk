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
