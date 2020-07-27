#ifndef _UTILS_H_
#define _UTILS_H_

#define LENGTH(x) (size_t) (sizeof(x) / sizeof(x[0]))

#define BYTE2WORD(a, b) (uint16_t) (((a & 0xFF) << 8) | (b & 0xFF))

#define BYTE2DWORD(a, b, c, d) \
  (((uint32_t) a & 0xFF) << 24) | \
  (((uint32_t) b & 0xFF) << 16) | \
  (((uint32_t) c & 0xFF) <<  8) | \
   ((uint32_t) d & 0xFF);

#define LISTENER (EvtAction)[&](EvtListener *, EvtContext *)->bool

#define DEBUG(text) if(false) { Serial.println(text); Serial.flush(); }

#define COPY(a, b, length) \
  for(uint8_t i = 0; i < length; i++) { \
    b[i] = a[i]; \
  }

#define CALLBACK(func, ...) if(func != NULL) { func(__VA_ARGS__); }

typedef void (*VoidCallback)();

// This is used so any task can see the millis() at the start of the loop
// without having to call millis() multiple times per loop. We do this
// because millis() disables interrupts and this helps us keep better time.
// Defined/Updated in Looper.cpp
extern unsigned long current_loop_millis;

// Wait for it to be at least MS milliseconds since LAST
#define LOOP_WAIT_MS(LAST, MS) if(current_loop_millis < LAST + MS) {return;}

#endif