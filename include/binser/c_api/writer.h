#ifndef WRITER_H
#define WRITER_H

#include "buffer.h"

typedef struct {
  binser_buffer_t buffer;
} binser_writer_t;

void binser_writer_init(binser_writer_t *writer, uint8_t *buf, size_t capacity);
void binser_writer_clear(binser_writer_t *writer);
int binser_write(binser_writer_t *writer, uint8_t *buf, size_t size);

/* 基本型の書き込み関数 */
int binser_write_u8(binser_writer_t *writer, uint8_t value);
int binser_write_i8(binser_writer_t *writer, int8_t value);
int binser_write_u16(binser_writer_t *writer, uint16_t value);
int binser_write_i16(binser_writer_t *writer, int16_t value);
int binser_write_u32(binser_writer_t *writer, uint32_t value);
int binser_write_i32(binser_writer_t *writer, int32_t value);
int binser_write_u64(binser_writer_t *writer, uint64_t value);
int binser_write_i64(binser_writer_t *writer, int64_t value);
int binser_write_f32(binser_writer_t *writer, float value);
int binser_write_f64(binser_writer_t *writer, double value);

#endif // WRITER_H