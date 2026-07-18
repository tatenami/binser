#ifndef READER_H
#define READER_H

#include "buffer.h"

typedef struct {
  binser_buffer_t buffer;
} binser_reader_t;

void binser_reader_init(binser_reader_t *reader, uint8_t *buf, size_t capacity);
int binser_read(binser_reader_t *reader, uint8_t *buf, size_t size);

/* 基本型の読み込み関数 */
int binser_read_u8(binser_reader_t *reader, uint8_t *value);
int binser_read_i8(binser_reader_t *reader, int8_t *value);
int binser_read_u16(binser_reader_t *reader, uint16_t *value); 
int binser_read_i16(binser_reader_t *reader, int16_t *value);
int binser_read_u32(binser_reader_t *reader, uint32_t *value);
int binser_read_i32(binser_reader_t *reader, int32_t *value);
int binser_read_u64(binser_reader_t *reader, uint64_t *value);
int binser_read_i64(binser_reader_t *reader, int64_t *value);
int binser_read_f32(binser_reader_t *reader, float *value);
int binser_read_f64(binser_reader_t *reader, double *value);

#endif // READER_H