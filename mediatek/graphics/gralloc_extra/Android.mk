LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES := \
	GraphicBufferExtra.cpp \
	GraphicBufferExtra_hal.cpp

LOCAL_C_INCLUDES := \
	$(LOCAL_PATH)/include

LOCAL_SHARED_LIBRARIES := \
	libhardware \
	libcutils \
	libutils \
	liblog

LOCAL_MODULE := libgralloc_extra

LOCAL_PROPRIETARY_MODULE := true

include $(BUILD_SHARED_LIBRARY)
