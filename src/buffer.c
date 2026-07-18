#include "c_api/buffer.h"

void binser_buffer_init(
  binser_buffer_t *buffer, 
  uint8_t* buf,
  size_t capacity
) {
  buffer->buf = buf;
  buffer->capacity = capacity;
  buffer->position = 0;
}

size_t binser_buffer_get_operatable_size(binser_buffer_t *buffer) {
  return (buffer->capacity - buffer->position);
}
  
