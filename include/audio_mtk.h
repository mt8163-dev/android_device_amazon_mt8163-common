/*
 * Copyright (C) 2011 The Android Open Source Project
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


#ifndef ANDROID_AUDIO_HAL_INTERFACE_MTK_H
#define ANDROID_AUDIO_HAL_INTERFACE_MTK_H

struct audio_hw_device_mtk: audio_hw_device{

    int (*SetEMParameter)(struct audio_hw_device *dev,void *ptr , int len);
    int (*GetEMParameter)(struct audio_hw_device *dev,void *ptr , int len);
    int (*SetAudioCommand)(struct audio_hw_device *dev,int par1 , int par2);
    int (*GetAudioCommand)(struct audio_hw_device *dev,int par1);
    int (*SetAudioData)(struct audio_hw_device *dev,int par1,size_t len,void *ptr);
    int (*GetAudioData)(struct audio_hw_device *dev,int par1,size_t len,void *ptr);
};
typedef struct audio_hw_device_mtk audio_hw_device_mtk_t;

#endif  // ANDROID_AUDIO_HAL_INTERFACE_MTK_H
