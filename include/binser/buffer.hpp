#include <cstdint>
namespace binser
{

class BinaryBuffer {
 private:
  uint8_t *data_;
  uint32_t capacity_;
  uint32_t pos_; // same mean: "index"

 public:
  BinaryBuffer(uint8_t *data, uint32_t capacity);
  uint8_t* data() { return data_; }
  uint32_t capacity() { return capacity_; }
  uint32_t position() { return pos_; }

  int read(uint8_t *buf, uint32_t size);
  int write(uint8_t *buf, uint32_t size);
};

}