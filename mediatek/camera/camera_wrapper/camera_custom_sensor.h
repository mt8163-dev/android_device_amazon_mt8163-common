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

/********************************************************************************************
 *     LEGAL DISCLAIMER
 *
 *     (Header of MediaTek Software/Firmware Release or Documentation)
 *
 *     BY OPENING OR USING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 *     THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE") RECEIVED
 *     FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON AN "AS-IS" BASIS
 *     ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES, EXPRESS OR IMPLIED,
 *     INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR
 *     A PARTICULAR PURPOSE OR NONINFRINGEMENT. NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY
 *     WHATSOEVER WITH RESPECT TO THE SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY,
 *     INCORPORATED IN, OR SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK
 *     ONLY TO SUCH THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
 *     NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S SPECIFICATION
 *     OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
 *
 *     BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE LIABILITY WITH
 *     RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE, AT MEDIATEK'S OPTION,
TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE, OR REFUND ANY SOFTWARE LICENSE
 *     FEES OR SERVICE CHARGE PAID BY BUYER TO MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 *     THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE WITH THE LAWS
 *     OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF LAWS PRINCIPLES.
 ************************************************************************************************/
#ifndef _CAMERA_CUSTOM_SENSOR_H_
#define _CAMERA_CUSTOM_SENSOR_H_

//#include "camera_custom_types.h"
//#include "camera_custom_nvram.h"

#ifndef __unused
#define __unused  __attribute__((__unused__))
#endif

typedef enum
{
    CAMERA_DATA_TYPE_START=0,
    CAMERA_NVRAM_DATA_ISP = CAMERA_DATA_TYPE_START,
    CAMERA_NVRAM_DATA_3A,
    CAMERA_NVRAM_DATA_SHADING,
    CAMERA_NVRAM_DATA_LENS,
    CAMERA_DATA_AE_PLINETABLE,
    CAMERA_NVRAM_DATA_STROBE,
    CAMERA_DATA_TSF_TABLE,
    CAMERA_NVRAM_DATA_GEOMETRY,
    CAMERA_NVRAM_DATA_FEATURE,
    CAMERA_NVRAM_VERSION,
    CAMERA_DATA_TYPE_NUM
} CAMERA_DATA_TYPE_ENUM;

namespace NSFeature
{


struct FeatureInfoProvider;
class SensorInfoBase
{
public:     ////            Feature Type.
                            typedef enum
                            {
                                EType_RAW =   0,  //  RAW Sensor
                                EType_YUV,        //  YUV Sensor
                            }   EType;
                        
                            typedef NSFeature::FeatureInfoProvider FeatureInfoProvider_T;

public:
    virtual                 ~SensorInfoBase(){}

public:     ////            Interface.
    virtual MBOOL           GetFeatureProvider(FeatureInfoProvider_T& rFInfoProvider __unused) { return false; }
    virtual EType           GetType() const                                 = 0;
    virtual MUINT32         GetID()   const                                 = 0;
    virtual char const*     getDrvName() const                              = 0;
    virtual char const*     getDrvMacroName() const                         = 0;
};


template <SensorInfoBase::EType _sensor_type, MUINT32 _sensor_id>
class SensorInfo : public SensorInfoBase
{
public:     ////
    typedef SensorInfo<_sensor_type, _sensor_id>    SensorInfo_T;
public:     ////            Interface.
    virtual EType           GetType() const { return _sensor_type; }
    virtual MUINT32         GetID()   const { return _sensor_id;   }
                            //
    virtual char const*     getDrvName() const      { return mpszDrvName; }
    virtual char const*     getDrvMacroName() const { return mpszDrvMacroName; }
public:     ////            Implementation.
                            SensorInfo()
                                : mpszDrvName(0), mpszDrvMacroName(0)
                            {
                            }
protected:  ////            Data Members.
    char const*             mpszDrvName;
    char const*             mpszDrvMacroName;
};


template <MUINT32 _sensor_id>
class YUVSensorInfo : public SensorInfo<SensorInfoBase::EType_YUV, _sensor_id>
{
    typedef YUVSensorInfo<_sensor_id>   SensorInfo_T;
public:     ////            Interface.
    static  SensorInfo_T*   createInstance(char const* pszDrvName = "", char const* pszDrvMacroName = "")
                            {
                                getInstance()->mpszDrvName      = pszDrvName;;
                                getInstance()->mpszDrvMacroName = pszDrvMacroName;
                                return  getInstance();
                            }
    static  SensorInfo_T*   getInstance() { static SensorInfo_T inst; return &inst; }
    static  MUINT32         getDefaultData(CAMERA_DATA_TYPE_ENUM const CameraDataType __unused,
					MVOID*const pDataBuf __unused, MUINT32 const size __unused)
                            {
                                return  -1;
                            }
                            //
    typedef SensorInfoBase::FeatureInfoProvider_T FeatureInfoProvider_T;
    virtual MBOOL           GetFeatureProvider(FeatureInfoProvider_T& rFInfoProvider __unused) { return false; }

