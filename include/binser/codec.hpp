namespace binser 
{

template <class Derived>
class Codec {
  public:
  template <typename... types>
  void operator()(types&... args) {

  }

  protected:
  Derived& derived() {
    return static_cast<Derived&>(*this);
  }
};

}