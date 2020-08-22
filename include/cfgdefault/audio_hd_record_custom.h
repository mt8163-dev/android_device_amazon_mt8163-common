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
 * aud_hd_record_custom.h
 *
 * Project:
 * --------
 *   ALPS
 *
 * Description:
 * ------------
 * This file is the header of audio customization related function or definition.
 *
 * Author:
 * -------
 * Charlie Lu.
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by CC/CQ. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision:$
 * $Modtime:$
 * $Log:$
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by CC/CQ. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef AUDIO_HD_RECORD_CUSTOM_H
#define AUDIO_HD_RECORD_CUSTOM_H

//hd_rec_fir
/* 0: Input FIR coefficients for Normal mode */
/* 1: Input FIR coefficients for Headset mode */
/* 2: Input FIR coefficients for Handfree mode */
/* 3: Input FIR coefficients for BT mode */
/* 4: Input FIR coefficients for Normal mode */
/* 5: Input FIR coefficients for Handfree mode */
/* 6: Input FIR coefficients for Normal mode 2nd Mic*/
/* 7: Input FIR coefficients for Voice Recognition*/
/* 8: Input FIR coefficients for Voice Unlock Main Mic */
/* 9: Input FIR coefficients for Voice Unlock 2nd Mic */
/* 10: Input FIR coefficients for 1st customization Main Mic*/
/* 11: Input FIR coefficients for 1st customization 2nd Mic*/
/* 12: Input FIR coefficients for 2nd customization Main Mic*/
/* 13: Input FIR coefficients for 2nd customization 2nd Mic*/
/* 14: Input FIR coefficients for 3rd customization Main Mic*/
/* 15: Input FIR coefficients for 3rd customization Ref Mic*/

#define DEFAULT_HD_RECORD_FIR_Coeff \
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
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    \
    32767,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
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
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
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
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    \
    32767,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
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


#define DEFAULT_HD_RECORD_MODE_FIR_MAPPING_CH1 \
    7, 4, \
    0, 1, \
    0, 1, \
    0, 1, \
    0, 1, \
    0, 1, \
    8, 1, \
    10, 1, \
    12, 1, \
    14, 1, \
    0, 1, \
    0, 1, \
    0, 1, \
    0, 1, \
    0, 3

#define DEFAULT_HD_RECORD_MODE_FIR_MAPPING_CH2 \
    6, 6, \
    6, 6, \
    6, 6, \
    6, 6, \
    6, 6, \
    6, 6, \
    9, 6, \
    11, 6, \
    13, 6, \
    15, 6, \
    6, 6, \
    6, 6, \
    6, 6, \
    6, 6, \
    6, 3

#endif
