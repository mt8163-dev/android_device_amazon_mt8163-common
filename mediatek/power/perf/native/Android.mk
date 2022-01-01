LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE_TAGS := optional
LOCAL_PRELINK_MODULE := false

LOCAL_C_INCLUDES += \
	$(JNI_H_INCLUDE) \
	$(LOCAL_PATH)

LOCAL_SHARED_LIBRARIES += \
	liblog \
	libnativehelper \
	libdl \
	libbinder \
	libcutils \
	libutils

LOCAL_SRC_FILES := PerfServiceNative.cpp
LOCAL_MODULE := libperfservicenative
include $(BUILD_SHARED_LIBRARY)