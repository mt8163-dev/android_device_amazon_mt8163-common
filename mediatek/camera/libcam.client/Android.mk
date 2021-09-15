LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES := \
    StreamImgBuf.cpp \

LOCAL_C_INCLUDES := \
    $(TOP)/system/media/camera/include \
    $(TOP)/system/core/include \
    $(TOP)/frameworks/native/libs/nativebase/include

LOCAL_SHARED_LIBRARIES := liblog libutils libcutils libdl libcam1client libcam_utils
LOCAL_MODULE := libcam.client
LOCAL_MODULE_TAGS := optional
include $(BUILD_SHARED_LIBRARY)
