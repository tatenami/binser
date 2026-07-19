#ifndef BUFFER_H
#define BUFFER_H

#include <stdint.h>
#include <stddef.h>

typedef struct {
  uint8_t *buf;
  size_t capacity;
  size_t position;
} binser_buffer_t;

void binser_buffer_init(
  binser_buffer_t *buffer, 
  uint8_t* buf,
  size_t capacity
);

void binser_buffer_clear(binser_buffer_t *buffer);

size_t binser_buffer_get_operatable_size(binser_buffer_t *buffer);

#endif // BUFFER_H