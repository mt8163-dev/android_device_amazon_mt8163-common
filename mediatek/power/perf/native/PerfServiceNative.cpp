/*
 * Copyright (C) 2007 The Android Open Source Project
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

#define LOG_TAG "PerfService"
#include "utils/Log.h"
#include "PerfServiceNative.h"

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#include <unistd.h>
#include <utils/String16.h>

#include <cutils/log.h>
#include <cutils/properties.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>
//#include <binder/IInterface.h>

namespace android
{

/* It should be sync with IPerfService.aidl */
enum {
    TRANSACTION_boostEnable = IBinder::FIRST_CALL_TRANSACTION,
    TRANSACTION_boostDisable,
    TRANSACTION_boostEnableTimeout,
    TRANSACTION_boostEnableTimeoutMs,
    TRANSACTION_notifyAppState,
    TRANSACTION_userReg,
    TRANSACTION_userRegBigLittle,
    TRANSACTION_userUnreg,
    TRANSACTION_userGetCapability,
    TRANSACTION_userRegScn,
    TRANSACTION_userRegScnConfig,
    TRANSACTION_userUnregScn,
    TRANSACTION_userEnable,
    TRANSACTION_userEnableTimeout,
    TRANSACTION_userEnableTimeoutMs,
    TRANSACTION_userEnableAsync,
    TRANSACTION_userEnableTimeoutAsync,
    TRANSACTION_userEnableTimeoutMsAsync,
    TRANSACTION_userDisable,
    TRANSACTION_userResetAll,
    TRANSACTION_userDisableAll,
    TRANSACTION_userRestoreAll,
    TRANSACTION_dumpAll,
    TRANSACTION_setFavorPid,
    TRANSACTION_restorePolicy,
    //TRANSACTION_getPackName,
    TRANSACTION_getLastBoostPid,
    TRANSACTION_notifyFrameUpdate,
    TRANSACTION_notifyDisplayType,
    TRANSACTION_notifyUserStatus,
};

static int inited = 0;
static char packName[128] = "";
static sp<IServiceManager> sm ;
static sp<IBinder> binderptr = NULL;

#define BOOT_INFO_FILE "/sys/class/BOOT/BOOT/boot/boot_mode"
#define RENDER_THREAD_UPDATE_DURATION   400000000

#define RENDER_BIT    0x800000
#define RENDER_MASK   0x7FFFFF

static int check_meta_mode(void)
{
    char bootMode[4];
    int fd;
    //check if in Meta mode
    fd = open(BOOT_INFO_FILE, O_RDONLY);
    if(fd < 0) {
        return 0; // not meta mode
    }

    if(read(fd, bootMode, 4) < 1) {
        close(fd);
        return 0;
    }

    if (bootMode[0] == 0x31) {
        close(fd);
        return 1; // meta mode
    }

    close(fd);
    return 0;
}

static void init(void)
{
    if(!inited) {
        if(check_meta_mode())
            return;

        sm = defaultServiceManager();
        //binder = sm->getService(String16("mtk-perfservice"));
        binderptr = sm->checkService(String16("mtk-perfservice")); // use check to avoid null binder
        if(binderptr!=NULL) {
            inited = 1;
        }
    }
}

extern "C"
void PerfServiceNative_boostEnable(int scenario)
{
    Parcel data, reply;
    init();

    //ALOGI("PerfServiceNative_boostEnable:%d", scenario);

    if(binderptr!=NULL) {
        data.writeInterfaceToken(String16("com.mediatek.perfservice.IPerfService"));
        data.writeInt32(scenario);
        binderptr->transact(TRANSACTION_boostEnable ,data,&reply); // should sync with IPerfService
    }
}

extern "C"
void PerfServiceNative_boostDisable(int scenario)
{
    Parcel data, reply;
    init();

    //ALOGI("PerfServiceNative_boostDisable:%d", scenario);

    if(binderptr!=NULL) {
        data.writeInterfaceToken(String16("com.mediatek.perfservice.IPerfService"));
        data.writeInt32(scenario);
        binderptr->transact(TRANSACTION_boostDisable ,data,&reply);
    }
}

extern "C"
void PerfServiceNative_boostEnableTimeout(int scenario, int timeout)
{
    Parcel data, reply;
    init();

    //ALOGI("PerfServiceNative_boostEnableTimeout:%d, %d", scenario, timeout);

    if(binderptr!=NULL) {
        data.writeInterfaceToken(String16("com.mediatek.perfservice.IPerfService"));
        data.writeInt32(scenario);
        data.writeInt32(timeout);
        binderptr->transact(TRANSACTION_boostEnableTimeout ,data,&reply);
    }
}

