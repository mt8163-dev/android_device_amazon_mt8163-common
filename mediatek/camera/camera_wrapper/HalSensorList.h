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

#ifndef _MTK_PLATFORM_HARDWARE_MTKCAM_HAL_SENSOR_HALSENSORLIST_H_
#define _MTK_PLATFORM_HARDWARE_MTKCAM_HAL_SENSOR_HALSENSORLIST_H_
//
#include "sensor_drv.h"
#include "IHalSensor.h"

extern NSCam::SensorStaticInfo sensorStaticInfo[3];



/******************************************************************************
 *
 ******************************************************************************/
namespace NSCam {
namespace NSHalSensor {

/******************************************************************************
 *
 ******************************************************************************/
class HalSensor;


/******************************************************************************
 *
 ******************************************************************************/

typedef struct {
    MUINT u4BitDepth;
    MUINT u4IsPacked;
    MUINT u1Order;
    MUINT sensorType;
}SENSOR_HAL_RAW_INFO_STRUCT;

typedef struct {
    MUINT TM_DummyPixel;
    MUINT TM_Vsync;
    MUINT TM_Line;
    MUINT TM_Pixel;
    MUINT TM_PAT;
    MUINT TM_FMT;
}SENSOR_HAL_TEST_MODEL_STRUCT;

 typedef struct {
    MUINT scenarioId;
    MUINT u1IsContinuous;
    MUINT u1IsBypassSensorScenario;
    MUINT u1HsyncPol;
    MUINT u1VsyncPol;
    MUINT u4PixelX0;
    MUINT u4PixelX1;
    MUINT u4PixelY0;
    MUINT u4PixelY1;
    /*
        PAD2CAM_DATA_ENUM padSel;
        TG_FORMAT_ENUM inDataType;
        SENSOR_DATA_BITS_ENUM senInLsb;
        SENINF_SOURCE_ENUM inSrcTypeSel;
    */
    MUINT padSel;
    MUINT inDataType;
    MUINT senInLsb;
    MUINT inSrcTypeSel;
    MUINT u1VirtualNo;
    MUINT u1IsIHDR;
    MUINT u1MIPIDataTermDelay;
    MUINT u1MIPIDataSettleDelay;
    MUINT u1MIPIClkTermDelay;
    MUINT u1MIPILaneNum;
    MUINT u1MIPIPacketECCOrder;
    MUINT cropWidth;
    MUINT cropHeight;
    MUINT frameRate;
    MUINT mclkSrc;
    MUINT mipiPad;
    MUINT twopixelOn;
    MUINT debugMode;
    MUINT HDRMode;
    MUINT MIPI_OPHY_TYPE; // 0: NCSI2 , 1:CSI2
    MUINT NCSI2_HSRXDET_MODE; // 0: Enable HS Detect, 1: disable HS Detect
}SENSOR_CONFIG_STRUCT;

/******************************************************************************
 *  Hal Sensor List.
 ******************************************************************************/
class HalSensorList;

/******************************************************************************
 *
 ******************************************************************************/
};  //namespace NSHalSensor
};  //namespace NSCam
#endif  //_MTK_PLATFORM_HARDWARE_MTKCAM_HAL_SENSOR_HALSENSORLIST_H_

