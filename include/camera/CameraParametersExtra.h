/*
 * Copyright (C) 2020 The LineageOS Project
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

#define CAMERA_PARAMETERS_EXTRA_C \
    const char CameraParameters::PROPERTY_KEY_CLIENT_APPMODE[]   = "client.appmode"; \
    const char CameraParameters::APP_MODE_NAME_DEFAULT[]         = "Default"; \
    const char CameraParameters::APP_MODE_NAME_MTK_ENG[]         = "MtkEng"; \
    const char CameraParameters::APP_MODE_NAME_MTK_ATV[]         = "MtkAtv"; \
    const char CameraParameters::APP_MODE_NAME_MTK_STEREO[]      = "MtkStereo"; \
    const char CameraParameters::APP_MODE_NAME_MTK_VT[]          = "MtkVt"; \
    const char CameraParameters::APP_MODE_NAME_MTK_PHOTO[]       = "MtkPhoto"; \
    const char CameraParameters::APP_MODE_NAME_MTK_VIDEO[]       = "MtkVideo"; \
    const char CameraParameters::APP_MODE_NAME_MTK_ZSD[]         = "MtkZsd"; \
    const char CameraParameters::SCENE_MODE_NORMAL[] = "normal"; \
    const char CameraParameters::KEY_FB_SMOOTH_LEVEL[]       = "fb-smooth-level"; \
    const char CameraParameters::KEY_FB_SMOOTH_LEVEL_MIN[]   = "fb-smooth-level-min"; \
    const char CameraParameters::KEY_FB_SMOOTH_LEVEL_MAX[]   = "fb-smooth-level-max"; \
    const char CameraParameters::KEY_FB_SMOOTH_LEVEL_Default[]   = "fb-smooth-level-default"; \
    const char CameraParameters::KEY_FB_SKIN_COLOR[]         = "fb-skin-color"; \
    const char CameraParameters::KEY_FB_SKIN_COLOR_MIN[]     = "fb-skin-color-min"; \
    const char CameraParameters::KEY_FB_SKIN_COLOR_MAX[]     = "fb-skin-color-max"; \
    const char CameraParameters::KEY_FB_SKIN_COLOR_Default[]     = "fb-skin-color-default"; \
    const char CameraParameters::KEY_FB_SHARP[]              = "fb-sharp"; \
    const char CameraParameters::KEY_FB_SHARP_MIN[]          = "fb-sharp-min"; \
    const char CameraParameters::KEY_FB_SHARP_MAX[]          = "fb-sharp-max"; \
    const char CameraParameters::KEY_FB_ENLARGE_EYE[]        = "fb-enlarge-eye"; \
    const char CameraParameters::KEY_FB_ENLARGE_EYE_MIN[]    = "fb-enlarge-eye-min"; \
    const char CameraParameters::KEY_FB_ENLARGE_EYE_MAX[]    = "fb-enlarge-eye-max"; \
    const char CameraParameters::KEY_FB_SLIM_FACE[]          = "fb-slim-face"; \
    const char CameraParameters::KEY_FB_SLIM_FACE_MIN[]      = "fb-slim-face-min"; \
    const char CameraParameters::KEY_FB_SLIM_FACE_MAX[]      = "fb-slim-face-max"; \
    const char CameraParameters::KEY_FB_EXTREME_BEAUTY[]     = "fb-extreme-beauty"; \
    const char CameraParameters::KEY_FB_TOUCH_POS[]          = "fb-touch-pos"; \
    const char CameraParameters::KEY_FB_FACE_POS[]           = "fb-face-pos"; \
    const char CameraParameters::KEY_FACE_BEAUTY[]           = "face-beauty"; \
    const char CameraParameters::KEY_FB_EXTREME_SUPPORTED[]  = "fb-extreme-beauty-supported"; \
    const char CameraParameters::KEY_FEATURE_MAX_FPS[]       = "feature-max-fps"; \
    const char CameraParameters::KEY_VIDEO_FACE_BEAUTY_SUPPORTED[] = "vfb-supported"; \
    const char CameraParameters::KEY_EXPOSURE[] = "exposure"; \
    const char CameraParameters::KEY_EXPOSURE_METER[] = "exposure-meter"; \
    const char CameraParameters::KEY_ISO_SPEED[] = "iso-speed"; \
    const char CameraParameters::KEY_AE_MODE[] = "ae-mode"; \
    const char CameraParameters::KEY_FOCUS_METER[] = "focus-meter"; \
    const char CameraParameters::KEY_EDGE[] = "edge"; \
    const char CameraParameters::KEY_HUE[] = "hue"; \
    const char CameraParameters::KEY_SATURATION[] = "saturation"; \
    const char CameraParameters::KEY_BRIGHTNESS[] = "brightness"; \
    const char CameraParameters::KEY_CONTRAST[] = "contrast"; \
    const char CameraParameters::KEY_AF_LAMP_MODE [] = "aflamp-mode"; \
    const char CameraParameters::KEY_STEREO_3D_PREVIEW_SIZE[] = "stereo3d-preview-size"; \
    const char CameraParameters::KEY_STEREO_3D_PICTURE_SIZE[] = "stereo3d-picture-size"; \
    const char CameraParameters::KEY_STEREO_3D_TYPE [] = "stereo3d-type"; \
    const char CameraParameters::KEY_STEREO_3D_MODE [] = "stereo3d-mode"; \
    const char CameraParameters::KEY_STEREO_3D_IMAGE_FORMAT [] = "stereo3d-image-format"; \
    const char CameraParameters::KEY_ZSD_MODE[] = "zsd-mode"; \
    const char CameraParameters::KEY_SUPPORTED_ZSD_MODE[] = "zsd-supported"; \
    const char CameraParameters::KEY_FPS_MODE[] = "fps-mode"; \
    const char CameraParameters::KEY_FOCUS_DRAW[] = "af-draw"; \
    const char CameraParameters::KEY_CAPTURE_MODE[] = "cap-mode"; \
    const char CameraParameters::KEY_SUPPORTED_CAPTURE_MODES[] = "cap-mode-values"; \
    const char CameraParameters::KEY_CAPTURE_PATH[] = "capfname"; \
    const char CameraParameters::KEY_BURST_SHOT_NUM[] = "burst-num"; \
    const char CameraParameters::KEY_MATV_PREVIEW_DELAY[] = "tv-delay"; \
    const char CameraParameters::KEY_PANORAMA_IDX[] = "pano-idx"; \
    const char CameraParameters::KEY_PANORAMA_DIR[] = "pano-dir"; \
    const char CameraParameters::EXPOSURE_METER_SPOT[] = "spot"; \
    const char CameraParameters::EXPOSURE_METER_CENTER[] = "center"; \
    const char CameraParameters::EXPOSURE_METER_AVERAGE[] = "average"; \
    const char CameraParameters::ISO_SPEED_AUTO[] = "auto"; \
    const char CameraParameters::ISO_SPEED_100[] = "100"; \
    const char CameraParameters::ISO_SPEED_200[] = "200"; \
    const char CameraParameters::ISO_SPEED_400[] = "400"; \
    const char CameraParameters::ISO_SPEED_800[] = "800"; \
    const char CameraParameters::ISO_SPEED_1600[] = "1600"; \
    const char CameraParameters::FOCUS_METER_SPOT[] = "spot"; \
    const char CameraParameters::FOCUS_METER_MULTI[] = "multi"; \
    const char CameraParameters::KEY_AWB2PASS[] = "awb-2pass"; \
    const char CameraParameters::KEY_CAMERA_MODE[] = "mtk-cam-mode"; \
    const int CameraParameters::CAMERA_MODE_NORMAL  = 0; \
    const int CameraParameters::CAMERA_MODE_MTK_PRV = 1; \
    const int CameraParameters::CAMERA_MODE_MTK_VDO = 2; \
    const int CameraParameters::CAMERA_MODE_MTK_VT  = 3; \
    const int CameraParameters::FPS_MODE_NORMAL = 0; \
    const int CameraParameters::FPS_MODE_FIX = 1; \
    const char CameraParameters::CAPTURE_MODE_PANORAMA_SHOT[] = "panoramashot"; \
    const char CameraParameters::CAPTURE_MODE_BURST_SHOT[] = "burstshot"; \
    const char CameraParameters::CAPTURE_MODE_NORMAL[] = "normal"; \
    const char CameraParameters::CAPTURE_MODE_BEST_SHOT[] = "bestshot"; \
    const char CameraParameters::CAPTURE_MODE_EV_BRACKET_SHOT[] = "evbracketshot"; \
    const char CameraParameters::CAPTURE_MODE_SMILE_SHOT[] = "smileshot"; \
    const char CameraParameters::CAPTURE_MODE_MAV_SHOT[] = "mav"; \
    const char CameraParameters::CAPTURE_MODE_AUTO_PANORAMA_SHOT[] = "autorama"; \
    const char CameraParameters::CAPTURE_MODE_MOTION_TRACK_SHOT[] = "motiontrack"; \
    const char CameraParameters::CAPTURE_MODE_HDR_SHOT[] = "hdr"; \
    const char CameraParameters::CAPTURE_MODE_ASD_SHOT[] = "asd"; \
    const char CameraParameters::CAPTURE_MODE_ZSD_SHOT[] = "zsd"; \
    const char CameraParameters::CAPTURE_MODE_PANO_3D[] = "pano_3d"; \
    const char CameraParameters::CAPTURE_MODE_SINGLE_3D[] = "single_3d"; \
    const char CameraParameters::CAPTURE_MODE_FACE_BEAUTY[] = "face_beauty"; \
    const char CameraParameters::CAPTURE_MODE_CONTINUOUS_SHOT[] = "continuousshot"; \
    const char CameraParameters::CAPTURE_MODE_MULTI_MOTION[] = "multi_motion"; \
    const char CameraParameters::CAPTURE_MODE_GESTURE_SHOT[] = "gestureshot"; \
    const char CameraParameters::PANORAMA_DIR_RIGHT[] = "right"; \
    const char CameraParameters::PANORAMA_DIR_LEFT[] = "left"; \
    const char CameraParameters::PANORAMA_DIR_TOP[] = "top"; \
    const char CameraParameters::PANORAMA_DIR_DOWN[] = "down"; \
    const int CameraParameters::ENABLE = 1; \
    const int CameraParameters::DISABLE = 0; \
    const char CameraParameters::HIGH[] = "high"; \
    const char CameraParameters::MIDDLE[] = "middle"; \
    const char CameraParameters::LOW[] = "low"; \
    const char CameraParameters::KEY_PREVIEW_INT_FORMAT[] = "prv-int-fmt"; \
    const char CameraParameters::PIXEL_FORMAT_YUV420I[] = "yuv420i-yyuvyy-3plane"; \
    const char CameraParameters::PIXEL_FORMAT_YV12_GPU[] = "yv12-gpu"; \
    const char CameraParameters::PIXEL_FORMAT_YUV422I_UYVY[] = "yuv422i-uyvy"; \
    const char CameraParameters::PIXEL_FORMAT_YUV422I_VYUY[] = "yuv422i-vyuy"; \
    const char CameraParameters::PIXEL_FORMAT_YUV422I_YVYU[] = "yuv422i-yvyu"; \
    const char CameraParameters::PIXEL_FORMAT_BAYER8[] = "bayer8"; \
    const char CameraParameters::PIXEL_FORMAT_BAYER10[] = "bayer10"; \
    const char CameraParameters::PIXEL_FORMAT_BITSTREAM[] = "bitstream"; \
    const char CameraParameters::PIXEL_FORMAT_YUV420SP_NV12[] = "yuv420sp-nv12"; \
    const char CameraParameters::KEY_BRIGHTNESS_VALUE[] = "brightness_value"; \
    const char CameraParameters::KEY_ISP_MODE[] = "isp-mode"; \
    const char CameraParameters::KEY_AF_X[] = "af-x"; \
    const char CameraParameters::KEY_AF_Y[] = "af-y"; \
    const char CameraParameters::EFFECT_SEPIA_BLUE[] = "sepiablue"; \
    const char CameraParameters::EFFECT_SEPIA_GREEN[] = "sepiagreen"; \
    const char CameraParameters::EFFECT_NASHVILLE[] = "nashville"; \
    const char CameraParameters::EFFECT_HEFE[] = "hefe"; \
    const char CameraParameters::EFFECT_VALENCIA[] = "valencia"; \
    const char CameraParameters::EFFECT_XPROII[] = "xproll"; \
    const char CameraParameters::EFFECT_LOFI[] = "lofi"; \
    const char CameraParameters::EFFECT_SIERRA[] = "sierra"; \
    const char CameraParameters::EFFECT_KELVIN[] = "kelvin"; \
    const char CameraParameters::EFFECT_WALDEN[] = "walden"; \
    const char CameraParameters::EFFECT_F1977[] = "f1977"; \
    const char CameraParameters::ON[] = "on"; \
    const char CameraParameters::OFF[] = "off"; \
    const char CameraParameters::WHITE_BALANCE_TUNGSTEN[] = "tungsten"; \
    const char CameraParameters::ISO_SPEED_ENG[] = "iso-speed-eng"; \
    const char CameraParameters::KEY_RAW_SAVE_MODE[] = "rawsave-mode"; \
    const char CameraParameters::KEY_RAW_PATH[] = "rawfname"; \
    const char CameraParameters::KEY_FAST_CONTINUOUS_SHOT[] = "fast-continuous-shot"; \
    const char CameraParameters::KEY_CSHOT_INDICATOR[] = "cshot-indicator"; \
    const char CameraParameters::KEY_FOCUS_ENG_MODE[]        = "afeng-mode"; \
    const char CameraParameters::KEY_FOCUS_ENG_STEP[]        = "afeng-pos"; \
    const char CameraParameters::KEY_FOCUS_ENG_MAX_STEP[]    = "afeng-max-focus-step"; \
    const char CameraParameters::KEY_FOCUS_ENG_MIN_STEP[]    = "afeng-min-focus-step"; \
    const char CameraParameters::KEY_FOCUS_ENG_BEST_STEP[]   = "afeng-best-focus-step"; \
    const char CameraParameters::KEY_RAW_DUMP_FLAG[]         = "afeng_raw_dump_flag"; \
    const char CameraParameters::KEY_PREVIEW_DUMP_RESOLUTION[] = "prv-dump-res"; \
    const int CameraParameters::PREVIEW_DUMP_RESOLUTION_NORMAL  = 0; \
    const int CameraParameters::PREVIEW_DUMP_RESOLUTION_CROP  = 1; \
    const char CameraParameters::KEY_MAX_NUM_DETECTED_OBJECT[] = "max-num-ot"; \
    const char CameraParameters::KEY_HEARTBEAT_MONITOR[] = "mtk-heartbeat-monitor"; \
    const char CameraParameters::KEY_HEARTBEAT_MONITOR_SUPPORTED[] = "mtk-heartbeat-monitor-supported"; \
    const char CameraParameters::KEY_VIDEO_HDR[] = "video-hdr"; \
    const char CameraParameters::KEY_VIDEO_HDR_MODE[] = "video-hdr-mode"; \
    const char CameraParameters::VIDEO_HDR_MODE_IVHDR[] = "video-hdr-mode-ivhdr"; \
    const char CameraParameters::VIDEO_HDR_MODE_MVHDR[] = "video-hdr-mode-mvhdr"; \
    const char CameraParameters::VIDEO_HDR_MODE_ZVHDR[] = "video-hdr-mode-zvhdr"; \
    const char CameraParameters::VIDEO_HDR_SIZE_DEVISOR[] = "video-hdr-size-devisor"; \
    const char CameraParameters::KEY_SINGLE_FRAME_CAPTURE_HDR_SUPPORTED[] = "single-frame-cap-hdr-supported"; \
    const char CameraParameters::KEY_SUPPORT_MZAF_FEATURE[] = "support-mzaf-feature"; \
    const char CameraParameters::KEY_HDR_DETECTION_SUPPORTED[] = "hdr-detection-supported"; \
    const char CameraParameters::KEY_HDR_AUTO_MODE[] = "hdr-auto-mode"; \
    const char CameraParameters::KEY_HDR_MODE[] = "hdr-mode"; \
    const char CameraParameters::HDR_MODE_OFF[] = "off"; \
    const char CameraParameters::HDR_MODE_ON[] = "on"; \
    const char CameraParameters::HDR_MODE_AUTO[] = "auto"; \
    const char CameraParameters::HDR_MODE_VIDEO_ON[] = "video-on"; \
    const char CameraParameters::HDR_MODE_VIDEO_AUTO[] = "video-auto"; \
    const char CameraParameters::KEY_ENG_AE_ENABLE[] = "ae-e"; \
    const char CameraParameters::KEY_ENG_PREVIEW_SHUTTER_SPEED[] = "prv-ss"; \
    const char CameraParameters::KEY_ENG_PREVIEW_SENSOR_GAIN[] = "prv-sr-g"; \
    const char CameraParameters::KEY_ENG_PREVIEW_ISP_GAIN[] = "prv-isp-g"; \
    const char CameraParameters::KEY_ENG_PREVIEW_AE_INDEX[] = "prv-ae-i"; \
    const char CameraParameters::KEY_ENG_PREVIEW_ISO[]="prv-iso"; \
    const char CameraParameters::KEY_ENG_CAPTURE_SENSOR_GAIN[] = "cap-sr-g"; \
    const char CameraParameters::KEY_ENG_CAPTURE_ISP_GAIN[] = "cap-isp-g"; \
    const char CameraParameters::KEY_ENG_CAPTURE_SHUTTER_SPEED[] = "cap-ss"; \
    const char CameraParameters::KEY_ENG_CAPTURE_ISO[] = "cap-iso"; \
    const char CameraParameters::KEY_ENG_FLASH_DUTY_VALUE[] = "flash-duty-value"; \
    const char CameraParameters::KEY_ENG_FLASH_DUTY_MIN[] = "flash-duty-min"; \
    const char CameraParameters::KEY_ENG_FLASH_DUTY_MAX[] = "flash-duty-max"; \
    const char CameraParameters::KEY_ENG_ZSD_ENABLE[] = "eng-zsd-e"; \
    const char CameraParameters::KEY_SENSOR_TYPE[] = "sensor-type"; \
    const char CameraParameters::KEY_ENG_PREVIEW_FPS[] = "eng-prv-fps"; \
    const char CameraParameters::KEY_ENG_MSG[] = "eng-msg"; \
    const int  CameraParameters::KEY_ENG_FLASH_DUTY_DEFAULT_VALUE = -1; \
    const int  CameraParameters::KEY_ENG_FLASH_STEP_DEFAULT_VALUE = -1; \
    const char CameraParameters::KEY_ENG_FLASH_STEP_MIN[] = "flash-step-min"; \
    const char CameraParameters::KEY_ENG_FLASH_STEP_MAX[] = "flash-step-max"; \
    const char CameraParameters::KEY_ENG_FOCUS_FULLSCAN_FRAME_INTERVAL[] = "focus-fs-fi"; \
    const char CameraParameters::KEY_ENG_FOCUS_FULLSCAN_FRAME_INTERVAL_MAX[] = "focus-fs-fi-max"; \
    const char CameraParameters::KEY_ENG_FOCUS_FULLSCAN_FRAME_INTERVAL_MIN[] = "focus-fs-fi-min"; \
    const int  CameraParameters::KEY_ENG_FOCUS_FULLSCAN_FRAME_INTERVAL_MAX_DEFAULT = 65535; \
    const int  CameraParameters::KEY_ENG_FOCUS_FULLSCAN_FRAME_INTERVAL_MIN_DEFAULT = 0; \
    const char CameraParameters::KEY_ENG_FOCUS_FULLSCAN_DAC_STEP[] = "focus-fs-dac-step"; \
    const char CameraParameters::KEY_ENG_PREVIEW_FRAME_INTERVAL_IN_US[] = "eng-prv-fius"; \
    const char CameraParameters::KEY_ENG_PARAMETER1[] = "eng-p1"; \
    const char CameraParameters::KEY_ENG_PARAMETER2[] = "eng-p2"; \
    const char CameraParameters::KEY_ENG_PARAMETER3[] = "eng-p3"; \
    const char CameraParameters::KEY_ENG_RAW_OUTPUT_PORT[] = "raw-output-port"; \
    const int  CameraParameters::KEY_ENG_RAW_IMGO = 0; \
    const int  CameraParameters::KEY_ENG_RAW_RRZO = 1; \
    const char CameraParameters::KEY_ENG_ISP_PROFILE[] = "isp-profile"; \
    const int  CameraParameters::KEY_ENG_ISP_PREVIEW = 0; \
    const int  CameraParameters::KEY_ENG_ISP_CAPTURE = 1; \
    const int  CameraParameters::KEY_ENG_ISP_VIDEO = 2; \
    const char CameraParameters::KEY_ENG_EV_VALUE[] = "eng-ev-value"; \
    const char CameraParameters::KEY_ENG_EVB_ENABLE[] = "eng-evb-enable"; \
    const char CameraParameters::KEY_ENG_3ADB_FLASH_ENABLE[] = "eng-3adb-flash-enable"; \
    const char CameraParameters::KEY_ENG_SAVE_SHADING_TABLE[] = "eng-s-shad-t"; \
    const char CameraParameters::KEY_ENG_SHADING_TABLE[] = "eng-shad-t"; \
    const int CameraParameters::KEY_ENG_SHADING_TABLE_AUTO = 0; \
    const int CameraParameters::KEY_ENG_SHADING_TABLE_LOW = 1; \
    const int CameraParameters::KEY_ENG_SHADING_TABLE_MIDDLE = 2; \
    const int CameraParameters::KEY_ENG_SHADING_TABLE_HIGH = 3; \
    const int CameraParameters::KEY_ENG_SHADING_TABLE_TSF = 4; \
    const char CameraParameters::KEY_VR_BUFFER_COUNT[] = "vr-buf-count"; \
    const char CameraParameters::KEY_ENG_EV_CALBRATION_OFFSET_VALUE[] = "ev-cal-o"; \
    const char CameraParameters::KEY_ENG_MFLL_SUPPORTED[] = "eng-mfll-s"; \
    const char CameraParameters::KEY_ENG_MFLL_ENABLE[] = "eng-mfll-e"; \
    const char CameraParameters::KEY_ENG_MFLL_PICTURE_COUNT[] = "eng-mfll-pc"; \
    const char CameraParameters::KEY_ENG_SENOSR_MODE_SLIM_VIDEO1_SUPPORTED[] = "sv1-s"; \
    const char CameraParameters::KEY_ENG_SENOSR_MODE_SLIM_VIDEO2_SUPPORTED[] = "sv2-s"; \
    const char CameraParameters::KEY_ENG_VIDEO_RAW_DUMP_RESIZE_TO_2M_SUPPORTED[] = "vdr-r2m-s"; \
    const char CameraParameters::KEY_ENG_VIDEO_RAW_DUMP_RESIZE_TO_4K2K_SUPPORTED[] = "vdr-r4k2k-s"; \
    const char CameraParameters::KEY_ENG_VIDEO_RAW_DUMP_CROP_CENTER_2M_SUPPORTED[] = "vdr-cc2m-s"; \
    const char CameraParameters::KEY_ENG_VIDEO_RAW_DUMP_RESIZE[] = "vdr-r"; \
    const char CameraParameters::KEY_ENG_VIDEO_RAW_DUMP_SUPPORTED[] = "vrd-s"; \
    const char CameraParameters::KEY_ENG_VIDEO_RAW_DUMP_MANUAL_FRAME_RATE_SUPPORTED[] = "vrd-mfr-s"; \
    const char CameraParameters::KEY_ENG_VIDEO_RAW_DUMP_MANUAL_FRAME_RATE_ENABLE[] = "vrd-mfr-e"; \
    const char CameraParameters::KEY_ENG_VIDEO_RAW_DUMP_MANUAL_FRAME_RATE_MIN[] = "vrd-mfr-min"; \
    const char CameraParameters::KEY_ENG_VIDEO_RAW_DUMP_MANUAL_FRAME_RATE_MAX[] = "vrd-mfr-max"; \
    const char CameraParameters::KEY_ENG_VIDEO_RAW_DUMP_MANUAL_FRAME_RATE_RANGE_LOW[] = "vrd-mfr-low"; \
    const char CameraParameters::KEY_ENG_VIDEO_RAW_DUMP_MANUAL_FRAME_RATE_RANGE_HIGH[] = "vrd-mfr-high"; \
    const char CameraParameters::KEY_ENG_MTK_AWB_SUPPORTED[] = "mtk-awb-s"; \
    const char CameraParameters::KEY_ENG_SENSOR_AWB_SUPPORTED[] = "sr-awb-s"; \
    const char CameraParameters::KEY_ENG_MTK_AWB_ENABLE[] = "mtk-awb-e"; \
    const char CameraParameters::KEY_ENG_SENSOR_AWB_ENABLE[] = "sr-awb-e"; \
    const char CameraParameters::KEY_ENG_MTK_SHADING_SUPPORTED[] = "mtk-shad-s"; \
    const char CameraParameters::KEY_ENG_MTK_1to3_SHADING_SUPPORTED[] = "mtk-123-shad-s"; \
    const char CameraParameters::KEY_ENG_SENSOR_SHADNING_SUPPORTED[] = "sr-shad-s"; \
    const char CameraParameters::KEY_ENG_MTK_SHADING_ENABLE[] = "mtk-shad-e"; \
    const char CameraParameters::KEY_ENG_MTK_1to3_SHADING_ENABLE[] = "mtk-123-shad-e"; \
    const char CameraParameters::KEY_ENG_SENSOR_SHADNING_ENABLE[] = "sr-shad-e"; \
    const char CameraParameters::KEY_ENG_MANUAL_MULTI_NR_SUPPORTED[] = "mnr-s"; \
    const char CameraParameters::KEY_ENG_MANUAL_MULTI_NR_ENABLE[] = "mnr-e"; \
    const char CameraParameters::KEY_ENG_MANUAL_MULTI_NR_TYPE[] = "mnr-t"; \
    const char CameraParameters::KEY_ENG_VIDEO_HDR_SUPPORTED[] = "vhdr-s"; \
    const char CameraParameters::KEY_ENG_VIDEO_HDR_MODE[]= "vhdr-m"; \
    const char CameraParameters::KEY_ENG_VIDEO_HDR_RATIO[]= "vhdr-ratio"; \
    const char CameraParameters::KEY_HSVR_PRV_SIZE[] = "hsvr-prv-size"; \
    const char CameraParameters::KEY_SUPPORTED_HSVR_PRV_SIZE[] = "hsvr-prv-size-values"; \
    const char CameraParameters::KEY_HSVR_PRV_FPS[] = "hsvr-prv-fps"; \
    const char CameraParameters::KEY_SUPPORTED_HSVR_PRV_FPS[] = "hsvr-prv-fps-values"; \
    const char CameraParameters::KEY_HSVR_SIZE_FPS[] = "hsvr-size-fps"; \
    const char CameraParameters::KEY_SUPPORTED_HSVR_SIZE_FPS[] = "hsvr-size-fps-values"; \
    const char CameraParameters::KEY_MFB_MODE[] = "mfb"; \
    const char CameraParameters::KEY_MFB_MODE_MFLL[] = "mfll"; \
    const char CameraParameters::KEY_MFB_MODE_AIS[] = "ais"; \
    const char CameraParameters::KEY_PIP_MAX_FRAME_RATE_ZSD_ON[] = "pip-fps-zsd-on"; \
    const char CameraParameters::KEY_PIP_MAX_FRAME_RATE_ZSD_OFF[] = "pip-fps-zsd-off"; \
    const char CameraParameters::KEY_DYNAMIC_FRAME_RATE[] = "dynamic-frame-rate"; \
    const char CameraParameters::KEY_DYNAMIC_FRAME_RATE_SUPPORTED[] = "dynamic-frame-rate-supported"; \
    const char CameraParameters::KEY_STEREO_REFOCUS_MODE[] = "stereo-image-refocus"; \
    const char CameraParameters::KEY_STEREO_CAPTURE_MODE[] = "stereo-capture-mode"; \
    const char CameraParameters::KEY_STEREO_DEPTHAF_MODE[] = "stereo-depth-af"; \
    const char CameraParameters::KEY_STEREO_DISTANCE_MODE[] = "stereo-distance-measurement"; \
    const char CameraParameters::KEY_STEREO_PICTURE_SIZE[] = "stereo-picture-size"; \
    const char CameraParameters::KEY_SUPPORTED_STEREO_PICTURE_SIZE[] = "stereo-picture-size-values"; \
    const char CameraParameters::KEY_REFOCUS_PICTURE_SIZE[] = "refocus-picture-size"; \
    const char CameraParameters::KEY_SUPPORTED_REFOCUS_PICTURE_SIZE[] = "refocus-picture-size-values"; \
    const char CameraParameters::KEY_STEREO_PREVIEW_FRAME_RATE[] = "stereo-preview-frame-rate"; \
    const char CameraParameters::KEY_STEREO_CAPTURE_FRAME_RATE[] = "stereo-capture-frame-rate"; \
    const char CameraParameters::KEY_STEREO_SENSOR_INDEX_MAIN[]  = "stereo-sensor-index-main"; \
    const char CameraParameters::KEY_STEREO_SENSOR_INDEX_MAIN2[] = "stereo-sensor-index-main2"; \
    const char CameraParameters::KEY_STEREO_CAPTURE_SUPPORTED_MODULE[] = "stereo-capture-supported-module"; \
    const char CameraParameters::REAR[]  = "rear"; \
    const char CameraParameters::FRONT[] = "front"; \
    const char CameraParameters::KEY_STEREO_VSDOF_MODE[] = "stereo-vsdof-mode"; \
    const char CameraParameters::KEY_STEREO_DOF_LEVEL[] = "stereo-dof-level"; \
    const char CameraParameters::KEY_STEREO_SUPPORTED_DOF_LEVEL[] = "stereo-supported-dof-level"; \
    const char CameraParameters::KEY_STEREO_RESULT_DOF_LEVEL[] = "stereo-result-dof-level"; \
    const char CameraParameters::KEY_STEREO_VSDOF_SUPPORTED_MODULE[] = "stereo-vsdof-supported-module"; \
    const char CameraParameters::KEY_STEREO_TOUCH_POSITION[] = "stereo-touch-position"; \
    const char CameraParameters::KEY_STEREO_DENOISE_MODE[] = "stereo-denoise-mode"; \
    const char CameraParameters::KEY_STEREO_DENOISE_SUPPORTED_MODULE[] = "stereo-denoise-supported-module"; \
    const char CameraParameters::KEY_STEREO_3RDPARTY_MODE[] = "stereo-3rdparty-mode"; \
    const char CameraParameters::KEY_STEREO_3RDPARTY_SUPPORTED_MODULE[] = "stereo-3rdparty-supported-module"; \
    const char CameraParameters::KEY_STEREO_PREVIEW_ENABLE[] = "stereo-preview-enable"; \
    const char CameraParameters::KEY_DUALCAM_CAPTURE_MODE[] = "dualcam-capture-mode"; \
    const char CameraParameters::KEY_REFOCUS_JPS_FILE_NAME[] = "refocus-jps-file-name"; \
    const char CameraParameters::KEY_3DNR_MODE[] = "3dnr-mode"; \
    const char CameraParameters::KEY_3DNR_QUALITY_SUPPORTED[] = "3dnr-quality-supported"; \
    const char CameraParameters::KEY_EIS_SUPPORTED_FRAMES[] = "eis-supported-frames"; \
    const char CameraParameters::KEY_EIS25_MODE[] = "eis25-mode"; \
    const char CameraParameters::KEY_ENG_FLASH_CALIBRATION[] = "flash-cali"; \
    const char CameraParameters::KEY_ENG_MANUAL_SHUTTER_SPEED[] = "m-ss"; \
    const char CameraParameters:: KEY_ENG_MANUAL_SENSOR_GAIN[] = "m-sr-g"; \
    const char CameraParameters::KEY_ENG_SENOSR_MODE_SUPPORTED[] = "sen-mode-s"; \
    const char CameraParameters::KEY_GESTURE_SHOT[] = "gesture-shot"; \
    const char CameraParameters::KEY_GESTURE_SHOT_SUPPORTED[] = "gesture-shot-supported"; \
    const char CameraParameters::KEY_NATIVE_PIP[] = "native-pip"; \
    const char CameraParameters::KEY_NATIVE_PIP_SUPPORTED[] = "native-pip-supported"; \
    const char CameraParameters::KEY_PDAF[] = "pdaf"; \
    const char CameraParameters::KEY_PDAF_SUPPORTED[] = "pdaf-supported"; \
    const char CameraParameters::KEY_FIRST_PREVIEW_FRAME_BLACK[] = "first-preview-frame-black"; \
    const char CameraParameters::KEY_DNG_SUPPORTED[] = "dng-supported"; \
    const char CameraParameters::KEY_DISPLAY_ROTATION_SUPPORTED[] = "disp-rot-supported"; \
    const char CameraParameters::KEY_PANEL_SIZE[] = "panel-size"; \
    const char CameraParameters::KEY_IS_SUPPORT_MZAF[] = "is-mzaf-supported"; \
    const char CameraParameters::KEY_MZAF_ENABLE[] = "mzaf-enable"; \
    const char CameraParameters::KEY_POST_VIEW_FMT[] = "post-view-fmt";

#define CAMERA_PARAMETERS_EXTRA_H \
    static const char PROPERTY_KEY_CLIENT_APPMODE[]; \
    static const char APP_MODE_NAME_DEFAULT[]; \
    static const char APP_MODE_NAME_MTK_ENG[]; \
    static const char APP_MODE_NAME_MTK_ATV[]; \
    static const char APP_MODE_NAME_MTK_STEREO[]; \
    static const char APP_MODE_NAME_MTK_VT[]; \
    static const char APP_MODE_NAME_MTK_PHOTO[]; \
    static const char APP_MODE_NAME_MTK_VIDEO[]; \
    static const char APP_MODE_NAME_MTK_ZSD[]; \
    static const char SCENE_MODE_NORMAL[]; \
    static const char KEY_FB_SMOOTH_LEVEL[]; \
    static const char KEY_FB_SMOOTH_LEVEL_MIN[]; \
    static const char KEY_FB_SMOOTH_LEVEL_MAX[]; \
    static const char KEY_FB_SMOOTH_LEVEL_Default[]; \
    static const char KEY_FB_SKIN_COLOR[]; \
    static const char KEY_FB_SKIN_COLOR_MIN[]; \
    static const char KEY_FB_SKIN_COLOR_MAX[]; \
    static const char KEY_FB_SKIN_COLOR_Default[]; \
    static const char KEY_FB_SHARP[]; \
    static const char KEY_FB_SHARP_MIN[]; \
    static const char KEY_FB_SHARP_MAX[]; \
    static const char KEY_FB_ENLARGE_EYE[]; \
    static const char KEY_FB_ENLARGE_EYE_MIN[]; \
    static const char KEY_FB_ENLARGE_EYE_MAX[]; \
    static const char KEY_FB_SLIM_FACE[]; \
    static const char KEY_FB_SLIM_FACE_MIN[]; \
    static const char KEY_FB_SLIM_FACE_MAX[]; \
    static const char KEY_FB_EXTREME_BEAUTY[]; \
    static const char KEY_FB_TOUCH_POS[]; \
    static const char KEY_FB_FACE_POS[]; \
    static const char KEY_FACE_BEAUTY[]; \
    static const char KEY_FB_EXTREME_SUPPORTED[]; \
    static const char KEY_FEATURE_MAX_FPS[]; \
    static const char KEY_VIDEO_FACE_BEAUTY_SUPPORTED[]; \
    static const char KEY_EXPOSURE[]; \
    static const char KEY_EXPOSURE_METER[]; \
    static const char KEY_ISO_SPEED[]; \
    static const char KEY_AE_MODE[]; \
    static const char KEY_FOCUS_METER[]; \
    static const char KEY_EDGE[]; \
    static const char KEY_HUE[]; \
    static const char KEY_SATURATION[]; \
    static const char KEY_BRIGHTNESS[]; \
    static const char KEY_CONTRAST[]; \
    static const char KEY_ZSD_MODE[]; \
    static const char KEY_SUPPORTED_ZSD_MODE[]; \
    static const char KEY_AWB2PASS[]; \
    static const char KEY_AF_LAMP_MODE []; \
    static const char KEY_STEREO_3D_PREVIEW_SIZE[]; \
    static const char KEY_STEREO_3D_PICTURE_SIZE[]; \
    static const char KEY_STEREO_3D_TYPE []; \
    static const char KEY_STEREO_3D_MODE []; \
    static const char KEY_STEREO_3D_IMAGE_FORMAT []; \
    static const char KEY_FPS_MODE[]; \
    static const char KEY_FOCUS_DRAW[]; \
    static const char KEY_CAPTURE_MODE[]; \
    static const char KEY_SUPPORTED_CAPTURE_MODES[]; \
    static const char KEY_CAPTURE_PATH[]; \
    static const char KEY_BURST_SHOT_NUM[]; \
    static const char KEY_MATV_PREVIEW_DELAY[]; \
    static const char KEY_PANORAMA_IDX[]; \
    static const char KEY_PANORAMA_DIR[]; \
    static const char KEY_SENSOR_DEV[]; \
    static const char KEY_SUPPORTED_SENSOR_DEVS[]; \
    static const char EXPOSURE_METER_SPOT[]; \
    static const char EXPOSURE_METER_CENTER[]; \
    static const char EXPOSURE_METER_AVERAGE[]; \
    static const char ISO_SPEED_AUTO[]; \
    static const char ISO_SPEED_100[]; \
    static const char ISO_SPEED_200[]; \
    static const char ISO_SPEED_400[]; \
    static const char ISO_SPEED_800[]; \
    static const char ISO_SPEED_1600[]; \
    static const char FOCUS_METER_SPOT[]; \
    static const char FOCUS_METER_MULTI[]; \
    static const char KEY_CAMERA_MODE[]; \
    static const int CAMERA_MODE_NORMAL; \
    static const int CAMERA_MODE_MTK_PRV; \
    static const int CAMERA_MODE_MTK_VDO; \
    static const int CAMERA_MODE_MTK_VT; \
    static const int FPS_MODE_NORMAL; \
    static const int FPS_MODE_FIX; \
    static const char CAPTURE_MODE_PANORAMA_SHOT[]; \
    static const char CAPTURE_MODE_BURST_SHOT[]; \
    static const char CAPTURE_MODE_NORMAL[]; \
    static const char CAPTURE_MODE_BEST_SHOT[]; \
    static const char CAPTURE_MODE_EV_BRACKET_SHOT[]; \
    static const char CAPTURE_MODE_SMILE_SHOT[]; \
    static const char CAPTURE_MODE_AUTO_PANORAMA_SHOT[]; \
    static const char CAPTURE_MODE_MOTION_TRACK_SHOT[]; \
    static const char CAPTURE_MODE_MAV_SHOT[]; \
    static const char CAPTURE_MODE_HDR_SHOT[]; \
    static const char CAPTURE_MODE_ASD_SHOT[]; \
    static const char CAPTURE_MODE_ZSD_SHOT[]; \
    static const char CAPTURE_MODE_PANO_3D[]; \
    static const char CAPTURE_MODE_SINGLE_3D[]; \
    static const char CAPTURE_MODE_FACE_BEAUTY[]; \
    static const char CAPTURE_MODE_CONTINUOUS_SHOT[]; \
    static const char CAPTURE_MODE_MULTI_MOTION[]; \
    static const char CAPTURE_MODE_GESTURE_SHOT[]; \
    static const char PANORAMA_DIR_RIGHT[]; \
    static const char PANORAMA_DIR_LEFT[]; \
    static const char PANORAMA_DIR_TOP[]; \
    static const char PANORAMA_DIR_DOWN[]; \
    static const int ENABLE; \
    static const int DISABLE; \
    static const char HIGH[]; \
    static const char MIDDLE[]; \
    static const char LOW[]; \
    static const char KEY_PREVIEW_INT_FORMAT[]; \
    static const char PIXEL_FORMAT_YUV420I[]; \
    static const char PIXEL_FORMAT_YV12_GPU[]; \
    static const char PIXEL_FORMAT_YUV422I_UYVY[]; \
    static const char PIXEL_FORMAT_YUV422I_VYUY[]; \
    static const char PIXEL_FORMAT_YUV422I_YVYU[]; \
    static const char PIXEL_FORMAT_BAYER8[]; \
    static const char PIXEL_FORMAT_BAYER10[]; \
    static const char PIXEL_FORMAT_BITSTREAM[]; \
    static const char PIXEL_FORMAT_YUV420SP_NV12[]; \
    static const char KEY_BRIGHTNESS_VALUE[]; \
    static const char KEY_ISP_MODE[]; \
    static const char KEY_AF_X[]; \
    static const char KEY_AF_Y[]; \
    static const char KEY_FOCUS_ENG_MAX_STEP[]; \
    static const char KEY_FOCUS_ENG_MIN_STEP[]; \
    static const char KEY_FOCUS_ENG_BEST_STEP[]; \
    static const char KEY_RAW_DUMP_FLAG[]; \
    static const char KEY_PREVIEW_DUMP_RESOLUTION[]; \
    static const int  PREVIEW_DUMP_RESOLUTION_NORMAL; \
    static const int  PREVIEW_DUMP_RESOLUTION_CROP; \
    static const char EFFECT_SEPIA_BLUE[]; \
    static const char EFFECT_SEPIA_GREEN[]; \
    static const char  EFFECT_NASHVILLE[]; \
    static const char  EFFECT_HEFE[]; \
    static const char  EFFECT_VALENCIA[]; \
    static const char  EFFECT_XPROII[]; \
    static const char  EFFECT_LOFI[]; \
    static const char  EFFECT_SIERRA[]; \
    static const char  EFFECT_KELVIN[]; \
    static const char  EFFECT_WALDEN[]; \
    static const char  EFFECT_F1977[]; \
    static const char WHITE_BALANCE_TUNGSTEN[]; \
    static const char ISO_SPEED_ENG[]; \
    static const char KEY_FOCUS_ENG_MODE[]; \
    static const char KEY_FOCUS_ENG_STEP[]; \
    static const char KEY_RAW_SAVE_MODE[]; \
    static const char KEY_RAW_PATH[]; \
    static const char KEY_FAST_CONTINUOUS_SHOT[]; \
    static const char KEY_VIDEO_HDR[]; \
    static const char KEY_VIDEO_HDR_MODE[]; \
    static const char VIDEO_HDR_MODE_IVHDR[]; \
    static const char VIDEO_HDR_MODE_MVHDR[]; \
    static const char VIDEO_HDR_MODE_ZVHDR[]; \
    static const char VIDEO_HDR_SIZE_DEVISOR[]; \
    static const char KEY_SINGLE_FRAME_CAPTURE_HDR_SUPPORTED[]; \
    static const char KEY_SUPPORT_MZAF_FEATURE[]; \
    static const char KEY_HDR_DETECTION_SUPPORTED[]; \
    static const char KEY_HDR_AUTO_MODE[]; \
    static const char KEY_HDR_MODE[]; \
    static const char HDR_MODE_OFF[]; \
    static const char HDR_MODE_ON[]; \
    static const char HDR_MODE_AUTO[]; \
    static const char HDR_MODE_VIDEO_ON[]; \
    static const char HDR_MODE_VIDEO_AUTO[]; \
    static const char KEY_MAX_NUM_DETECTED_OBJECT[]; \
    static const char KEY_HEARTBEAT_MONITOR[]; \
    static const char KEY_HEARTBEAT_MONITOR_SUPPORTED[]; \
    static const char KEY_CSHOT_INDICATOR[]; \
    static const char KEY_ENG_AE_ENABLE[]; \
    static const char KEY_ENG_PREVIEW_SHUTTER_SPEED[]; \
    static const char KEY_ENG_PREVIEW_SENSOR_GAIN[]; \
    static const char KEY_ENG_PREVIEW_ISP_GAIN[]; \
    static const char KEY_ENG_PREVIEW_AE_INDEX[]; \
    static const char KEY_ENG_PREVIEW_ISO[]; \
    static const char KEY_ENG_CAPTURE_SENSOR_GAIN[]; \
    static const char KEY_ENG_CAPTURE_ISP_GAIN[]; \
    static const char KEY_ENG_CAPTURE_SHUTTER_SPEED[]; \
    static const char KEY_ENG_CAPTURE_ISO[]; \
    static const char KEY_ENG_FLASH_DUTY_VALUE[]; \
    static const char KEY_ENG_FLASH_DUTY_MIN[]; \
    static const char KEY_ENG_FLASH_DUTY_MAX[]; \
    static const char KEY_ENG_ZSD_ENABLE[]; \
    static const char KEY_SENSOR_TYPE[]; \
    static const char KEY_ENG_PREVIEW_FPS[]; \
    static const char KEY_ENG_MSG[]; \
    static const int  KEY_ENG_FLASH_DUTY_DEFAULT_VALUE; \
    static const int  KEY_ENG_FLASH_STEP_DEFAULT_VALUE; \
    static const char KEY_ENG_FLASH_STEP_MIN[]; \
    static const char KEY_ENG_FLASH_STEP_MAX[]; \
    static const char KEY_ENG_FOCUS_FULLSCAN_FRAME_INTERVAL[]; \
    static const char KEY_ENG_FOCUS_FULLSCAN_FRAME_INTERVAL_MAX[]; \
    static const char KEY_ENG_FOCUS_FULLSCAN_FRAME_INTERVAL_MIN[]; \
    static const int  KEY_ENG_FOCUS_FULLSCAN_FRAME_INTERVAL_MAX_DEFAULT; \
    static const int  KEY_ENG_FOCUS_FULLSCAN_FRAME_INTERVAL_MIN_DEFAULT; \
    static const char KEY_ENG_FOCUS_FULLSCAN_DAC_STEP[]; \
    static const char KEY_ENG_PREVIEW_FRAME_INTERVAL_IN_US[]; \
    static const char KEY_ENG_PARAMETER1[]; \
    static const char KEY_ENG_PARAMETER2[]; \
    static const char KEY_ENG_PARAMETER3[]; \
    static const char KEY_ENG_RAW_OUTPUT_PORT[]; \
    static const int  KEY_ENG_RAW_IMGO; \
    static const int  KEY_ENG_RAW_RRZO; \
    static const char KEY_ENG_ISP_PROFILE[]; \
    static const int  KEY_ENG_ISP_PREVIEW; \
    static const int  KEY_ENG_ISP_CAPTURE; \
    static const int  KEY_ENG_ISP_VIDEO; \
    static const char KEY_ENG_EV_VALUE[]; \
    static const char KEY_ENG_EVB_ENABLE[]; \
    static const char KEY_ENG_3ADB_FLASH_ENABLE[]; \
    static const char KEY_ENG_SAVE_SHADING_TABLE[]; \
    static const char KEY_ENG_SHADING_TABLE[]; \
    static const int KEY_ENG_SHADING_TABLE_AUTO; \
    static const int KEY_ENG_SHADING_TABLE_LOW; \
    static const int KEY_ENG_SHADING_TABLE_MIDDLE; \
    static const int KEY_ENG_SHADING_TABLE_HIGH; \
    static const int KEY_ENG_SHADING_TABLE_TSF; \
    static const char KEY_VR_BUFFER_COUNT[]; \
    static const char KEY_ENG_EV_CALBRATION_OFFSET_VALUE[]; \
    static const char KEY_ENG_MFLL_SUPPORTED[]; \
    static const char KEY_ENG_MFLL_ENABLE[]; \
    static const char KEY_ENG_MFLL_PICTURE_COUNT[]; \
    static const char KEY_ENG_SENOSR_MODE_SLIM_VIDEO1_SUPPORTED[]; \
    static const char KEY_ENG_SENOSR_MODE_SLIM_VIDEO2_SUPPORTED[]; \
    static const char KEY_ENG_VIDEO_RAW_DUMP_RESIZE_TO_2M_SUPPORTED[]; \
    static const char KEY_ENG_VIDEO_RAW_DUMP_RESIZE_TO_4K2K_SUPPORTED[]; \
    static const char KEY_ENG_VIDEO_RAW_DUMP_CROP_CENTER_2M_SUPPORTED[]; \
    static const char KEY_ENG_VIDEO_RAW_DUMP_MANUAL_FRAME_RATE_SUPPORTED[]; \
    static const char KEY_ENG_VIDEO_RAW_DUMP_MANUAL_FRAME_RATE_ENABLE[]; \
    static const char KEY_ENG_VIDEO_RAW_DUMP_MANUAL_FRAME_RATE_MIN[]; \
    static const char KEY_ENG_VIDEO_RAW_DUMP_MANUAL_FRAME_RATE_MAX[]; \
    static const char KEY_ENG_VIDEO_RAW_DUMP_MANUAL_FRAME_RATE_RANGE_LOW[]; \
    static const char KEY_ENG_VIDEO_RAW_DUMP_MANUAL_FRAME_RATE_RANGE_HIGH[]; \
    static const char KEY_ENG_VIDEO_RAW_DUMP_RESIZE[]; \
    static const char KEY_ENG_VIDEO_RAW_DUMP_SUPPORTED[]; \
    static const char KEY_ENG_MTK_AWB_SUPPORTED[]; \
    static const char KEY_ENG_SENSOR_AWB_SUPPORTED[]; \
    static const char KEY_ENG_MTK_AWB_ENABLE[]; \
    static const char KEY_ENG_SENSOR_AWB_ENABLE[]; \
    static const char KEY_ENG_MTK_SHADING_SUPPORTED[]; \
    static const char KEY_ENG_MTK_1to3_SHADING_SUPPORTED[]; \
    static const char KEY_ENG_SENSOR_SHADNING_SUPPORTED[]; \
    static const char KEY_ENG_MTK_SHADING_ENABLE[]; \
    static const char KEY_ENG_MTK_1to3_SHADING_ENABLE[]; \
    static const char KEY_ENG_SENSOR_SHADNING_ENABLE[]; \
    static const char KEY_ENG_MANUAL_MULTI_NR_SUPPORTED[]; \
    static const char KEY_ENG_MANUAL_MULTI_NR_ENABLE[]; \
    static const char KEY_ENG_MANUAL_MULTI_NR_TYPE[]; \
    static const char KEY_ENG_VIDEO_HDR_SUPPORTED[]; \
    static const char KEY_ENG_VIDEO_HDR_MODE[]; \
    static const char KEY_ENG_VIDEO_HDR_RATIO[]; \
    static const char KEY_HSVR_PRV_SIZE[]; \
    static const char KEY_SUPPORTED_HSVR_PRV_SIZE[]; \
    static const char KEY_HSVR_PRV_FPS[]; \
    static const char KEY_SUPPORTED_HSVR_PRV_FPS[]; \
    static const char KEY_HSVR_SIZE_FPS[]; \
    static const char KEY_SUPPORTED_HSVR_SIZE_FPS[]; \
    static const char KEY_MFB_MODE[]; \
    static const char KEY_MFB_MODE_MFLL[]; \
    static const char KEY_MFB_MODE_AIS[]; \
    static const char KEY_PIP_MAX_FRAME_RATE_ZSD_ON[]; \
    static const char KEY_PIP_MAX_FRAME_RATE_ZSD_OFF[]; \
    static const char KEY_DYNAMIC_FRAME_RATE[]; \
    static const char KEY_DYNAMIC_FRAME_RATE_SUPPORTED[]; \
    static const char KEY_STEREO_REFOCUS_MODE[]; \
    static const char KEY_STEREO_CAPTURE_MODE[]; \
    static const char KEY_STEREO_DEPTHAF_MODE[]; \
    static const char KEY_STEREO_DISTANCE_MODE[]; \
    static const char KEY_STEREO_PICTURE_SIZE[]; \
    static const char KEY_SUPPORTED_STEREO_PICTURE_SIZE[]; \
    static const char KEY_REFOCUS_PICTURE_SIZE[]; \
    static const char KEY_SUPPORTED_REFOCUS_PICTURE_SIZE[]; \
    static const char KEY_STEREO_PREVIEW_FRAME_RATE[]; \
    static const char KEY_STEREO_CAPTURE_FRAME_RATE[]; \
    static const char KEY_STEREO_SENSOR_INDEX_MAIN[]; \
    static const char KEY_STEREO_SENSOR_INDEX_MAIN2[]; \
    static const char KEY_STEREO_CAPTURE_SUPPORTED_MODULE[]; \
    static const char KEY_STEREO_VSDOF_MODE[]; \
    static const char KEY_STEREO_DOF_LEVEL[]; \
    static const char KEY_STEREO_SUPPORTED_DOF_LEVEL[]; \
    static const char KEY_STEREO_RESULT_DOF_LEVEL[]; \
    static const char KEY_STEREO_VSDOF_SUPPORTED_MODULE[]; \
    static const char KEY_STEREO_TOUCH_POSITION[]; \
    static const char KEY_STEREO_DENOISE_MODE[]; \
    static const char KEY_STEREO_DENOISE_SUPPORTED_MODULE[]; \
    static const char KEY_STEREO_3RDPARTY_MODE[]; \
    static const char KEY_STEREO_3RDPARTY_SUPPORTED_MODULE[]; \
    static const char KEY_STEREO_PREVIEW_ENABLE[]; \
    static const char KEY_DUALCAM_CAPTURE_MODE[]; \
    static const char KEY_REFOCUS_JPS_FILE_NAME[]; \
    static const char KEY_3DNR_MODE[]; \
    static const char KEY_3DNR_QUALITY_SUPPORTED[]; \
    static const char KEY_EIS_SUPPORTED_FRAMES[]; \
    static const char KEY_EIS25_MODE[]; \
    static const char KEY_ENG_MANUAL_SHUTTER_SPEED []; \
    static const char KEY_ENG_MANUAL_SENSOR_GAIN[]; \
    static const char KEY_ENG_FLASH_CALIBRATION[]; \
    static const char KEY_ENG_SENOSR_MODE_SUPPORTED[]; \
    static const char KEY_GESTURE_SHOT[]; \
    static const char KEY_GESTURE_SHOT_SUPPORTED[]; \
    static const char KEY_NATIVE_PIP[]; \
    static const char KEY_NATIVE_PIP_SUPPORTED[]; \
    static const char KEY_PDAF[]; \
    static const char KEY_PDAF_SUPPORTED[]; \
    static const char KEY_FIRST_PREVIEW_FRAME_BLACK[]; \
    static const char KEY_DNG_SUPPORTED[]; \
    static const char KEY_DISPLAY_ROTATION_SUPPORTED[]; \
    static const char KEY_PANEL_SIZE[]; \
    static const char KEY_IS_SUPPORT_MZAF[]; \
    static const char KEY_MZAF_ENABLE[]; \
    static const char KEY_POST_VIEW_FMT[]; \
    static const char ON[]; \
    static const char OFF[]; \
    static const char REAR[]; \
    static const char FRONT[];
