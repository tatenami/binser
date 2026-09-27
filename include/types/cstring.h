#ifndef CSTRING_H
#define CSTRING_H

#include <stdint.h>

typedef struct {
  uint32_t length;
  char *data;
} CString;

#endif // CSTRING_H