#ifndef STRING_HPP
#define STRING_HPP

#include <string>
#include <memory>
#include "cstring.h"

template <class Codec>
void codec(Codec& codec, std::string& str) {
  // for (size_t i = 0; i < str.length(); ++i) {
  //   codec(str[i]);
  // }

  if constexpr (Codec::is_saving) {
    // 先頭に長さを書き込む (uint32_t)
    uint32_t length = static_cast<uint32_t>(str.length());
    codec(length);
    uint8_t* data_ptr = (uint8_t*)str.c_str();
    codec.write_bytes(data_ptr, str.length());
  } else {
    // 先頭の長さを読み込む (uint32_t)
    uint32_t length;
    codec(length);

    // 文字列の長さに応じて別のバッファ (uint8_t*) を確保し読み込む
    std::unique_ptr<uint8_t[]> buffer = std::make_unique<uint8_t[]>(length);
    codec.read_bytes(buffer.get(), length);

    // 読み込んだバッファを1byteずつ std::string に変換
    str.clear();
    for (size_t i = 0; i < length; ++i) {
      str.push_back(static_cast<char>(buffer[i]));
    }
    str.push_back('\0');
  }
}

template <class Codec>
void codec(Codec& codec, CString& cstr) {
  codec(cstr.length);
  for (size_t i = 0; i < cstr.length; ++i) {
    codec(cstr.data[i]);
  }
}

#endif // STRING_HPP