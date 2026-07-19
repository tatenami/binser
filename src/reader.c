#include "c_api/reader.h"
#include <stdio.h>

void binser_reader_init(binser_reader_t *reader, uint8_t *buf, size_t capacity) {
  binser_buffer_init(&(reader->buffer), buf, capacity);
}

void binser_reader_clear(binser_reader_t *reader) {
  binser_buffer_clear(&(reader->buffer));
}

int binser_read(binser_reader_t *reader, uint8_t *buf, size_t size) {
  if (size == 0) {
    return 0;
  }

  size_t readable_size = binser_buffer_get_operatable_size(&(reader->buffer));
  if (readable_size < size) {
    return 0;
  }

  for (size_t i = 0; i < size; i++) {
    buf[i] = reader->buffer.buf[reader->buffer.position + i];
  }
  
  reader->buffer.position += size;

  return readable_size;
}

/* 基本型の読み込み関数 */
int binser_read_u8(binser_reader_t *reader, uint8_t *value) {
  return binser_read(reader, (uint8_t*)value, sizeof(*value));
}

int binser_read_i8(binser_reader_t *reader, int8_t *value) {
  return binser_read(reader, (uint8_t*)value, sizeof(*value));
}

int binser_read_u16(binser_reader_t *reader, uint16_t *value) {
  return binser_read(reader, (uint8_t*)value, sizeof(*value));
}

int binser_read_i16(binser_reader_t *reader, int16_t *value) {
  return binser_read(reader, (uint8_t*)value, sizeof(*value));
}

int binser_read_u32(binser_reader_t *reader, uint32_t *value) {
  return binser_read(reader, (uint8_t*)value, sizeof(*value));
}

int binser_read_i32(binser_reader_t *reader, int32_t *value) {
  return binser_read(reader, (uint8_t*)value, sizeof(*value));
}

int binser_read_u64(binser_reader_t *reader, uint64_t *value) {
  return binser_read(reader, (uint8_t*)value, sizeof(*value));
}

int binser_read_i64(binser_reader_t *reader, int64_t *value) {
  return binser_read(reader, (uint8_t*)value, sizeof(*value));
}

int binser_read_f32(binser_reader_t *reader, float *value) {
  return binser_read(reader, (uint8_t*)value, sizeof(*value));
}

int binser_read_f64(binser_reader_t *reader, double *value) {
  return binser_read(reader, (uint8_t*)value, sizeof(*value));
}
