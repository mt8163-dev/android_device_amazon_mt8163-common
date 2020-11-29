# Release name
PRODUCT_RELEASE_NAME := KFDOWI

# Inherit some common CM stuff.
$(call inherit-product-if-exists, vendor/cm/config/common_full_tablet_wifionly.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/core_64_bit.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/full_base.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/product_launched_with_l.mk)

# Inherit device configuration
$(call inherit-product, device/amazon/douglas/device_douglas.mk)

# Device identifier. This must come after all inclusions
PRODUCT_DEVICE := douglas
PRODUCT_NAME := cm_douglas
PRODUCT_BRAND := google
PRODUCT_MODEL := Fire HD8 2017
PRODUCT_MANUFACTURER := Amazon
