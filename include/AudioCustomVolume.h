/*
 * Copyright (C) 2014 The Android Open Source Project
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

#ifndef ANDROID_AUDIOCUSTOMVOLUME_H
#define ANDROID_AUDIOCUSTOMVOLUME_H
#include "cfgdefault/CFG_Audio_Default.h"
#include "AudioMTKHardwareCommand.h"


namespace android {

#define CUSTOM_VOICE_VOLUME_MAX       (160)
#define CUSTOM_VOICE_ONEDB_STEP         (4)
#define CUSTOM_VOLUME_REV_1           (0x01)

//#ifndef GET_AUDIO_POLICY_VOL_FROM_VER1_DATA
//#define GET_AUDIO_POLICY_VOL_FROM_VER1_DATA (0x102)
//#endif

const float fBPerStep = 0.25f;
const float fCUSTOM_VOLUME_MAPPING_STEP = 256.0f;
const float fBConvert = -fBPerStep * 2.302585093f / 20.0f;
const float fBConvertInverse = 1.0f / fBConvert;


enum CustomVolumeMode {
    CUSTOM_VOLUME_NORMAL_MODE = 0,
    CUSTOM_VOLUME_HEADSET_MODE,
    CUSTOM_VOLUME_SPEAKER_MODE,
    CUSTOM_VOLUME_HEADSET_SPEAKER_MODE,
    CUSTOM_NUM_OF_VOL_MODE
};

enum CustomVolumeType {
    CUSTOM_VOL_TYPE_VOICE_CALL = 0,
    CUSTOM_VOL_TYPE_SYSTEM,
    CUSTOM_VOL_TYPE_RING,
    CUSTOM_VOL_TYPE_MUSIC,
    CUSTOM_VOL_TYPE_ALARM,
    CUSTOM_VOL_TYPE_NOTIFICATION,
    CUSTOM_VOL_TYPE_BLUETOOTH_SCO,
    CUSTOM_VOL_TYPE_ENFORCED_AUDIBLE,
    CUSTOM_VOL_TYPE_DTMF,
    CUSTOM_VOL_TYPE_TTS,
    CUSTOM_VOL_TYPE_BOOT,
    CUSTOM_VOL_TYPE_VIBSPK,
    CUSTOM_VOL_TYPE_SIP,
    CUSTOM_VOL_TYPE_ACCESSIBILITY,
    CUSTOM_VOL_TYPE_REROUTING,
    CUSTOM_VOL_TYPE_PATCH,
    CUSTOM_NUM_OF_VOL_TYPE
};


#define CUSTOM_AUDIO_MAX_VOLUME_STEP (AUDIO_MAX_VOLUME_STEP)

const unsigned char audiovolume_dtmf[NUM_OF_VOL_MODE][AUDIO_MAX_VOLUME_STEP]=
{
    {128,132,136,140,144,148,152,156,160,164,168,172,176,180,184},
    {128,132,136,140,144,148,152,156,160,164,168,172,176,180,184},
    {128,132,136,140,144,148,152,156,160,164,168,172,176,180,184},
    {128,132,136,140,144,148,152,156,160,164,168,172,176,180,184}
};

const unsigned char audiovolume_system[NUM_OF_VOL_MODE][AUDIO_MAX_VOLUME_STEP]=
{
    {144,152,176,184,192,200,208,216,224,232,240,244,248,252,255},
    {144,152,160,168,176,184,192,200,208,216,224,232,240,248,255},
    {168,176,184,192,200,208,216,224,232,236,240,244,248,252,255},
    {168,176,184,192,200,208,216,224,232,236,240,244,248,252,255}
};

const unsigned char audiovolume_rerouting[NUM_OF_VOL_MODE][AUDIO_MAX_VOLUME_STEP]=
{
    {255,255,255,255,255,255,255,255,255,255,255,255,255,255,255},
    {255,255,255,255,255,255,255,255,255,255,255,255,255,255,255},
    {255,255,255,255,255,255,255,255,255,255,255,255,255,255,255},
    {255,255,255,255,255,255,255,255,255,255,255,255,255,255,255}
};

const unsigned char audiovolume_patch[NUM_OF_VOL_MODE][AUDIO_MAX_VOLUME_STEP]=
{
    {255,255,255,255,255,255,255,255,255,255,255,255,255,255,255},
    {255,255,255,255,255,255,255,255,255,255,255,255,255,255,255},
    {255,255,255,255,255,255,255,255,255,255,255,255,255,255,255},
    {255,255,255,255,255,255,255,255,255,255,255,255,255,255,255}
};

const unsigned char audiovolume_tts_nonspeaker[NUM_OF_VOL_MODE][AUDIO_MAX_VOLUME_STEP]=
{
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {255,255,255,255,255,255,255,255,255,255,255,255,255,255,255},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
};


typedef struct _AUDIO_CUSTOM_VOLUME_STRUCT {
    unsigned char bRev;
    unsigned char bReady;
    unsigned char audiovolume_steamtype[CUSTOM_NUM_OF_VOL_TYPE][CUSTOM_NUM_OF_VOL_MODE][CUSTOM_AUDIO_MAX_VOLUME_STEP];
    unsigned char audiovolume_level[CUSTOM_NUM_OF_VOL_TYPE];
} AUDIO_CUSTOM_VOLUME_STRUCT;

}

#endif
