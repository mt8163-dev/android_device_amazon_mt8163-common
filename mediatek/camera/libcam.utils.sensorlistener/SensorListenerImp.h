#ifndef SENSOR_LISTENER_IMP_H
#define SENSOR_LISTENER_IMP_H
//-----------------------------------------------------------------------------
#include <utils/Trace.h>
#define MY_LOGD(fmt, arg...)        ALOGD("[%s] " fmt, __FUNCTION__, ##arg)
#define MY_LOGW(fmt, arg...)        ALOGW("[%s] " fmt, __FUNCTION__, ##arg)
#define MY_LOGE(fmt, arg...)        ALOGE("[%s] " fmt, __FUNCTION__, ##arg)
//
#define MY_LOGD_IF(cond, arg...)    if (cond) { MY_LOGD(arg); }
#define MY_LOGW_IF(cond, arg...)    if (cond) { MY_LOGW(arg); }
#define MY_LOGE_IF(cond, arg...)    if (cond) { MY_LOGE(arg); }
//
#define FUNCTION_NAME               MY_LOGD("")
#define FUNCTION_IN                 MY_LOGD("+")
#define FUNCTION_OUT                MY_LOGD("-")
#define CAM_TRACE_NAME(name)                    ATRACE_NAME(name)
#define CAM_TRACE_BEGIN(name)                   ATRACE_BEGIN(name)
#define CAM_TRACE_END()                         ATRACE_END()
typedef bool MBOOL;
typedef void MVOID;
typedef bool MBOOL;
typedef unsigned int MUINT32;
typedef uintptr_t MUINTPTR;
typedef int MINT32;
#define MFALSE  0
#define MTRUE 1
//-----------------------------------------------------------------------------
class SensorListener
{
    protected:
        virtual ~SensorListener() {};
    //
    public:
        typedef enum
        {
            SensorType_Acc,
            SensorType_Mag,
            SensorType_Gyro,
            SensorType_Light,
            SensorType_Proxi
        }SensorTypeEnum;
        //
        typedef void (*Listener) (ASensorEvent event);
        //
        static SensorListener*  createInstance(void);
        virtual MVOID   destroyInstance(void) = 0;
        virtual MBOOL   setListener(Listener func) = 0;
        virtual MBOOL   enableSensor(
                            SensorTypeEnum  sensorType,
                            MUINT32         periodInMs) = 0;
        virtual MBOOL   disableSensor(SensorTypeEnum sensorType) = 0;
};

bool
setThreadPriority(
    int policy,
    int priority);
bool
getThreadPriority(
    int& policy,
    int& priority);
//-----------------------------------------------------------------------------
class SensorListenerImpThread : public Thread
{
    public:
        SensorListenerImpThread(Looper* looper) : Thread(false)
        {
            mLooper = sp<Looper>(looper);
        }
        //
        ~SensorListenerImpThread()
        {
            mLooper.clear();
        }
        //
        status_t readyToRun()
        {
            int policy = SCHED_OTHER, priority = 0;
            //
            ::prctl(PR_SET_NAME,"Mtkcam@SensorListenerImpThread", 0, 0, 0);
            //
            setThreadPriority(policy,priority);
            getThreadPriority(policy,priority);
            MY_LOGD("policy(%d),priority(%d)",policy,priority);
            //
            return NO_ERROR;
        }
        //
        virtual bool threadLoop()
        {
            //MY_LOGD("pollOnce E");
            mLooper->pollOnce(-1);
            //MY_LOGD("pollOnce X");
            return true;
        }
        // force looper wake up
        void wake() {
            mLooper->wake();
        }
    private:
        sp<Looper> mLooper;
};
//-----------------------------------------------------------------------------
class SensorListenerImp : public SensorListener
{
    public:
        SensorListenerImp();
        ~SensorListenerImp();
        //
        virtual void    destroyInstance(void);
        virtual MBOOL   setListener(Listener func);
        virtual MBOOL   enableSensor(
                            SensorTypeEnum  sensorType,
                            MUINT32         periodInMs);
        virtual MBOOL   disableSensor(SensorTypeEnum sensorType);
        //
        virtual MBOOL   init(void);
        virtual MBOOL   uninit(void);
        virtual MBOOL   getEvents(void);
        virtual MBOOL   isSupport(void);
        //
    private:
        #define SENSOR_TYPE_AMOUNT  (SensorType_Proxi+1)
        //
        mutable Mutex               mLock;
        volatile MINT32             mUser;
        Sensor const*               mpSensor[SENSOR_TYPE_AMOUNT];
        volatile MUINT32            mSensorEnableCnt;
        sp<Looper>                  mspLooper;
        sp<SensorEventQueue>        mspSensorEventQueue;
        SensorManager*              mpSensorManager;
        Listener                    mpListener;
        sp<SensorListenerImpThread> mspThread;
};

//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
#endif

