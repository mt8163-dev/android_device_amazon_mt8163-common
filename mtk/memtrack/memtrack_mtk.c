/*
 * Copyright (C) 2013 The Android Open Source Project
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

#include <errno.h>

#include <hardware/memtrack.h>

#include "memtrack_mtk.h"

int mtk_memtrack_init(const struct memtrack_module *module)
{
    gl_memtrack_init();
    graphic_memtrack_init();
    return 0;
}

int mtk_memtrack_get_memory(const struct memtrack_module *module,
                                pid_t pid,
                                int type,
                                struct memtrack_record *records,
                                size_t *num_records)
{
    if (type == MEMTRACK_TYPE_GL) {
        return gl_memtrack_get_memory(pid, type, records, num_records);
    } else if(type == MEMTRACK_TYPE_GRAPHICS) {
        return graphic_memtrack_get_memory(pid, type, records, num_records);
    }

    return -EINVAL;
}

static struct hw_module_methods_t memtrack_module_methods = {
    .open = NULL,
};

struct memtrack_module HAL_MODULE_INFO_SYM = {
    common: {
        tag: HARDWARE_MODULE_TAG,
        module_api_version: MEMTRACK_MODULE_API_VERSION_0_1,
        hal_api_version: HARDWARE_HAL_API_VERSION,
        id: MEMTRACK_HARDWARE_MODULE_ID,
        name: "MediaTek Memory Tracker HAL",
        author: "The Android Open Source Project",
        methods: &memtrack_module_methods,
    },

    init: mtk_memtrack_init,
    getMemory: mtk_memtrack_get_memory,
};

