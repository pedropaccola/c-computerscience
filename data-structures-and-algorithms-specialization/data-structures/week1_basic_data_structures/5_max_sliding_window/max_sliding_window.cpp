#include <deque>
#include <iostream>

void max_sliding_window_naive(const int *array, int n, int m) {
  std::deque<int> max_index;
  for (int i = 0; i < m; i++) {
    while (!max_index.empty() && array[i] >= array[max_index.back()]) {
      max_index.pop_back();
    }
    max_index.push_back(i);
  }

  for (int i = m; i < n; i++) {
    std::cout << array[max_index.front()] << " ";

    while (!max_index.empty() && max_index.front() <= i - m) {
      max_index.pop_front();
    }

    while (!max_index.empty() && array[i] >= array[max_index.back()]) {
      max_index.pop_back();
    }
    max_index.push_back(i);
  }

  std::cout << array[max_index.front()] << std::endl;
  return;
}

int main() {
  int n = 0;
  std::cin >> n;

  int array[n];
  for (size_t i = 0; i < n; ++i)
    std::cin >> array[i];

  int m = 0;
  std::cin >> m;

  max_sliding_window_naive(array, n, m);

  return 0;
}
