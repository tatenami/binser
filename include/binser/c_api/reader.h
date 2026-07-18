#include "buffer.h"

typedef struct {
  binser_buffer_t *buffer;
} binser_reader_t;

void binser_reader_init(binser_reader_t *reader, uint8_t *buf, size_t capacity);
int binser_read(binser_reader_t *reader, uint8_t *buf, size_t size);
