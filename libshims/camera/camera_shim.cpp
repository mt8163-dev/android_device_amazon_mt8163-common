#include <sensor/SensorManager.h>

extern "C" {
    extern void _ZN7android13SensorManager16createEventQueueENS_7String8Ei(void **retVal, void *sensorMgr, void **str8P, int mode);
    extern void _ZN7android7String8C1EPKc(void **str8P, const char *str);
    extern void _ZN7android7String8D1Ev(void **str8P);
    extern void _ZN7android13SensorManagerC1Ev() {}

    extern void _ZN7android13SensorManager16createEventQueueEv(void **retVal, void *sensorMgr)
    {
        void *string;

        _ZN7android7String8C1EPKc(&string, "");
        _ZN7android13SensorManager16createEventQueueENS_7String8Ei(retVal, sensorMgr, &string, 0);
        _ZN7android7String8D1Ev(&string);
    }

    extern pthread_mutex_t _ZN7android9SingletonINS_13SensorManagerEE5sLockE = PTHREAD_MUTEX_INITIALIZER;
    extern void* _ZN7android9SingletonINS_13SensorManagerEE9sInstanceE = NULL;
}
