#include <cstddef>
#include <stdint.h>
#include <meta>
#include <type_traits>
#include <string_view>

#include <cstdio>
#include <iostream>

void print_indent(std::size_t depth) {
  for (std::size_t i = 0; i < depth; ++i) {
    std::printf("  ");
  }
}

template <typename T>
void serialize_array(const T& array, std::size_t size, std::size_t depth) {
  using type = std::remove_extent_t<T>;
  constexpr std::size_t type_size = sizeof(type);

  std::printf("[ ");

  for (int i = 0; i < size; i++) {
    // static_cast<type>(*(buffer->buf)) = array[i];
    // buffer->position += type_size;
    std::cout << array[i];

    if (i + 1 < size) {
      std::printf(", ");
    }
  }

  std::printf(" ]");
}

void serialize_string(const std::string_view& str) {
  std::printf("'%s'", str.data());
}

template <typename T>
void serialize(const T& value, std::size_t depth) {
  // constexpr std::meta::info info = ^^T;

  constexpr std::string_view name = std::meta::display_string_of(^^T);

  if constexpr (std::is_class_v<T>) { // T が class or struct 

    std::printf("<%s> {\n", name.data());

    static constexpr auto members = std::define_static_array(
      std::meta::nonstatic_data_members_of(^^T, std::meta::access_context::unchecked())
    );

    template for (
      constexpr auto member: members)
    {
      print_indent(depth + 1);

      constexpr auto member_name = std::meta::identifier_of(member);

      std::printf("%s: ", member_name.data());

      serialize(value.[:member:], depth + 1);

      std::printf("\n");
    }

    print_indent(depth);
    std::printf("}");
  }
  else if constexpr (std::is_array_v<T>) { // T が配列
    constexpr std::size_t size = std::extent_v<T>;
    using elem_t = std::remove_extent_t<T>;

    // elem_t が配列でなく，かつ is_class でないなら，直の for で展開
    if constexpr (std::is_same_v<std::remove_cv_t<elem_t>, char>) {
      std::printf("<%s> ", name.data());
      serialize_string(std::string_view{value, size});
    }
    else if constexpr (
      std::is_array_v<elem_t> || std::is_class_v<elem_t> 
    ) {
      std::printf("<%s> [\n", name.data());

      for (int i = 0; i < size; i++) {
        print_indent(depth + 1);

        serialize(value[i], depth + 1);

        if (i + 1 < size) {
          std::printf(",");
        }

        std::printf("\n");
      }

      print_indent(depth);
      std::printf("]");
    }
    else {
      std::printf("<%s> ", name.data());
      serialize_array(value, size, depth);
    }
  }
  else { // 基本型
    std::printf("<%s> ", name.data());
    std::cout << value;
  }
}