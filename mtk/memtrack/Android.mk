# Copyright (C) 2013 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

LOCAL_PATH := $(call my-dir)

# HAL module implemenation stored in
# hw/<POWERS_HARDWARE_MODULE_ID>.<ro.hardware>.so
include $(CLEAR_VARS)

LOCAL_MODULE_RELATIVE_PATH := hw
LOCAL_C_INCLUDES += hardware/libhardware/include \
                    vendor/mediatek/proprietary/hardware/libmemtrack

LOCAL_SHARED_LIBRARIES := liblog
LOCAL_SRC_FILES := memtrack_mtk.c memtrack_graphic.c

ifeq ($(TARGET_BOARD_PLATFORM),mt6795)
LOCAL_SHARED_LIBRARIES += libmemtrack_GL
else ifeq ($(TARGET_BOARD_PLATFORM),mt6595)
LOCAL_SHARED_LIBRARIES += libmemtrack_GL
else ifeq ($(TARGET_BOARD_PLATFORM),mt6572)
LOCAL_SRC_FILES += memtrack_gl_mali_utgard.c
else ifeq ($(TARGET_BOARD_PLATFORM),mt6580)
LOCAL_SRC_FILES += memtrack_gl_mali_utgard.c
else ifeq ($(TARGET_BOARD_PLATFORM),mt6582)
LOCAL_SRC_FILES += memtrack_gl_mali_utgard.c
else ifeq ($(TARGET_BOARD_PLATFORM),mt6592)
LOCAL_SRC_FILES += memtrack_gl_mali_utgard.c
else
LOCAL_SRC_FILES += memtrack_gl_mali_midgard.c
endif

LOCAL_MODULE := memtrack.$(TARGET_BOARD_PLATFORM)

LOCAL_MULTILIB := both
include $(BUILD_SHARED_LIBRARY)


