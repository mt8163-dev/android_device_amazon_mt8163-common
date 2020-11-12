#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <errno.h>
#include <pthread.h>
#include <stdio.h>

#define LOG_TAG "PlayReady_Shim"
#define LIB_NAME "libplayready"

#include <log/log.h>

#ifdef __cplusplus
extern "C"
{
#endif

extern void Oem_CritSec_Initialize(unsigned int value, int *sval) 
{
    ALOGI("%s: init value=%u, sval=%p", __func__, value, sval);

    int ret = sem_unlink(LIB_NAME);
    if (ret != 0)
    {
        ALOGW("%s: sem_unlink() failed, errno=%d, ret=%d", __func__, errno, ret);
    }
    
    // sem = sem_open("libplayready",0x40,0x180,1,param_1);
    sem_t *sem = sem_open(LIB_NAME, O_RDWR, 0777, value);

    if (sem == NULL) 
    {
        ALOGE("%s: sem_open() failed, errno=%d", __func__, errno);
        if (EEXIST == errno) 
        {
            ALOGW("%s: a semaphore with that name already exists (%s)", __func__, LIB_NAME);
        }
    } 
    else 
    { 
        sem_getvalue(sem, sval);
    }

    ALOGV("%s: all done", __func__);
}

extern void Oem_CritSec_Enter(sem_t *sem, int *value) 
{
    int ret = -1;

    ALOGI("%s: init value=%p", __func__, value);

    if (sem == NULL)
    {
        ALOGE("%s: sem is NULL", __func__);
    }
    else
    {
        ret = sem_getvalue(sem, value);
        if (ret != 0)
        {
            ALOGW("%s: sem_getvalue() failed, errno=%d, ret=%d", __func__, errno, ret);
        }

        ret = sem_wait(sem);
        if (ret != 0)
        {
            ALOGW("%s: sem_wait() failed, errno=%d, ret=%d", __func__, errno, ret);
        }

        ret = sem_getvalue(sem, value);
        if (ret != 0)
        {
            ALOGW("%s: sem_getvalue() failed, errno=%d, ret=%d", __func__, errno, ret);
        }
    }

    ALOGV("%s: all done", __func__);
}

extern void Oem_CritSec_Leave(sem_t *sem, int *value)
{
    int ret = -1;

    ALOGI("%s: init value=%p", __func__, value);

    if (sem == NULL)
    {
        ALOGE("%s: sem is NULL", __func__);
    }
    else
    {
        ret = sem_getvalue(sem, value);
        if (ret != 0)
        {
            ALOGW("%s: sem_getvalue() failed, errno=%d, ret=%d", __func__, errno, ret);
        }

        ret = sem_post(sem);
        if (ret != 0)
        {
            ALOGW("%s: sem_post() failed, errno=%d, ret=%d", __func__, errno, ret);
        }

        ret = sem_getvalue(sem, value);
        if (ret != 0)
        {
            ALOGW("%s: sem_getvalue() failed, errno=%d, ret=%d", __func__, errno, ret);
        }
    }

    ALOGV("%s: all done", __func__);
}

#ifdef __cplusplus
}
#endif