extern "C"
void PerfServiceNative_boostEnableTimeoutMs(int scenario, int timeout_ms)
{
    Parcel data, reply;
    init();

    //ALOGI("PerfServiceNative_boostEnableTimeoutMs:%d, %d", scenario, timeout_ms);

    if(binderptr!=NULL) {
        data.writeInterfaceToken(String16("com.mediatek.perfservice.IPerfService"));
        data.writeInt32(scenario);
        data.writeInt32(timeout_ms);
        binderptr->transact(TRANSACTION_boostEnableTimeoutMs ,data,&reply);
    }
}

extern "C"
void PerfServiceNative_boostEnableAsync(int scenario)
{
    Parcel data, reply;
    init();

    //ALOGI("PerfServiceNative_boostEnableAsync:%d", scenario);

    if(binderptr!=NULL) {
        data.writeInterfaceToken(String16("com.mediatek.perfservice.IPerfService"));
        data.writeInt32(scenario);
        binderptr->transact(TRANSACTION_boostEnable ,data,&reply,IBinder::FLAG_ONEWAY); // should sync with IPerfService
    }
}

extern "C"
void PerfServiceNative_boostDisableAsync(int scenario)
{
    Parcel data, reply;
    init();

    //ALOGI("PerfServiceNative_boostDisableAsync:%d", scenario);

    if(binderptr!=NULL) {
        data.writeInterfaceToken(String16("com.mediatek.perfservice.IPerfService"));
        data.writeInt32(scenario);
        binderptr->transact(TRANSACTION_boostDisable ,data,&reply,IBinder::FLAG_ONEWAY);
    }
}

extern "C"
void PerfServiceNative_boostEnableTimeoutAsync(int scenario, int timeout)
{
    Parcel data, reply;
    init();

    //ALOGI("PerfServiceNative_boostEnableTimeoutAsync:%d, %d", scenario, timeout);

    if(binderptr!=NULL) {
        data.writeInterfaceToken(String16("com.mediatek.perfservice.IPerfService"));
        data.writeInt32(scenario);
        data.writeInt32(timeout);
        binderptr->transact(TRANSACTION_boostEnableTimeout ,data,&reply,IBinder::FLAG_ONEWAY);
    }
}

extern "C"
void PerfServiceNative_boostEnableTimeoutMsAsync(int scenario, int timeout_ms)
{
    Parcel data, reply;
    init();

    //ALOGI("PerfServiceNative_boostEnableTimeoutMsAsync:%d, %d", scenario, timeout_ms);

    if(binderptr!=NULL) {
        data.writeInterfaceToken(String16("com.mediatek.perfservice.IPerfService"));
        data.writeInt32(scenario);
        data.writeInt32(timeout_ms);
        binderptr->transact(TRANSACTION_boostEnableTimeoutMs ,data,&reply,IBinder::FLAG_ONEWAY);
    }
}

extern "C"
int PerfServiceNative_userReg(int scn_core, int scn_freq)
{
    Parcel data, reply;
    int    handle = -1, pid=-1, tid=-1;
    init();

    pid = (int)getpid();
    tid = (int)gettid();

    //ALOGI("PerfServiceNative_userReg: %d, %d (pid:%d, tid:%d)", scn_core, scn_freq, pid, tid);

    if(binderptr!=NULL) {
        data.writeInterfaceToken(String16("com.mediatek.perfservice.IPerfService"));
        data.writeInt32(scn_core);
        data.writeInt32(scn_freq);
        data.writeInt32(pid);
        data.writeInt32(tid);
        binderptr->transact(TRANSACTION_userReg ,data,&reply); // should sync with IPerfService
        reply.readExceptionCode();
        handle = reply.readInt32();
    }
    return handle;
}

