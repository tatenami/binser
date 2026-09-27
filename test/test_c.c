#include <stdio.h>
#include <string.h>
#include "../include/c_api.h"
#include "../include/types/types.h"

uint8_t write_buf[20] = {};
uint8_t read_buf[20] = {};

void buf_dump(binser_buffer_t *buffer) {
  for (int i = 0; i < buffer->position; i++) {
    printf("%02X ", buffer->buf[i]);
  }
  printf("\n");
}

void write_vec2(binser_writer_t *writer, Vec2 *vec) {
  binser_write_f32(writer, vec->x);
  binser_write_f32(writer, vec->y);
}

void read_vec2(binser_reader_t *reader, Vec2 *vec) {
  binser_read_f32(reader, &(vec->x));
  binser_read_f32(reader, &(vec->y));
}

void write_color(binser_writer_t *writer, ColorRGB *rgb) {
  binser_write_u8(writer, rgb->r);
  binser_write_u8(writer, rgb->g);
  binser_write_u8(writer, rgb->b);
}

void read_color(binser_reader_t *reader, ColorRGB *rgb) {
  binser_read_u8(reader, &(rgb->r));
  binser_read_u8(reader, &(rgb->g));
  binser_read_u8(reader, &(rgb->b));
}

void write_string(binser_writer_t *writer, CString *cstr) {
  binser_write_u32(writer, cstr->length);
  binser_write(writer, (uint8_t *)(cstr->data), cstr->length);
}

void read_string(binser_reader_t *reader, CString *cstr) {
  binser_read_u32(reader, &(cstr->length));
  binser_read(reader, (uint8_t *)(cstr->data), cstr->length);
}

int main() {
  binser_writer_t writer;
  binser_reader_t reader;

  binser_writer_init(&writer, write_buf, 20);
  binser_reader_init(&reader, read_buf, 20);
  
  // Vector
  Vec2 vec = {1.0f, 2.0f};
  Vec2 read_vec;
  printf("Original Vec2: x = %f, y = %f\n", vec.x, vec.y);
  
  write_vec2(&writer, &vec);
  buf_dump(&(writer.buffer));

  // 書き込まれたバッファを読み込み用のバッファにコピー
  for (size_t i = 0; i < writer.buffer.position; i++) {
    read_buf[i] = write_buf[i];
  }

  read_vec2(&reader, &read_vec);
  printf("Read Vec2: x = %f, y = %f\n", read_vec.x, read_vec.y);
  binser_buffer_clear(&(writer.buffer));
  binser_buffer_clear(&(reader.buffer));

  // COLOR
  ColorRGB rgb = {150, 200, 100};
  ColorRGB read_rgb;
  printf("Original Color: r = %d, g = %d, b = %d\n", rgb.r, rgb.g, rgb.b);

  write_color(&writer, &rgb);
  buf_dump(&(writer.buffer));

  // 書き込まれたバッファを読み込み用のバッファにコピー
  for (size_t i = 0; i < writer.buffer.position; i++) {
    read_buf[i] = write_buf[i];
  }

  read_color(&reader, &read_rgb);
  printf("Read Color: r = %d, g = %d, b = %d\n", read_rgb.r, read_rgb.g, read_rgb.b);
  binser_buffer_clear(&(writer.buffer));
  binser_buffer_clear(&(reader.buffer));

  // String
  char *msg = "hello";
  char msg_buf[10] = {0};
  CString cstr = {(uint32_t)strlen(msg), msg};
  CString read_cstr = {0, msg_buf};
  printf("Original String: length = %d, str = '%s'\n", cstr.length, cstr.data);

  write_string(&writer, &cstr);
  buf_dump(&(writer.buffer));

  // 書き込まれたバッファを読み込み用のバッファにコピー
  for (size_t i = 0; i < writer.buffer.position; i++) {
    read_buf[i] = write_buf[i];
  }

  read_string(&reader, &read_cstr);
  printf("Read String: length = %d, str = '%s'\n", read_cstr.length, read_cstr.data);
  binser_buffer_clear(&(writer.buffer));
  binser_buffer_clear(&(reader.buffer));

  return 0;
}
