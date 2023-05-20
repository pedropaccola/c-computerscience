#include <array>
#include <iostream>

int main() {
  std::array<int, 10> collection;
  std::cout << collection.size() << std::endl;
  for (int i : collection) {
    break;
  }
  return 0;
}
