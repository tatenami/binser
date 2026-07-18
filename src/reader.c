#include "c_api/reader.h"

void binser_reader_init(binser_reader_t *reader, uint8_t *buf, size_t capacity) {
  binser_buffer_init(reader->buffer, buf, capacity);
}

int binser_read(binser_reader_t *reader, uint8_t *buf, size_t size) {
  if (size == 0) {
    return 0;
  }

  size_t readable_size = binser_buffer_get_operatable_size(reader->buffer);
  if (readable_size < size) {
    return 0;
  }

  for (size_t i = 0; i < readable_size; i++) {
    buf[i] = reader->buffer->buf[reader->buffer->position + i];
  }
  
  reader->buffer->position += readable_size;
  
  return readable_size;
}