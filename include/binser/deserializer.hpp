#ifndef DESERIALIZER_HPP
#define DESERIALIZER_HPP

#include "codec.hpp"
#include "c_api/reader.h"

#include <cstdio>

namespace binser 
{

class BinaryDeserializer: public Codec<BinaryDeserializer> {
 private:
  binser_reader_t &reader_;

 public:
  static constexpr bool is_saving = false; 

  BinaryDeserializer(binser_reader_t& reader): reader_(reader) {}

  void read_bytes(uint8_t *buf, size_t size) {
    binser_read(&reader_, buf, size);
  }

  // ユーザ定義型のデシリアライズ関数を呼び出す
  template <typename T>
  void process(T& value) {
    printf("Deserializing user-defined type...\n");
    codec(*this, value);
  }

  /* 基本型のデシリアライズ関数 */
  void process(uint8_t& value) {
    binser_read_u8(&reader_, &value);
    printf("Deserializing uint8_t: %u\n", value);
  }

  void process(int8_t& value) {
    binser_read_i8(&reader_, &value);
    printf("Deserializing int8_t: %d\n", value);
  }

  void process(uint16_t& value) {
    binser_read_u16(&reader_, &value);
    printf("Deserializing uint16_t: %u\n", value);
  }

  void process(int16_t& value) {
    binser_read_i16(&reader_, &value);
    printf("Deserializing int16_t: %d\n", value);
  }

  void process(uint32_t& value) {
    binser_read_u32(&reader_, &value);
    printf("Deserializing uint32_t: %u\n", value);
  }

  void process(int32_t& value) {
    binser_read_i32(&reader_, &value);
    printf("Deserializing int32_t: %d\n", value);
  }

  void process(uint64_t& value) {
    binser_read_u64(&reader_, &value);
    printf("Deserializing uint64_t: %llu\n", value);
  }

  void process(int64_t& value) {
    binser_read_i64(&reader_, &value);
    printf("Deserializing int64_t: %lld\n", value);
  }

  void process(float& value) {
    binser_read_f32(&reader_, &value);
    printf("Deserializing float: %f\n", value);
  }

  void process(double& value) {
    binser_read_f64(&reader_, &value);
    printf("Deserializing double: %f\n", value);
  }
};

}

#endif // DESERIALIZER_HPP