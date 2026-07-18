#ifndef VEC3_HPP
#define VEC3_HPP

#include "vec3.h"

template <class Codec>
void codec(Codec& codec, Vec3& vec) {
  codec(vec.x, vec.y, vec.z);
}

#endif // VEC3_HPP