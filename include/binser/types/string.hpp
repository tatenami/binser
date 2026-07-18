#ifndef STRING_HPP
#define STRING_HPP

#include <string>
#include "cstring.h"

template <class Codec>
void codec(Codec& codec, std::string& str) {
  codec(str.length());
  for (size_t i = 0; i < str.length(); ++i) {
    codec(str[i]);
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