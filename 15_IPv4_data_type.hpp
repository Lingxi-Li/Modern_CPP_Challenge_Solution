#include <cctype>
#include <cstdint>
#include <iostream>
#include <string>
#include <utility>

class ipv4addr {
public:
  ipv4addr(std::uint32_t value = 0) noexcept
    : value(value) {}

  ipv4addr(const char* str) noexcept {
    std::uint32_t acc = 0;
    do {
      if (std::isdigit(*str)) {
        acc = acc * 10 + (*str - '0');
      }
      else {
        value = value * 256 + std::exchange(acc, 0);
      }
    }
    while (*str++);
  }
    
  ipv4addr(const std::string& str) noexcept
    : ipv4addr(str.c_str()) {}
  
  std::uint32_t to_uint32() const noexcept {
    return value;
  }
    
  friend std::ostream& operator<<(std::ostream& os, ipv4addr addr) {
    constexpr std::uint32_t bases[] = { 256 * 256 * 256, 256 * 256, 256 };
    auto val = addr.value;
    for (auto base : bases) {
      os << val / base << '.';
      val = val % base;
    }
    return os << val;
  }
  
private:
  std::uint32_t value{};
};
