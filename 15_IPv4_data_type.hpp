#include <cctype>
#include <cstdint>
#include <initializer_list>
#include <iostream>
#include <sstream>
#include <string>
#include <type_traits>
#include <utility>

class ipv4addr {
public:
  ipv4addr(std::uint32_t value = 0) noexcept
    : value(value) {}

  template <typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
  ipv4addr(std::initializer_list<T> parts) noexcept {
    for (auto part : parts) {
      value = (value << 8) + static_cast<std::uint8_t>(part);
    }
  }
  
  ipv4addr(const char* str) noexcept {
    std::uint32_t acc = 0;
    do {
      if (std::isdigit(*str)) {
        acc = acc * 10 + (*str - '0');
      }
      else {
        value = (value << 8) + std::exchange(acc, 0);
      }
    }
    while (*str++);
  }
    
  ipv4addr(const std::string& str) noexcept
    : ipv4addr(str.c_str()) {}
  
  std::uint32_t to_uint32() const noexcept {
    return value;
  }
  
  std::string to_string() const {
    std::ostringstream os;
    os << *this;
    return os.str();
  }
    
  friend std::ostream& operator<<(std::ostream& os, ipv4addr addr) {
    return os << (addr.value >> 24)        << '.'
              << (addr.value >> 16 & 0xFF) << '.'
              << (addr.value >> 8 & 0xFF)  << '.'
              << (addr.value & 0xFF);
  }
  
private:
  std::uint32_t value{};
};
