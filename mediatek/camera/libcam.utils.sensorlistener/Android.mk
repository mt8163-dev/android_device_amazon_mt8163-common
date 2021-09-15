#XCORE: Porting sensorlistener for camera.
#XCORE: Its removed from libgui, so building with new libsensor.
#XCORE: Making shim causes sensors to stop polling.
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES += SensorListener.cpp

LOCAL_SHARED_LIBRARIES += liblog
LOCAL_SHARED_LIBRARIES += libutils
LOCAL_SHARED_LIBRARIES += libcutils
LOCAL_SHARED_LIBRARIES += libsensor
LOCAL_SHARED_LIBRARIES += libbinder

LOCAL_MODULE := libcam.utils.sensorlistener
LOCAL_MODULE_TAGS := optional

include $(BUILD_SHARED_LIBRARY)

