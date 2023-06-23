#include <algorithm>
#include <iostream>

void max_sliding_window_naive(const int *array, int n, int m) {
  for (size_t i = 0; i < n - m + 1; i++) {
    int window_max = array[i];
    for (size_t j = i + 1; j < i + m; j++)
      window_max = std::max(window_max, array[j]);

    std::cout << window_max << " ";
  }
  std::cout << std::endl;
  return;
}

int main() {
  int n = 0;
  std::cin >> n;

  // std::vector<int> array(n);
  int array[n];
  for (size_t i = 0; i < n; ++i)
    // std::cin >> array.at(i);
    std::cin >> array[i];

  int m = 0;
  std::cin >> m;

  max_sliding_window_naive(array, n, m);

  return 0;
}
