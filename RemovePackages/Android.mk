LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE_TAGS := optional
LOCAL_STATIC_JAVA_LIBRARIES := android-common
LOCAL_CERTIFICATE := shared
LOCAL_PACKAGE_NAME := RemovePackages

LOCAL_OVERRIDES_PACKAGES := \
	Telecom \
	TelephonyProvider \
	TeleService
include $(BUILD_PACKAGE)