extern "C"
int PerfServiceNative_userRegBigLittle(int scn_core_big, int scn_freq_big, int scn_core_little, int scn_freq_little)
{
    Parcel data, reply;
    int    handle = -1, pid=-1, tid=-1;
    init();

    pid = (int)getpid();
    tid = (int)gettid();

    //ALOGI("PerfServiceNative_userRegBigLittle: %d, %d, %d, %d (pid:%d, tid:%d)", scn_core_little, scn_freq_little, scn_core_big, scn_freq_big, pid, tid);

    if(binderptr!=NULL) {
        data.writeInterfaceToken(String16("com.mediatek.perfservice.IPerfService"));
        data.writeInt32(scn_core_big);
        data.writeInt32(scn_freq_big);
        data.writeInt32(scn_core_little);
        data.writeInt32(scn_freq_little);
        data.writeInt32(pid);
        data.writeInt32(tid);
        binderptr->transact(TRANSACTION_userRegBigLittle ,data,&reply); // should sync with IPerfService
        reply.readExceptionCode();
        handle = reply.readInt32();
    }
    return handle;
}

extern "C"
void PerfServiceNative_userUnreg(int handle)
{
    Parcel data, reply;
    init();

    //ALOGI("PerfServiceNative_userUnreg:%d", handle);

    if(binderptr!=NULL) {
        data.writeInterfaceToken(String16("com.mediatek.perfservice.IPerfService"));
        data.writeInt32(handle);
        binderptr->transact(TRANSACTION_userUnreg ,data,&reply); // should sync with IPerfService
    }
}

extern "C"
int PerfServiceNative_userGetCapability(int cmd)
{
    Parcel data, reply;
    int value = -1;
    init();

    //ALOGI("PerfServiceNative_userGetCapability: %d", cmd);

    if(binderptr!=NULL) {
        data.writeInterfaceToken(String16("com.mediatek.perfservice.IPerfService"));
        data.writeInt32(cmd);
        binderptr->transact(TRANSACTION_userGetCapability ,data,&reply); // should sync with IPerfService
        reply.readExceptionCode();
        value = reply.readInt32();
    }
    return value;
}

extern "C"
int PerfServiceNative_userRegScn(void)
{
    Parcel data, reply;
    int    handle = -1, pid=-1, tid=-1;
    init();

    pid = (int)getpid();
    tid = (int)gettid();

    //ALOGI("PerfServiceNative_userRegScn: (pid:%d, tid:%d)", pid, tid);

    if(binderptr!=NULL) {
        data.writeInterfaceToken(String16("com.mediatek.perfservice.IPerfService"));
        data.writeInt32(pid);
        data.writeInt32(tid);
        binderptr->transact(TRANSACTION_userRegScn ,data,&reply); // should sync with IPerfService
        reply.readExceptionCode();
        handle = reply.readInt32();
    }
    return handle;
}

extern "C"
void PerfServiceNative_userRegScnConfig(int handle, int cmd, int param_1, int param_2, int param_3, int param_4)
{
    Parcel data, reply;
    init();

    //ALOGI("PerfServiceNative_userRegScnConfig: handle:%d, cmd:%d, p1:%d, p2:%d, p3:%d, p4:%d", handle, cmd, param_1, param_2, param_3, param_4);

    if(binderptr!=NULL) {
        data.writeInterfaceToken(String16("com.mediatek.perfservice.IPerfService"));
        data.writeInt32(handle);
        data.writeInt32(cmd);
        data.writeInt32(param_1);
        data.writeInt32(param_2);
        data.writeInt32(param_3);
        data.writeInt32(param_4);
        binderptr->transact(TRANSACTION_userRegScnConfig,data,&reply); // should sync with IPerfService
    }
}

extern "C"
void PerfServiceNative_userUnregScn(int handle)
{
    Parcel data, reply;
    init();

    ALOGI("PerfServiceNative_userUnregScn: handle:%d", handle);

    if(binderptr!=NULL) {
        data.writeInterfaceToken(String16("com.mediatek.perfservice.IPerfService"));
        data.writeInt32(handle);
        binderptr->transact(TRANSACTION_userUnregScn,data,&reply); // should sync with IPerfService
    }
}

extern "C"
void PerfServiceNative_userEnable(int handle)
{
    Parcel data, reply;
    init();

    //ALOGI("PerfServiceNative_userEnable:%d", handle);

    if(binderptr!=NULL) {
        data.writeInterfaceToken(String16("com.mediatek.perfservice.IPerfService"));
        data.writeInt32(handle);
        binderptr->transact(TRANSACTION_userEnable ,data,&reply); // should sync with IPerfService
    }
}

extern "C"
void PerfServiceNative_userEnableTimeout(int handle, int timeout)
{
    Parcel data, reply;
    init();

    //ALOGI("PerfServiceNative_userEnableTimeout:%d, %d", handle, timeout);

    if(binderptr!=NULL) {
        data.writeInterfaceToken(String16("com.mediatek.perfservice.IPerfService"));
        data.writeInt32(handle);
        data.writeInt32(timeout);
        binderptr->transact(TRANSACTION_userEnableTimeout ,data,&reply);
    }
}

