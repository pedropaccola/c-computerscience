#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

class StackWithMax {
private:
  std::vector<int> stack;
  std::vector<int> misses;
  int miss = 0;

public:
  void Push(int value) {
    if (stack.empty() || value >= stack.back()) {
      stack.push_back(value);
      misses.push_back(miss);
      miss = 0;
    } else {
      miss++;
    }
  }

  void Pop() {
    assert(stack.size());
    if (miss > 0) {
      miss--;
    } else {
      stack.pop_back();
      miss = misses.back();
      misses.pop_back();
    }
  }

  int Max() const {
    assert(stack.size());
    return stack.back();
  }
};

int main() {
  int num_queries = 0;
  std::cin >> num_queries;

  std::string query;
  std::string value;

  StackWithMax stack;

  for (int i = 0; i < num_queries; ++i) {
    std::cin >> query;
    if (query == "push") {
      std::cin >> value;
      stack.Push(std::stoi(value));
    } else if (query == "pop") {
      stack.Pop();
    } else if (query == "max") {
      std::cout << stack.Max() << "\n";
    } else {
      assert(0);
    }
  }
  return 0;
}
