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


#define SHIFT_POLY(ARR, VAL) \
  for (uint8_t i = 0; i < (sizeof(ARR) / sizeof(word)); i++) { \
    ARR[i] += VAL; \
  }


#define MEASURE_PIXEL_L2R(Y, CHECK, PAINT) \
  static uint16_t x = 0; \
  if(x == WindowManager::getWidth()) return; \
  if(display->gfx_GetPixel(x, Y) == CHECK) { \
    Serial.println("Found it!"); \
    Serial.println(x); \
    while(true) {} \
  } \
  display->gfx_PutPixel(x, Y, PAINT); \
  x++;

#define MEASURE_PIXEL_R2L(Y, CHECK, PAINT) \
  static uint16_t x = WindowManager::getWidth() - 1; \
  if(x == 0) return; \
  if(display->gfx_GetPixel(x, Y) == CHECK) { \
    Serial.println("Found it!"); \
    Serial.println(x); \
    while(true) {} \
  } \
  display->gfx_PutPixel(x, Y, PAINT); \
  x--;

#define MEASURE_PIXEL_B2T(X, CHECK, PAINT) \
  static uint16_t y = WindowManager::getHeight() - 1; \
  if(y == 0) return; \
  if(display->gfx_GetPixel(X, y) == CHECK) { \
    Serial.println("Found it!"); \
    Serial.println(y); \
    while(true) {} \
  } \
  display->gfx_PutPixel(X, y, PAINT); \
  y--;

#endif