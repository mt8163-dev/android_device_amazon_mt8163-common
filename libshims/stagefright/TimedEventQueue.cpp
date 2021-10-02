#undef __STRICT_ANSI__
#define __STDINT_LIMITS
#define __STDC_LIMIT_MACROS

#include <inttypes.h>
#include <stdint.h>

#define LOG_TAG "TimedEventQueue"

#include <log/log.h>

namespace android {

extern "C" {
   /*
    * NOTE: TimedEventQueue was deprecated in Android 6.0 +.
    * This library provides stubs for TimedEventQueue symbols.
    */
   int32_t _ZN7android15TimedEventQueue14postTimedEventERKNS_2spINS0_5EventEEEx(void *event, 
       int64_t realtime_us) {
         return realtime_us; // event->eventID();
   }

   int32_t _ZN7android15TimedEventQueue9postEventERKNS_2spINS0_5EventEEE(void *event) {
       return _ZN7android15TimedEventQueue14postTimedEventERKNS_2spINS0_5EventEEEx(event, 0);
   }
}

} // namespace android
