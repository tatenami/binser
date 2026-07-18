#ifndef CODEC_HPP
#define CODEC_HPP

namespace binser 
{

template <class Derived>
class Codec {
  public:
  template <typename... types>
  void operator()(types&... args) {
    (derived().process(args), ...);
  }

  protected:
  Derived& derived() {
    return static_cast<Derived&>(*this);
  }
};

}

#endif // CODEC_HPP