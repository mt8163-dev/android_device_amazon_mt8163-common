/*
 * Copyright (C) 2020 The Android Open Source Project
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

#include <stdint.h>
#include <sys/types.h>

#include "GraphicBuffer.h"
#include <ui/GraphicBufferMapper.h>
#include <ui/PixelFormat.h>

namespace android {
static uint64_t getUniqueId() {
    static volatile int32_t nextId = 0;
    uint64_t id = static_cast<uint64_t>(getpid()) << 32;
    id |= static_cast<uint32_t>(android_atomic_inc(&nextId));
    return id;
}

GraphicBuffer::GraphicBuffer(uint32_t inWidth, uint32_t inHeight,
        PixelFormat inFormat, uint32_t inUsage)
    : BASE(), mOwner(ownData), mBufferMapper(GraphicBufferMapper::get()),
      mInitCheck(NO_ERROR), mId(getUniqueId()), mGenerationNumber(0)
{
    width  =
    height =
    stride =
    format =
    usage  = 0;
    handle = NULL;
    mInitCheck = initSize(inWidth, inHeight, inFormat, inUsage, "<Unknown>");
}
};