extern "C"
void PerfServiceNative_userEnableTimeoutMs(int handle, int timeout_ms)
{
    Parcel data, reply;
    init();

    //ALOGI("PerfServiceNative_userEnableTimeoutMs:%d, %d", handle, timeout_ms);

    if(binderptr!=NULL) {
        data.writeInterfaceToken(String16("com.mediatek.perfservice.IPerfService"));
        data.writeInt32(handle);
        data.writeInt32(timeout_ms);
        binderptr->transact(TRANSACTION_userEnableTimeoutMs ,data,&reply);
    }
}

extern "C"
void PerfServiceNative_userEnableAsync(int handle)
{
    Parcel data, reply;
    init();

    //ALOGI("PerfServiceNative_userEnableAsync:%d", handle);

    if(binderptr!=NULL) {
        data.writeInterfaceToken(String16("com.mediatek.perfservice.IPerfService"));
        data.writeInt32(handle);
        binderptr->transact(TRANSACTION_userEnableAsync ,data,&reply); // should sync with IPerfService
    }
}

extern "C"
void PerfServiceNative_userEnableTimeoutAsync(int handle, int timeout)
{
    Parcel data, reply;
    init();

    //ALOGI("PerfServiceNative_userEnableTimeoutAsync:%d, %d", handle, timeout);

    if(binderptr!=NULL) {
        data.writeInterfaceToken(String16("com.mediatek.perfservice.IPerfService"));
        data.writeInt32(handle);
        data.writeInt32(timeout);
        binderptr->transact(TRANSACTION_userEnableTimeoutAsync ,data,&reply);
    }
}

extern "C"
void PerfServiceNative_userEnableTimeoutMsAsync(int handle, int timeout_ms)
{
    Parcel data, reply;
    init();

    //ALOGI("PerfServiceNative_userEnableTimeoutMsAsync:%d, %d", handle, timeout_ms);

    if(binderptr!=NULL) {
        data.writeInterfaceToken(String16("com.mediatek.perfservice.IPerfService"));
        data.writeInt32(handle);
        data.writeInt32(timeout_ms);
        binderptr->transact(TRANSACTION_userEnableTimeoutMsAsync ,data,&reply);
    }
}

extern "C"
void PerfServiceNative_userDisable(int handle)
{
    Parcel data, reply;
    init();

    //ALOGI("PerfServiceNative_userDisable:%d", handle);

    if(binderptr!=NULL) {
        data.writeInterfaceToken(String16("com.mediatek.perfservice.IPerfService"));
        data.writeInt32(handle);
        binderptr->transact(TRANSACTION_userDisable ,data,&reply);
    }
}

extern "C"
void PerfServiceNative_userResetAll(void)
{
    Parcel data, reply;
    init();

    //ALOGI("PerfServiceNative_userResetAll");

    if(binderptr!=NULL) {
        data.writeInterfaceToken(String16("com.mediatek.perfservice.IPerfService"));
        binderptr->transact(TRANSACTION_userResetAll ,data,&reply);
    }
}

extern "C"
void PerfServiceNative_userDisableAll(void)
{
    Parcel data, reply;
    init();

    //ALOGI("PerfServiceNative_userDisableAll");

    if(binderptr!=NULL) {
        data.writeInterfaceToken(String16("com.mediatek.perfservice.IPerfService"));
        binderptr->transact(TRANSACTION_userDisableAll ,data,&reply);
    }
}

extern "C"
void PerfServiceNative_dumpAll(void)
{
    Parcel data, reply;
    init();

    //ALOGI("PerfServiceNative_dumpAll");

    if(binderptr!=NULL) {
        data.writeInterfaceToken(String16("com.mediatek.perfservice.IPerfService"));
        binderptr->transact(TRANSACTION_dumpAll ,data,&reply);
    }
}

extern "C"
void PerfServiceNative_setFavorPid(int pid)
{
    Parcel data, reply;
    init();

    //ALOGI("PerfServiceNative_setFavorPid: pid:%d", pid);

    if(binderptr!=NULL) {
        data.writeInterfaceToken(String16("com.mediatek.perfservice.IPerfService"));
        data.writeInt32(pid);
        binderptr->transact(TRANSACTION_setFavorPid,data,&reply,IBinder::FLAG_ONEWAY);
    }
}

