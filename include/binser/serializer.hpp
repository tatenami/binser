#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "codec.hpp"
#include "c_api/writer.h"

#include <cstdio>

namespace binser 
{

class BinarySerializer: public Codec<BinarySerializer> {
 private:
  binser_writer_t &writer_;

 public:
  static constexpr bool is_saving = true;

  BinarySerializer(binser_writer_t& writer): writer_(writer) {}

  void write_bytes(const uint8_t *buf, size_t size) {
    binser_write(&writer_, (uint8_t*)buf, size);
  }

  // ユーザ定義型のシリアライズ関数を呼び出す
  template <typename T>
  void process(T& value) {
    printf("Serializing user-defined type...\n");
    codec(*this, value);
  }

  /* 基本型のシリアライズ関数 */
  void process(uint8_t& value) {
    printf("Serializing uint8_t: %u\n", value);
    binser_write_u8(&writer_, value);
  }

  void process(int8_t& value) {
    printf("Serializing int8_t: %d\n", value);
    binser_write_i8(&writer_, value);
  }

  void process(uint16_t& value) {
    printf("Serializing uint16_t: %u\n", value);
    binser_write_u16(&writer_, value);
  }

  void process(int16_t& value) {
    printf("Serializing int16_t: %d\n", value);
    binser_write_i16(&writer_, value);
  }

  void process(uint32_t& value) {
    printf("Serializing uint32_t: %u\n", value);
    binser_write_u32(&writer_, value);
  }

  void process(int32_t& value) {
    printf("Serializing int32_t: %d\n", value);
    binser_write_i32(&writer_, value);
  }

  void process(uint64_t& value) {
    printf("Serializing uint64_t: %llu\n", value);
    binser_write_u64(&writer_, value);
  }

  void process(int64_t& value) {
    printf("Serializing int64_t: %lld\n", value);
    binser_write_i64(&writer_, value);
  }

  void process(float& value) {
    printf("Serializing float: %f\n", value);
    binser_write_f32(&writer_, value);
  }

  void process(double& value) {
    printf("Serializing double: %f\n", value);  
    binser_write_f64(&writer_, value);
  }
};

}
#endif // SERIALIZER_HPP