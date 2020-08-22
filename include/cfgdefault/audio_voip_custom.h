/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein is
 * confidential and proprietary to MediaTek Inc. and/or its licensors. Without
 * the prior written permission of MediaTek inc. and/or its licensors, any
 * reproduction, modification, use or disclosure of MediaTek Software, and
 * information contained herein, in whole or in part, shall be strictly
 * prohibited.
 *
 * MediaTek Inc. (C) 2010. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER
 * ON AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL
 * WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR
 * NONINFRINGEMENT. NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH
 * RESPECT TO THE SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY,
 * INCORPORATED IN, OR SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES
 * TO LOOK ONLY TO SUCH THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO.
 * RECEIVER EXPRESSLY ACKNOWLEDGES THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO
 * OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES CONTAINED IN MEDIATEK
 * SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE
 * RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S
 * ENTIRE AND CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE
 * RELEASED HEREUNDER WILL BE, AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE
 * MEDIATEK SOFTWARE AT ISSUE, OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE
 * CHARGE PAID BY RECEIVER TO MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek
 * Software") have been modified by MediaTek Inc. All revisions are subject to
 * any receiver's applicable license agreements with MediaTek Inc.
 */

#ifndef AUDIO_VOIP_CUSTOM_H
#define AUDIO_VOIP_CUSTOM_H

/****************************************************
* Define default AP side VOIP parameters
*****************************************************/

//VoIP speech parameters common part
#define DEFAULT_VOIP_SPEECH_COMMON_PARAM  \
    0,  55997,  31000,    10752,      32769,      0,      0,      0, \
    0,      0,      0,      0


#ifdef __MTK_DUAL_MIC_SUPPORT__
#ifdef __MTK_VOIP_NORMAL_DMNR__
#define VOIP_SPEECH_MODE_PARA13 (371)
#define VOIP_SPEECH_MODE_PARA14 (23)
#define VOIP_SPEECH_MODE_PARA03 (29)
#define VOIP_SPEECH_MODE_PARA08 (400)
#else
#define VOIP_SPEECH_MODE_PARA13 (0)
#define VOIP_SPEECH_MODE_PARA14 (0)
#define VOIP_SPEECH_MODE_PARA03 (31)
#define VOIP_SPEECH_MODE_PARA08 (80)
#endif
#else
#define VOIP_SPEECH_MODE_PARA13 (0)
#define VOIP_SPEECH_MODE_PARA14 (0)
#define VOIP_SPEECH_MODE_PARA03 (31)
#define VOIP_SPEECH_MODE_PARA08 (80)
#endif

#ifdef __MTK_DUAL_MIC_SUPPORT__
#ifdef __MTK_VOIP_HANDSFREE_DMNR__
#define VOIP_SPEECH_SPK_MODE_PARA13 (307)
#define VOIP_SPEECH_SPK_MODE_PARA14 (31)
#define VOIP_SPEECH_SPK_MODE_PARA03 (29)
#define VOIP_SPEECH_SPK_MODE_PARA08 (400)      
#else
#define VOIP_SPEECH_SPK_MODE_PARA13 (0)
#define VOIP_SPEECH_SPK_MODE_PARA14 (0)
#define VOIP_SPEECH_SPK_MODE_PARA03 (29)
#define VOIP_SPEECH_SPK_MODE_PARA08 (276)  
#endif    
#else
#define VOIP_SPEECH_SPK_MODE_PARA13 (0)
#define VOIP_SPEECH_SPK_MODE_PARA14 (0)
#define VOIP_SPEECH_SPK_MODE_PARA03 (29)
#define VOIP_SPEECH_SPK_MODE_PARA08 (276)
#endif


//VoIP speech parameter different part
//1. normal mode
//2.loud speaker mode
//3. headset mode
//4.BT mode
#define DEFAULT_VOIP_SPEECH_MODE_PARAM \
    128,   253, 6212,    VOIP_SPEECH_MODE_PARA03, 57351,   31,    0,    32, \
    VOIP_SPEECH_MODE_PARA08,  197,  611,     0, 13066,   0|VOIP_SPEECH_MODE_PARA13,    0|VOIP_SPEECH_MODE_PARA14,   0, \
    \
    192,   224,  2218,    VOIP_SPEECH_SPK_MODE_PARA03, 57351, 24607,    0,     4, \
    VOIP_SPEECH_SPK_MODE_PARA08,  197,   611,     0, 13066,     VOIP_SPEECH_SPK_MODE_PARA13,     VOIP_SPEECH_SPK_MODE_PARA14,     0, \
    \
    0,   189,  8196,    31, 57351,    31,      0,    64, \
    80,  197,   611,     0, 13066,     0,     0,     0, \
    \
    0,   253,  8196,    31, 53255,    31,      0,     0, \
    80,  197,   611,     0, 13066,    0,     0,      0

//VoIP FIR parameter
//1. normal mode
//2.loud speaker mode
//3. headset mode
//4.BT mode
#define DEFAULT_VOIP_IN_FIR_PARAM \
    32767,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0,  \
    \
    32767,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0,  \
    \
    32767,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0,  \
    \
    32767,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0

//VoIP FIR parameter
//1. normal mode
//2.loud speaker mode
//3. headset mode
//4.BT mode
#define DEFAULT_VOIP_OUT_FIR_PARAM \
    32767,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0,  \
    \
    32767,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0,  \
    \
    32767,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0,  \
    \
    32767,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0

#endif
