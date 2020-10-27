/*
 * Copyright (C) 2020 The CyanogenMod Project
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

#include <stdlib.h>
#include <stdint.h>
#include <media/IMediaSource.h>
#include <cutils/log.h>
#include <string.h>
#include <media/stagefright/MediaBufferGroup.h>
#include <media/stagefright/MediaSource.h>

extern android::MediaBufferGroup*   _ZN7android16MediaBufferGroupC1Ev() {
#ifdef AOSP
    return new android::MediaBufferGroup();
#else
    return new android::MediaBufferGroup(0);
#endif
}

extern int _ZN7android16MediaBufferGroup14acquire_bufferEPPNS_11MediaBufferEb(void *obj,android::MediaBuffer **out, 
            bool nonBlocking, size_t requestedSize) {
    android::MediaBufferGroup *mbg = static_cast<android::MediaBufferGroup *>(obj);
    return mbg->acquire_buffer(out,nonBlocking,requestedSize);

}

extern "C" {
    void _ZNK7android12IMediaSource11ReadOptions9getSeekToEPxPNS1_8SeekModeE(int64_t*, int32_t*) {}
    bool _ZNK7android12IMediaSource11ReadOptions14getNonBlockingEv();

    void _ZNK7android11MediaSource11ReadOptions9getSeekToEPxPNS1_8SeekModeE(int64_t *time_us, int32_t *mode) {
	    _ZNK7android12IMediaSource11ReadOptions9getSeekToEPxPNS1_8SeekModeE(time_us, mode);
    }

    bool _ZNK7android11MediaSource11ReadOptions14getNonBlockingEv() {
        return _ZNK7android12IMediaSource11ReadOptions14getNonBlockingEv();
    }
}
