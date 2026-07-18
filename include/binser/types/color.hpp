#ifndef COLOR_HPP
#define COLOR_HPP

#include "color.h"

template <class Codec>
void codec(Codec& codec, ColorRGB& color) {
  codec(color.r, color.g, color.b);
}

template <class Codec>
void codec(Codec& codec, ColorRGBA& color) {
  codec(color.r, color.g, color.b, color.a);
}

#endif // COLOR_HPP