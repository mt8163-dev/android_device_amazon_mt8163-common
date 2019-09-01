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
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <pthread.h>
#include <log/log.h>

#include <hardware/memtrack.h>

#include "memtrack_mtk.h"

#define ARRAY_SIZE(x) (sizeof(x)/sizeof(x[0]))
#define min(x, y) ((x) < (y) ? (x) : (y))

struct memtrack_record record_templates[] = {
    {
        .flags = MEMTRACK_FLAG_SMAPS_ACCOUNTED |
                 MEMTRACK_FLAG_PRIVATE |
                 MEMTRACK_FLAG_NONSECURE,
    },
    {
        .flags = MEMTRACK_FLAG_SMAPS_UNACCOUNTED |
                 MEMTRACK_FLAG_PRIVATE |
                 MEMTRACK_FLAG_NONSECURE,
    },
};

int gl_memtrack_get_memory(pid_t pid, int type,
                             struct memtrack_record *records,
                             size_t *num_records)
{
    size_t allocated_records = min(*num_records, ARRAY_SIZE(record_templates));
    int i;
    FILE *fp;
    char line[1024];

    *num_records = ARRAY_SIZE(record_templates);

    /* fastpath to return the necessary number of records */
    if (allocated_records == 0) {
        return 0;
    }

    fp = fopen("/sys/kernel/debug/mali/gpu_memory", "r");
    if (fp == NULL) {
        return -errno;
    }

    memcpy(records, record_templates,
           sizeof(struct memtrack_record) * allocated_records);

    while (1) {
        if (fgets(line, sizeof(line), fp) == NULL) {
            break;
        }

        /* Format:
         * Name (:bytes)    pid   mali_mem    max_mali_mem   external_mem   ump_mem   dma_mem
         * ====================================================================================
         * surfaceflinger   142   1048576     1310720        4923392        0         20795392
         */
        if (line[0] == ' ' && line[1] == ' ') {
            unsigned int mali_mem;
            unsigned int external_mem;
            int line_pid;

            int ret = sscanf(line, "  %*s %u %u %*u %*u %*u %*u\n",
                             &line_pid, &mali_mem);
            if (ret == 2 && line_pid == pid) {
                if (allocated_records > 0) {
                    records[0].size_in_bytes = 0;
                }
                if (allocated_records > 1) {
                    records[1].size_in_bytes = mali_mem;
                }
                break;
            }
        }
    }

    fclose(fp);

    return 0;
}

int gl_memtrack_init()
{
  return 0;
}
