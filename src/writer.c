#include "c_api/writer.h"

void binser_writer_init(binser_writer_t *writer, uint8_t *buf, size_t capacity) {
  binser_buffer_init(writer->buffer, buf, capacity);
}

int binser_write(binser_writer_t *writer, uint8_t *buf, size_t size) {
  if (size == 0) {
    return 0;
  }

  size_t writable_size = binser_buffer_get_operatable_size(writer->buffer);
  if (writable_size < size) {
    return 0;
  }

  for (size_t i = 0; i < size; i++) {
    writer->buffer->buf[writer->buffer->position + i] = buf[i];
  }

  writer->buffer->position += size;

  return size;
}