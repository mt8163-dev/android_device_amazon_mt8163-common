/*
 * Copyright (C) 2007 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ANDROID_PERFSERVICE_TYPES_H
#define ANDROID_PERFSERVICE_TYPES_H

/* Scenarios, MUST align with PerfService.java */
enum {
    SCN_NONE            = 0,
    SCN_APP_SWITCH      = 1,  /* apply both for */
    SCN_APP_ROTATE      = 2,
    SCN_APP_TOUCH       = 3,
    SCN_SW_SNOOP_BOOST  = 4, // SCN_DONT_USE1
    SCN_SW_FRAME_UPDATE = 5,
    SCN_APP_LAUNCH      = 6,
    SCN_GAMING          = 7,
    SCN_NUM             = 8,
    SCN_APP_RUN_BASE = SCN_NUM,
};

enum {
    STATE_PAUSED    = 0,
    STATE_RESUMED   = 1,
    STATE_DESTORYED = 2,
    STATE_DEAD      = 3,
    STATE_STOPPED   = 4,
    STATE_NUM       = 5,
};

enum {
    CMD_GET_CPU_FREQ_LEVEL_COUNT        = 0,
    CMD_GET_CPU_FREQ_LITTLE_LEVEL_COUNT = 1,
    CMD_GET_CPU_FREQ_BIG_LEVEL_COUNT    = 2,
    CMD_GET_GPU_FREQ_LEVEL_COUNT        = 3,
    CMD_GET_MEM_FREQ_LEVEL_COUNT        = 4,
    CMD_GET_PERF_INDEX_MIN              = 5,
    CMD_GET_PERF_INDEX_MAX              = 6,
    CMD_GET_PERF_NORMALIZED_INDEX_MAX   = 7,
};

enum {
    CMD_SET_CPU_CORE_MIN            = 0,
    CMD_SET_CPU_CORE_MAX            = 1,
    CMD_SET_CPU_CORE_BIG_LITTLE_MIN = 2,
    CMD_SET_CPU_CORE_BIG_LITTLE_MAX = 3,
    CMD_SET_CPU_FREQ_MIN            = 4,
    CMD_SET_CPU_FREQ_MAX            = 5,
    CMD_SET_CPU_FREQ_BIG_LITTLE_MIN = 6,
    CMD_SET_CPU_FREQ_BIG_LITTLE_MAX = 7,
    CMD_SET_GPU_FREQ_MIN            = 8,
    CMD_SET_GPU_FREQ_MAX            = 9,
    CMD_SET_VCORE                   = 10,
    CMD_SET_SCREEN_OFF_STATE        = 11,
    CMD_SET_CPUFREQ_HISPEED_FREQ    = 12,
    CMD_SET_CPUFREQ_MIN_SAMPLE_TIME = 13,
    CMD_SET_CPUFREQ_ABOVE_HISPEED_DELAY = 14,
    CMD_SET_CLUSTER_CPU_CORE_MIN    = 15,
    CMD_SET_CLUSTER_CPU_CORE_MAX    = 16,
    CMD_SET_CLUSTER_CPU_FREQ_MIN    = 17,
    CMD_SET_CLUSTER_CPU_FREQ_MAX    = 18,
    CMD_SET_ROOT_CLUSTER            = 19,
    CMD_SET_CPU_UP_THRESHOLD        = 20,
    CMD_SET_CPU_DOWN_THRESHOLD      = 21,
    CMD_SET_PERF_INDEX              = 22,
    CMD_SET_NORMALIZED_PERF_INDEX   = 23,
};

enum {
    SCREEN_OFF_DISABLE      = 0,
    SCREEN_OFF_ENABLE       = 1,
    SCREEN_OFF_WAIT_RESTORE = 2,
};

enum {
    DISPLAY_TYPE_GAME   = 0,
    DISPLAY_TYPE_OTHERS = 1,
    DISPLAY_TYPE_VP     = 2,
};

enum {
    NOTIFY_USER_TYPE_PID = 0,
    NOTIFY_USER_TYPE_FRAME_UPDATE = 1,
    NOTIFY_USER_TYPE_DISPLAY_TYPE = 2,
    NOTIFY_USER_TYPE_SCENARIO_ON  = 3,
    NOTIFY_USER_TYPE_SCENARIO_OFF = 4,
};

#endif // ANDROID_PERFSERVICE_H