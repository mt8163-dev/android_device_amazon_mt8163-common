######################################################################
#
# libgui_ext.so
#

LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES := \
    IGuiExtService.cpp \
    GuiExtService.cpp \
    GuiExtClient.cpp \
    GuiExtClientProducer.cpp \
    GuiExtClientConsumer.cpp \
    GuiExtImpl.cpp

LOCAL_C_INCLUDES:= \
    $(TOP)/frameworks/base/include/ \
    $(TOP)/device/amazon/mt8163-common/mediatek/graphics/gui_ext/inc \
    $(TOP)/device/amazon/mt8163-common/mediatek/graphics/ui_ext/inc \
    $(TOP)/device/amazon/mt8163-common/mediatek/graphics/gralloc_extra/include

LOCAL_SHARED_LIBRARIES := \
    libutils \
    libcutils \
    libbinder \
    libhardware \
    libhardware_legacy \
    libgui \
    liblog \
    libui \
    libdl \
    libion \
    libion_mtk \
    libgralloc_extra \
    libui_ext

# for bring up, please unmark this line
# LOCAL_CFLAGS += -DMTK_DO_NOT_USE_GUI_EXT

ifeq ($(TARGET_AOSP_BUILD), true)
LOCAL_CFLAGS += -DAOSP_BUILD
endif

ifneq ($(strip $(TARGET_BUILD_VARIANT)), eng)
LOCAL_CFLAGS += -DMTK_USER_BUILD
endif

ifeq ($(MTK_MIRAVISION_SUPPORT),yes)
LOCAL_CFLAGS += -DCONFIG_FOR_SOURCE_PQ
endif

LOCAL_MODULE := libgui_ext

LOCAL_PROPRIETARY_MODULE := true

LOCAL_MODULE_TAGS := optional

include $(BUILD_SHARED_LIBRARY)

######################################################################
