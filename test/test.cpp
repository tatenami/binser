#include <cstdio>
#include "../include/binser/serializer.hpp"
#include "../include/binser/deserializer.hpp"

#include "../include/binser/types.hpp"
#include <string>

// struct Vec2 {
//   float x;
//   float y;
// };

// template <class Codec>
// void codec(Codec& codec, Vec2& vec) {
//   codec(vec.x, vec.y);
// }

uint8_t write_buf[20];
uint8_t read_buf[20];

int main() {
  binser_writer_t writer;
  binser_reader_t reader;

  binser_writer_init(&writer, write_buf, sizeof(write_buf));
  binser_reader_init(&reader, read_buf, sizeof(read_buf));

  binser::BinarySerializer serializer(writer);
  binser::BinaryDeserializer deserializer(reader);

  Vec2 vec{1.0f, 2.0f};

  printf("Original Vec2: x = %f, y = %f\n", vec.x, vec.y);

  codec(serializer, vec);

  // 書き込まれたバッファを表示
  printf("Written bytes = %d\n", writer.buffer.position);
  printf("Written buffer:\n");
  for (size_t i = 0; i < writer.buffer.position; i++) {
    printf("%02x ", write_buf[i]);
  }
  printf("\n");

  // 書き込まれたバッファを読み込み用のバッファにコピー
  for (size_t i = 0; i < sizeof(write_buf); i++) {
    read_buf[i] = write_buf[i];
  }

  Vec2 vec_read;
  codec(deserializer, vec_read);

  // 読み込まれた値を表示
  printf("Deserialized Vec2: x = %f, y = %f\n", vec_read.x, vec_read.y);
  printf("\n");

  // 文字列テスト
  std::string str = "Hello";
  uint8_t str_write_buf[20];
  uint8_t str_read_buf[20];

  binser_writer_t str_writer;
  binser_reader_t str_reader;
  binser_writer_init(&str_writer, str_write_buf, sizeof(str_write_buf));
  binser_reader_init(&str_reader, str_read_buf, sizeof(str_read_buf));

  binser::BinarySerializer str_serializer(str_writer);
  binser::BinaryDeserializer str_deserializer(str_reader);

  printf("Original str = '%s'\n", str.c_str());

  codec(str_serializer, str);

  printf("Written bytes = %d\n", writer.buffer.position);

  // 書き込まれたバッファを表示
  printf("Written string buffer:\n");
  for (size_t i = 0; i < str_writer.buffer.position; i++) {
    printf("%02x ", str_write_buf[i]);
  }

  printf("\n");
  // 書き込まれたバッファを読み込み用のバッファにコピー
  for (size_t i = 0; i < sizeof(str_write_buf); i++) {
    str_read_buf[i] = str_write_buf[i];
  }

  std::string str_read;
  codec(str_deserializer, str_read);
  printf("Deserialized string: %s\n", str_read.c_str());

  return 0;
}