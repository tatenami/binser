#include "buffer.hpp"

namespace binser
{

BinaryBuffer::BinaryBuffer(uint8_t *data, uint32_t capacity):
  data_(data), capacity_(capacity), pos_(0) {

}

int BinaryBuffer::read(uint8_t *buf, uint32_t size) {
  if (size == 0) {
    return 0;
  }

  uint32_t readable_size = (capacity_ - pos_);
  if (readable_size < size) {
    return 0;
  }

  for (uint32_t i = 0; i < readable_size; i++) {
    buf[i] = data_[pos_];
    pos_++;
  }

  return readable_size;
}

int BinaryBuffer::write(uint8_t *buf, uint32_t size) {
  if (size == 0) {
    return 0;
  }

  uint32_t writeable_size = (capacity_ - pos_);
  if (writeable_size < size) {
    return 0;
  }

  for (uint32_t i = 0; i < writeable_size; i++) {
    data_[pos_] = buf[i];
    pos_++;
  }

  return writeable_size;
}

}