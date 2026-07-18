#ifndef VEC2_HPP
#define VEC2_HPP

#include "vec2.h"

template <class Codec>
void codec(Codec& codec, Vec2& vec) {
  codec(vec.x, vec.y);
}

#endif // VEC2_HPP