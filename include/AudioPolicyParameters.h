#ifndef ANDROID_AUDIO_POLICY_PARAMETERS_H
#define ANDROID_AUDIO_POLICY_PARAMETERS_H

enum PolicyParameters
{
    POLICY_LOAD_VOLUME =         0,
    POLICY_SET_FM_SPEAKER,
    POLICY_CHECK_FM_PRIMARY_KEY_ROUTING,
    POLICY_SET_FM_PRESTOP,
    POLICY_SET_A2DP_FORCE_IGNORE,
    POLICY_SET_FM_TX_ENABLE,
    POLICY_SET_FM_RX_FORCE_DISABLE_TX,
    POLICY_SET_LOSSLESS_BT_STATUS,
    POLICY_SET_CROSSMOUNT_LOCAL_PLAYBACK, //For MTK_CROSSMOUNT_SUPPORT
    POLICY_SET_CROSSMOUNT_MIC_LOCAL_PLAYBACK, //For MTK_CROSSMOUNT_SUPPORT
};

enum FMStatus
{
    FM_STATE_STOP = 0,
    FM_STATE_PLAY,
    FM_STATE_PRESTOP,
    FM_STATE_PRESTOP_WITH_MUTE,
};


// for User Case Manager
static const char *keyInitVoume = "VolumeInit";
static const char *keySetVoumeIndex = "SetVolumeIndex";
static const char *keySetStreamStart = "SetStreamStart";
static const char *keySetStreamStop = "SetStreamStop";
static const char *keySetRecordStreamStart = "SetRecordStreamStart";
static const char *keySetRecordStreamStop = "SetRecordStreamStop";

//!  BESLOUDNESS_CONTROL_CALLBACK_STRUCT interface
/*!
this structure is hold for flinger callback funtion
*/
typedef struct _BESLOUDNESS_CONTROL_CALLBACK_STRUCT
{
    void (*callback)(void *data);
} BESLOUDNESS_CONTROL_CALLBACK_STRUCT;

#endif // end of ANDROID_AUDIO_POLICY_PARAMETERS_H
