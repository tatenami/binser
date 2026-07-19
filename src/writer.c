#include "c_api/writer.h"

#include <stdio.h>

void binser_writer_init(binser_writer_t *writer, uint8_t *buf, size_t capacity) {
  binser_buffer_init(&(writer->buffer), buf, capacity);
}

void binser_writer_clear(binser_writer_t *writer) {
  binser_buffer_clear(&(writer->buffer));
}


int binser_write(binser_writer_t *writer, uint8_t *buf, size_t size) {
  if (size == 0) {
    return 0;
  }

  size_t writable_size = binser_buffer_get_operatable_size(&(writer->buffer));
  if (writable_size < size) {
    return 0;
  }

  for (size_t i = 0; i < size; i++) {
    writer->buffer.buf[writer->buffer.position + i] = buf[i];
  }

  writer->buffer.position += size;
  
  return size;
}

/* 基本型の書き込み関数 */
int binser_write_u8(binser_writer_t *writer, uint8_t value) {
  return binser_write(writer, (uint8_t*)&value, sizeof(value));
}

int binser_write_i8(binser_writer_t *writer, int8_t value) {
  return binser_write(writer, (uint8_t*)&value, sizeof(value));
}

int binser_write_u16(binser_writer_t *writer, uint16_t value) {
  return binser_write(writer, (uint8_t*)&value, sizeof(value));
}

int binser_write_i16(binser_writer_t *writer, int16_t value) {
  return binser_write(writer, (uint8_t*)&value, sizeof(value));
}

int binser_write_u32(binser_writer_t *writer, uint32_t value) {
  return binser_write(writer, (uint8_t*)&value, sizeof(value));
}

int binser_write_i32(binser_writer_t *writer, int32_t value) {
  return binser_write(writer, (uint8_t*)&value, sizeof(value));
}

int binser_write_u64(binser_writer_t *writer, uint64_t value) {
  return binser_write(writer, (uint8_t*)&value, sizeof(value));
}

int binser_write_i64(binser_writer_t *writer, int64_t value) {
  return binser_write(writer, (uint8_t*)&value, sizeof(value));
}

int binser_write_f32(binser_writer_t *writer, float value) {
  return binser_write(writer, (uint8_t*)&value, sizeof(value));
}

int binser_write_f64(binser_writer_t *writer, double value) {
  return binser_write(writer, (uint8_t*)&value, sizeof(value));
}
