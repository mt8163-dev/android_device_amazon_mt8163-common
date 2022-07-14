/*
 * Copyright (C) 2008 The Android Open Source Project
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <pthread.h>
#include <dlfcn.h>

#include <errno.h>
#include <limits.h>
#include <stdatomic.h>
#include <stdlib.h>
#include <string.h>
#include <sys/cdefs.h>
#include <sys/mman.h>
#include <unistd.h>

struct pthread_mutex_internal_t {
    _Atomic(uint16_t) state;
    // padding to align with pthread_mutex_t
    // size is 40 bytes in 64 bit
    // size is 4 bytes in 32 bit (satisfied)
#if defined(__LP64__)
    char __reserved[36];
#endif
} __attribute__((aligned(4)));

static_assert(sizeof(pthread_mutex_t) == sizeof(pthread_mutex_internal_t),
              "pthread_mutex_t should actually be pthread_mutex_internal_t in implementation.");

// For binary compatibility with old version of pthread_mutex_t, we can't use more strict alignment
// than 4-byte alignment.
static_assert(alignof(pthread_mutex_t) == 4,
              "pthread_mutex_t should fulfill the alignment of pthread_mutex_internal_t.");

static inline pthread_mutex_internal_t* __get_internal_mutex(pthread_mutex_t* mutex_interface) {
  return reinterpret_cast<pthread_mutex_internal_t*>(mutex_interface);
}

static inline __always_inline bool IsMutexDestroyed(uint16_t mutex_state) {
    return mutex_state == 0xffff;
}

int pthread_mutex_destroy(pthread_mutex_t* mutex_interface) {
    pthread_mutex_internal_t* mutex = __get_internal_mutex(mutex_interface);
    uint16_t old_state = atomic_load_explicit(&mutex->state, memory_order_relaxed);
    if (__predict_false(IsMutexDestroyed(old_state))) {
        // Mutex destroyed? Done! Don't explode.
        return EBUSY;
    }

    int (*real_pthread_mutex_destroy)(pthread_mutex_t*);
    *(void **)&real_pthread_mutex_destroy = dlsym(RTLD_NEXT, "pthread_mutex_destroy");
    return real_pthread_mutex_destroy(mutex_interface);
}
