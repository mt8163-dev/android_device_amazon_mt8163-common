#
# Camera wrapper library for libcam.halsensor
#

LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_CLANG := true

LOCAL_SRC_FILES := \
    imgsensor_drv.cpp

LOCAL_CFLAGS += -DMTK_SUB_IMGSENSOR

LOCAL_SHARED_LIBRARIES := liblog libcutils libdl libutils \
			  libcameracustom libcam2halsensor

LOCAL_MODULE := libcam.halsensor
LOCAL_MODULE_TAGS := optional

include $(BUILD_SHARED_LIBRARY)
