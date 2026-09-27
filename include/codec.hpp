#ifndef CODEC_HPP
#define CODEC_HPP

namespace binser 
{

template <class Derived>
class Codec {
  public:
  template <typename... types>
  void operator()(types&... args) {
    // 畳み込みパック展開
    (derived().process(args), ...);
    /*
    (
      derived().process(arg1),
      derived().process(arg2),
    );
    */
  }

  protected:
  Derived& derived() {
    return static_cast<Derived&>(*this);
  }
};

}

#endif // CODEC_HPP