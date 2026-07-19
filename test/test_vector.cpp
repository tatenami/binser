#include <cstdio>
#include <cstring>
#include "../include/binser/serializer.hpp"
#include "../include/binser/deserializer.hpp"
#include "../include/binser/types.hpp"

using namespace std;
using namespace binser;

uint8_t write_buf[20];
uint8_t read_buf[20];

void buf_dump(uint8_t *buf, size_t size) {
  for (int i = 0; i < size; i++) {
    printf("%#x ", buf[i]);
  }
  printf("\n");
}

int main() {
  binser_writer_t writer;
  binser_reader_t reader;

  binser_writer_init(&writer, write_buf, 20);
  binser_reader_init(&reader, read_buf, 20);

  BinarySerializer serializer(writer);
  BinaryDeserializer deserializer(reader);

  Vec3 test_vec3 = { .x = 5.0f, .y = 9.0f, .z = 3.0f };
  Vec3 read_vec3;

  printf("Original Vec3: x=%f. y=%f, z=%f\n", test_vec3.x, test_vec3.y, test_vec3.z);

  codec(serializer, test_vec3);
  buf_dump(write_buf, 20);

  memcpy(read_buf, write_buf, 20);

  codec(deserializer, read_vec3);
  printf("Deserialized Vec3: x=%f. y=%f, z=%f\n", read_vec3.x, read_vec3.y, read_vec3.z);

  return 0;
}
