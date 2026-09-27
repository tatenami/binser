#include "c_api.h"

void binser_write_vec2(binser_writer_t *writer, Vec2 *vec) {
  binser_write_f32(writer, vec->x);
  binser_write_f32(writer, vec->y);
}

void binser_read_vec2(binser_reader_t *reader, Vec2 *vec) {
  binser_read_f32(reader, &(vec->x));
  binser_read_f32(reader, &(vec->y));
}

void binser_write_vec3(binser_writer_t *writer, Vec3 *vec) {
  binser_write_f32(writer, vec->x);
  binser_write_f32(writer, vec->y);
  binser_write_f32(writer, vec->z);
}

void binser_read_vec3(binser_reader_t *reader, Vec3 *vec) {
  binser_read_f32(reader, &(vec->x));
  binser_read_f32(reader, &(vec->y));
  binser_read_f32(reader, &(vec->z));
}

void binser_write_color(binser_writer_t *writer, ColorRGB *rgb) {
  binser_write_u8(writer, rgb->r);
  binser_write_u8(writer, rgb->g);
  binser_write_u8(writer, rgb->b);
}

void binser_read_color(binser_reader_t *reader, ColorRGB *rgb) {
  binser_read_u8(reader, &(rgb->r));
  binser_read_u8(reader, &(rgb->g));
  binser_read_u8(reader, &(rgb->b));
}

void binser_write_string(binser_writer_t *writer, CString *cstr) {
  binser_write_u32(writer, cstr->length);
  binser_write(writer, (uint8_t *)(cstr->data), cstr->length);
}

void binser_read_string(binser_reader_t *reader, CString *cstr) {
  binser_read_u32(reader, &(cstr->length));
  binser_read(reader, (uint8_t *)(cstr->data), cstr->length);
}
