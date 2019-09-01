LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES := libaudio_shim.c
LOCAL_LDLIBS += -ldl
LOCAL_C_INCLUDES += \
	external/tinyalsa/include \
	system/core/include/cutils
LOCAL_SHARED_LIBRARIES := liblog libtinyalsa

LOCAL_MODULE := libaudio_shim
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES

include $(BUILD_SHARED_LIBRARY)