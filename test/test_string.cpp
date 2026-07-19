#include <cstdio>
#include <cstring>
#include <string>
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

  string write_str = "Hello";
  string read_str;

  printf("Original string: %s (len=%d)\n", write_str.c_str(), write_str.length());

  codec(serializer, write_str);
  buf_dump(write_buf, 20);

  memcpy(read_buf, write_buf, 20);

  codec(deserializer, read_str);
  printf("Deserialized string: %s (len=%d)\n", read_str.c_str(), read_str.length());

  printf("\n");

  // C lang test
  printf("[C lang test]\n");

  binser_writer_clear(&writer);
  binser_reader_clear(&reader);

  char write_msg[20] = "Good Moring";
  char read_msg[20] = {};
  
  CString str_data = { .length = strlen(write_msg), .data = write_msg };
  CString str_rdata = { .length = 0, .data = read_msg };

  printf("Original str: %s (len=%d)\n", str_data.data, str_data.length);

  binser_write_u32(&writer, str_data.length);
  binser_write(&writer, (uint8_t *)(str_data.data), str_data.length);

  buf_dump(write_buf, 20);

  memcpy(read_buf, write_buf, 20);

  binser_read_u32(&reader, &(str_rdata.length));
  binser_read(&reader, (uint8_t *)(str_rdata.data), str_rdata.length);

  printf("Deserialized str: %s (len=%d)\n", str_rdata.data, str_rdata.length);

  return 0;
}
