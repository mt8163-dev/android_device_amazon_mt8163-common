/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 */
/* MediaTek Inc. (C) 2010. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
 * AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 * NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 * SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 * SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
 * THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
 * THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
 * CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
 * SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
 * CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 * AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
 * MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek Software")
 * have been modified by MediaTek Inc. All revisions are subject to any receiver's
 * applicable license agreements with MediaTek Inc.
 */

/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 *
 * Filename:
 * ---------
 *
 *
 * Project:
 * --------
 *   ALPS
 *
 * Description:
 * ------------
 *
 * Author:
 * -------
 * ChiPeng
 *
 *------------------------------------------------------------------------------
 * $Revision:$ 1.0.0
 * $Modtime:$
 * $Log:$
 *
 * 06 26 2010 chipeng.chang
 * [ALPS00002705][Need Patch] [Volunteer Patch] ALPS.10X.W10.11 Volunteer patch for speech parameter 
 * modify speech parameters.
 *
 * Mar 15 2010 mtk02308
 * [ALPS] Init Custom parameter
 *
 *

 *
 *
 *******************************************************************************/
#ifndef SPEECH_COEFF_DEFAULT_H
#define SPEECH_COEFF_DEFAULT_H

#ifndef FALSE
#define FALSE 0
#endif

//speech parameter depen on BT_CHIP cersion
#if defined(MTK_MT6611)

#define BT_COMP_FILTER (1 << 15)
#define BT_SYNC_DELAY  86

#elif defined(MTK_MT6612)

#define BT_COMP_FILTER (1 << 15)
#define BT_SYNC_DELAY  86

#elif defined(MTK_MT6616) || defined(MTK_MT6620) || defined(MTK_MT6622) || defined(MTK_MT6626) || defined(MTK_MT6628)

#define BT_COMP_FILTER (1 << 15)
#define BT_SYNC_DELAY  86

#else // MTK_MT6620

#define BT_COMP_FILTER (0 << 15)
#define BT_SYNC_DELAY  86

#endif

#ifdef __MTK_DUAL_MIC_SUPPORT__

  #ifndef MTK_INTERNAL
  #define SPEECH_MODE_PARA13 (371)
  #define SPEECH_MODE_PARA14 (23)
  #define SPEECH_MODE_PARA03 (29)
  #define SPEECH_MODE_PARA08 (400)
  #else
  #define SPEECH_MODE_PARA13 (0)
  #define SPEECH_MODE_PARA14 (0)
  #define SPEECH_MODE_PARA03 (31)
  #define SPEECH_MODE_PARA08 (80)
  #endif

#else
#define SPEECH_MODE_PARA13 (0)
#define SPEECH_MODE_PARA14 (0)
#define SPEECH_MODE_PARA03 (31)
#define SPEECH_MODE_PARA08 (80)


#endif

#if (defined(__NXP_SMARTPA_SUPPORT__) || defined(__MTK_SPEAKER_MONITOR_SUPPORT__))
	#define MANUAL_CLIPPING (1 << 15)
	#define NXP_DELAY_REF   (1 << 6)
	#define PRE_CLIPPING_LEVEL 32767
#else
	#define MANUAL_CLIPPING (0 << 15)
	#define NXP_DELAY_REF   (0 << 6) 
	#define PRE_CLIPPING_LEVEL 10752
#endif



#define DEFAULT_SPEECH_NORMAL_MODE_PARA \
   96,   253,  16388,     SPEECH_MODE_PARA03,   57351,     799,   400,     64, \
   SPEECH_MODE_PARA08,  4325,      611,       0,   20488,      0|SPEECH_MODE_PARA13,     0|SPEECH_MODE_PARA14,  8192

#define DEFAULT_SPEECH_EARPHONE_MODE_PARA \
    0,        189,  10756,      31,   57351,     31,   400,     64, \
    80,  4325,    611,     0, 20488,     0,     0,     0  

#define DEFAULT_SPEECH_BT_EARPHONE_MODE_PARA \
     0,   253, 10756,    31, 53255,  31,   400,     0, \
    80,  4325,    611,     0, 20488 | BT_COMP_FILTER,  0,     0,     BT_SYNC_DELAY

#define DEFAULT_SPEECH_LOUDSPK_MODE_PARA \
    96|MANUAL_CLIPPING ,   224,  5256,    31, 57351, 24607,   400,   132, \
    84,  4325,    611,     0, 20488|NXP_DELAY_REF,     0,     0,     0

#define DEFAULT_SPEECH_CARKIT_MODE_PARA \
    96,   224,  5256,    31, 57351, 24607,   400,   132, \
    84,  4325,    611,     0, 20488,        0,     0,     0

#define DEFAULT_SPEECH_BT_CORDLESS_MODE_PARA \
     0,   479, 10756,    28, 53255,  31,   400,     0, \
    4048,  4325,    611,     0, 20488 | BT_COMP_FILTER,  0,     0,     BT_SYNC_DELAY

