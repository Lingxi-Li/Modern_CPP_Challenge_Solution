#include <utility>

template <typename Container, typename... Ts>
void push_back(Container& c, Ts&&... vs) {
  ( ..., c.push_back(std::forward<Ts>(vs)) );
}
