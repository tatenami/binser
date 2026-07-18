#include "buffer.h"

typedef struct {
  binser_buffer_t *buffer;
} binser_writer_t;

void binser_writer_init(binser_writer_t *writer, uint8_t *buf, size_t capacity);
int binser_write(binser_writer_t *writer, uint8_t *buf, size_t size);