#define DEFAULT_SPEECH_AUX1_MODE_PARA \
    0,      0,      0,      0,      0,      0,      0,      0, \
    0,      0,      0,      0,      0,      0,      0,      0

#define DEFAULT_SPEECH_AUX2_MODE_PARA \
    0,      0,      0,      0,      0,      0,      0,      0, \
    0,      0,      0,      0,      0,      0,      0,      0

#define DEFAULT_SPEECH_VOICE_TRACKING_MODE_PARA \
    96|MANUAL_CLIPPING ,   224,  5256,    31, 57351, 24607,   400,   132, \
    84,  4325,    611,     0, 8200|NXP_DELAY_REF,     883,     23,     0

#define DEFAULT_SPEECH_HAC_MODE_PARA \
   96,   253,  16388,     SPEECH_MODE_PARA03,   57351,     799,   400,     64, \
   SPEECH_MODE_PARA08,  4325,      611,       0,   20488,      0|SPEECH_MODE_PARA13,     0|SPEECH_MODE_PARA14,  8192
#define DEFAULT_SPEECH_COMMON_PARA \
    0,  55997,  31000,    PRE_CLIPPING_LEVEL,      32769,      0,      0,      0, \
    0,      0,      0,      0

#define DEFAULT_SPEECH_VOL_PARA \
    0,      0,      0,      0

#define DEFAULT_AUDIO_DEBUG_INFO \
    0,      0,      0,      0,      0,      0,      0,      0, \
    0,      0,      0,      0,      0,      0,      0,      0

#define DEFAULT_VM_SUPPORT  FALSE

#define DEFAULT_AUTO_VM     FALSE

#define MICBAIS     1900

#define DEFAULT_WB_SPEECH_NORMAL_MODE_PARA \
    96,   253, 16388,    SPEECH_MODE_PARA03, 57607,    799,   400,     64, \
    SPEECH_MODE_PARA08,  4325,   611,     0,  16392,    0|SPEECH_MODE_PARA13,     0|SPEECH_MODE_PARA14,  8192  

#define DEFAULT_WB_SPEECH_EARPHONE_MODE_PARA \
     0,   189, 10756,    31, 57607,     31,  400,     64, \
    80,  4325,   611,     0,  16392,     0,     0,     0  

#define DEFAULT_WB_SPEECH_BT_EARPHONE_MODE_PARA \
     0,   253, 10756,    31, 53511,  31,   400,     0, \
    80,  4325,   611,     0,  16392 | BT_COMP_FILTER,  0,     0, BT_SYNC_DELAY  

#define DEFAULT_WB_SPEECH_LOUDSPK_MODE_PARA \
    96|MANUAL_CLIPPING,   224,  5256,    31, 57607, 24607,   400,   132, \
    84,  4325,   611,     0,  16392|NXP_DELAY_REF,     0,     0,     0  

#define DEFAULT_WB_SPEECH_CARKIT_MODE_PARA \
    96,   224,  5256,    31, 57607, 24607,   400,   132, \
    84,  4325,   611,     0,  16392,     0,     0,     0  

#define DEFAULT_WB_SPEECH_BT_CORDLESS_MODE_PARA \
     0,   479, 10756,    28, 53511,  31,   400,     0, \
    4048,  4325,   611,     0,  16392 | BT_COMP_FILTER,  0,     0, BT_SYNC_DELAY  

#define DEFAULT_WB_SPEECH_AUX1_MODE_PARA \
    96,   224,  5256,    31, 57607,     0,   400,     0,  4112,  4325,    11,     0,     0,     0,     0,     0 

#define DEFAULT_WB_SPEECH_AUX2_MODE_PARA \
    0,      0,     0,     0,       0,     0,     0,     0, \
    0,      0,     0,     0,       0,     0,     0,     0  

#define DEFAULT_WB_SPEECH_VOICE_TRACKING_MODE_PARA \
    96|MANUAL_CLIPPING,   224,  5256,    31, 57607, 24607,   400,   132, \
    84,  4325,   611,     0,  8200|NXP_DELAY_REF,     883,     23,     0  

#define DEFAULT_WB_SPEECH_HAC_MODE_PARA \
    96,   253, 16388,    SPEECH_MODE_PARA03, 57607,    799,   400,     64, \
    SPEECH_MODE_PARA08,  4325,   611,     0,  16392,    0|SPEECH_MODE_PARA13,     0|SPEECH_MODE_PARA14,  8192  

/* The Bluetooth PCM digital volume */
/* default_bt_pcm_in_vol : uplink, only for enlarge volume,
                           0x100 : 0dB  gain
                           0x200 : 6dB  gain
                           0x300 : 9dB  gain
                           0x400 : 12dB gain
                           0x800 : 18dB gain
                           0xF00 : 24dB gain             */
#define DEFAULT_BT_PCM_IN_VOL        0x100
/* default_bt_pcm_out_vol : downlink gain,
                           0x1000 : 0dB; maximum 0x7FFF  */
#define DEFAULT_BT_PCM_OUT_VOL       0x1000


#endif
