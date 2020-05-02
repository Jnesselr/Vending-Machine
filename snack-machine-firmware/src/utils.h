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

#define DEBUG(text) if(true) { Serial.println(text); }

#define COPY(a, b, length) \
  for(uint8_t i = 0; i < length; i++) { \
    b[i] = a[i]; \
  }

typedef void (*VoidCallback)();

#endif