extern "C"
void PerfServiceNative_setBoostThread(void)
{
    Parcel data, reply;
    int tid;
    init();

    tid = (int)gettid();
    //ALOGI("PerfServiceNative_setBoostThread: pid:%d, tid:%d", (int)getpid(), tid);

    if(binderptr!=NULL) {
        data.writeInterfaceToken(String16("com.mediatek.perfservice.IPerfService"));
        data.writeInt32(tid | RENDER_BIT);
        binderptr->transact(TRANSACTION_setFavorPid,data,&reply,IBinder::FLAG_ONEWAY);
    }
}

extern "C"
void PerfServiceNative_restoreBoostThread(void)
{
    Parcel data, reply;
    int tid;
    init();

    tid = (int)gettid();
    //ALOGI("PerfServiceNative_restoreBoostThread: pid:%d, tid:%d", (int)getpid(), tid);

    if(binderptr!=NULL) {
        data.writeInterfaceToken(String16("com.mediatek.perfservice.IPerfService"));
        data.writeInt32(tid | RENDER_BIT);
        binderptr->transact(TRANSACTION_restorePolicy,data,&reply,IBinder::FLAG_ONEWAY);
    }
}

extern "C"
void PerfServiceNative_notifyFrameUpdate(int level)
{
    Parcel data, reply;
    static nsecs_t mPreviousTime = 0;
    nsecs_t now = systemTime(CLOCK_MONOTONIC);
    //static int set_tid = 0;
    init();

    #if 0 // L MR1: foreground app is already in root group
    // get tid
    if(!set_tid) {
        level = (int)gettid();
        set_tid = 1;
    }
    #endif

    if(mPreviousTime == 0 || (now - mPreviousTime) > RENDER_THREAD_UPDATE_DURATION) { // 400ms
        //ALOGI("PerfServiceNative_notifyFrameUpdate:%d", (now - mPreviousTime)/1000000);
        if(binderptr!=NULL) {
            data.writeInterfaceToken(String16("com.mediatek.perfservice.IPerfService"));
            data.writeInt32(level);
            binderptr->transact(TRANSACTION_notifyFrameUpdate ,data,&reply,IBinder::FLAG_ONEWAY);
        }
        mPreviousTime = now;
    }
}

extern "C"
void PerfServiceNative_notifyDisplayType(int type)
{
    Parcel data, reply;
    init();

    //ALOGI("PerfServiceNative_notifyDisplayType:%d", type);
    if(binderptr!=NULL) {
        data.writeInterfaceToken(String16("com.mediatek.perfservice.IPerfService"));
        data.writeInt32(type);
        binderptr->transact(TRANSACTION_notifyDisplayType ,data,&reply,IBinder::FLAG_ONEWAY);
    }
}

extern "C"
void PerfServiceNative_notifyUserStatus(int type, int status)
{
    Parcel data, reply;
    init();

    //ALOGI("PerfServiceNative_notifyUserStatus:%d, status:%d", type, status);
    if(binderptr!=NULL) {
        data.writeInterfaceToken(String16("com.mediatek.perfservice.IPerfService"));
        data.writeInt32(type);
        data.writeInt32(status);
        binderptr->transact(TRANSACTION_notifyUserStatus ,data,&reply,IBinder::FLAG_ONEWAY);
    }
}

extern "C"
int PerfServiceNative_getLastBoostPid()
{
    Parcel data, reply;
    //const int handle = 1;
    init();

    //ALOGI("PerfServiceNative_getLastBoostPid");
    if(binderptr!=NULL) {
        data.writeInterfaceToken(String16("com.mediatek.perfservice.IPerfService"));
        binderptr->transact(TRANSACTION_getLastBoostPid,data,&reply);
        reply.readExceptionCode();

        return reply.readInt32();
    }
    return -1;
}

extern "C"
const char* PerfServiceNative_getPackName()
{
#if 1
    int pid, ret;
    char spid[8];
    char path[64] = "/proc/";
    FILE *ifp;

    pid = PerfServiceNative_getLastBoostPid();
    //itoa(pid, spid, 10);
    sprintf(spid, "%d", pid);
    strcat(path, spid);
    strcat(path, "/cmdline");
    if ((ifp = fopen(path,"r")) == NULL)
        return "";
    ret = fscanf(ifp, "%s", packName);
    fclose(ifp);
    if (ret == 1)
        return packName;
    else
        return "";
#else
    return packName;
#endif
}

}
