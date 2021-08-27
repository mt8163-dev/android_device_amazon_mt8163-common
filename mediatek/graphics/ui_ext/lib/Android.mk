######################################################################
#
# libui_ext.so
#

LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES := \
	GraphicBufferUtil.cpp \
	FpsCounter.cpp \
	IDumpTunnel.cpp \
	RefBaseDump.cpp

LOCAL_C_INCLUDES := \
	$(TOP)/device/amazon/mt8163-common/mediatek/graphics/ui_ext/inc \
	$(TOP)/device/amazon/mt8163-common/mediatek/graphics/gralloc_extra/include \
	$(TOP)/external/libpng \
	$(TOP)/external/zlib \
	$(TOP)/external/skia/src/images \
	$(TOP)/external/skia/include/core \
    $(TOP)/external/skia/include/config

LOCAL_SHARED_LIBRARIES := \
	libpng \
	libutils \
	libui \
	libcutils \
	libhardware \
	libgralloc_extra \
	libbinder \
	libdl \
	liblog

ifeq ($(MTK_MIRAVISION_SUPPORT),yes)
LOCAL_CFLAGS += -DCONFIG_FOR_SOURCE_PQ
endif

ifeq ($(FPGA_EARLY_PORTING), yes)
LOCAL_CFLAGS += -DFPGA_EARLY_PORTING
endif

LOCAL_MODULE := libui_ext

LOCAL_PROPRIETARY_MODULE := true

LOCAL_MODULE_TAGS := optional

include $(BUILD_SHARED_LIBRARY)

######################################################################
