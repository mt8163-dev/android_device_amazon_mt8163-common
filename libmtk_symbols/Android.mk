LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES := \
    icu55.c \
    mtk_asc.cpp \
    mtk_audio.cpp \
    mtk_fence.cpp \
    mtk_omx.cpp \
    mtk_cam.cpp \
    mtk_ui.cpp


LOCAL_SHARED_LIBRARIES := libbinder liblog libgui libui libicuuc libicui18n libmedia
LOCAL_MODULE := libmtk_symbols
LOCAL_MODULE_TAGS := optional


include $(BUILD_SHARED_LIBRARY)
