#undef __STRICT_ANSI__
#define __STDINT_LIMITS
#define __STDC_LIMIT_MACROS

#include <inttypes.h>
#include <stdint.h>

#define LOG_TAG "TimedEventQueue"

#include <log/log.h>

namespace android {

extern "C" bool mRunning;

extern "C" {
   /*
    * NOTE: TimedEventQueue was deprecated in Android 6.0 +.
    * This library provides stubs for TimedEventQueue symbols.
    */
   bool mRunning;

   void _ZN7android15TimedEventQueueC1Ev() {
       ALOGV("(%s): TimedEventQueue init...", __func__);
   }

   void _ZN7android15TimedEventQueueD1Ev() {
       ALOGI("(%s): TimedEventQueue exit...", __func__);
   }

   int32_t _ZN7android15TimedEventQueue14postTimedEventERKNS_2spINS0_5EventEEEx(void *event, 
       int64_t realtime_us) {
         return realtime_us; // event->eventID();
   }

   int32_t _ZN7android15TimedEventQueue9postEventERKNS_2spINS0_5EventEEE(void *event) {
       return _ZN7android15TimedEventQueue14postTimedEventERKNS_2spINS0_5EventEEEx(event, 0);
   }

   int32_t _ZN7android15TimedEventQueue18postEventWithDelayERKNS_2spINS0_5EventEEEx(void *event,
     int64_t delay_us) {
       return _ZN7android15TimedEventQueue14postTimedEventERKNS_2spINS0_5EventEEEx(event, delay_us);
   }

   void _ZN7android15TimedEventQueue5startEv() {
       mRunning = true;
   }

   void _ZN7android15TimedEventQueue4stopEb(bool flush) {
       if (!flush) _ZN7android15TimedEventQueue14postTimedEventERKNS_2spINS0_5EventEEEx(NULL, INT64_MIN);
       mRunning = false;
   }

   bool _ZN7android15TimedEventQueue11cancelEventEi(int32_t event_id) {
       return (event_id == 0); 
   }
}

} // namespace android