    static  MUINT32			getNullFlickerPara(MINT32 sensorMode __unused, MVOID*const pDataBuf __unused)
    						{
    							return  -1;
    						}
protected:  ////            Implementation.
    virtual MUINT32         impGetDefaultData(CAMERA_DATA_TYPE_ENUM const CameraDataType __unused,
					MVOID*const pDataBuf __unused, MUINT32 const size __unused) const { return  -1; }
    static  SensorInfoBase* GetInstance();
};


template <MUINT32 _sensor_id>
class RAWSensorInfo : public SensorInfo<SensorInfoBase::EType_RAW, _sensor_id>
{
    typedef RAWSensorInfo<_sensor_id>   SensorInfo_T;
public:     ////            Interface.
    static  SensorInfo_T*   createInstance(char const* pszDrvName = "", char const* pszDrvMacroName = "")
                            {
                                getInstance()->mpszDrvName      = pszDrvName;;
                                getInstance()->mpszDrvMacroName = pszDrvMacroName;
                                return  getInstance();
                            }
    static  SensorInfo_T*   getInstance() { static SensorInfo_T inst; return &inst; }
    static  MUINT32         getDefaultData(CAMERA_DATA_TYPE_ENUM const CameraDataType, MVOID*const pDataBuf, MUINT32 const size)
                            {
                                return  getInstance()->impGetDefaultData(CameraDataType, pDataBuf, size);
                            }

	static  MUINT32         getFlickerPara(MINT32 sensorMode, MVOID*const pDataBuf)
                            {
                                return  getInstance()->impGetFlickerPara(sensorMode, pDataBuf);
                            }
protected:  ////            Implementation.
    virtual MUINT32         impGetDefaultData(CAMERA_DATA_TYPE_ENUM const CameraDataType, MVOID*const pDataBuf, MUINT32 const size) const;
    virtual MUINT32         impGetFlickerPara(MINT32 sensorMode, MVOID*const pDataBuf) const;

};


};  //  NSFeature


typedef struct
{
    MUINT32 SensorId;
    MUINT8  drvname[32];
    NSFeature::SensorInfoBase* pSensorInfo;
    NSFeature::SensorInfoBase* (*pfGetSensorInfoInstance)();
    MUINT32 (*getCameraDefault)(CAMERA_DATA_TYPE_ENUM CameraDataType, MVOID *pDataBuf, MUINT32 size);
    MUINT32 (*getCameraCalData)(MUINT32* pGetCalData);
    MUINT32 (*getCameraFlickerPara)(MINT32 sensorMode, MVOID *pDataBuf);
} MSDK_SENSOR_INIT_FUNCTION_STRUCT, *PMSDK_SENSOR_INIT_FUNCTION_STRUCT;

MUINT32 GetSensorInitFuncList(MSDK_SENSOR_INIT_FUNCTION_STRUCT **ppSensorList);


#endif  //  _CAMERA_CUSTOM_SENSOR_H_

