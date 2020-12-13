LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)
LOCAL_C_INCLUDES += \
	external/tinyalsa/include \
	system/core/include/cutils

LOCAL_SRC_FILES:= audiofix.c
LOCAL_SHARED_LIBRARIES:= liblog libcutils libtinyalsa

LOCAL_MODULE := audiofix
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_PATH := $(TARGET_OUT_OPTIONAL_EXECUTABLES)

include $(BUILD_EXECUTABLE)
