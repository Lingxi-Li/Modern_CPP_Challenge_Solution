#include <algorithm>

template <typename Less, typename T, typename... Ts>
constexpr const T& min(Less less, const T& a, const T& b, const Ts&... rems) {
  if constexpr (sizeof...(rems)) {
    return min(less, std::min(a, b, less), rems...);
  }
  else {
    return std::min(a, b, less);
  }
}
