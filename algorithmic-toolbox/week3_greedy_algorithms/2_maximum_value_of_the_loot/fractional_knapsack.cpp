#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

double get_optimal_value(int capacity, std::vector<int> weights, std::vector<int> values)
{
  double value {0.0};
  std::vector<std::pair<int, int>> v;

  for (size_t i {0}; i < weights.size(); ++i)
  {
    v.push_back({weights[i], values[i]});
  }

  auto cmp = [](auto a, auto b) { return 1. * a.second / a.first > 1. * b.second/ b.first; };
  std::sort(v.begin(), v.end(), cmp);

  size_t i {0};
  while (capacity > 0 && i < weights.size())
  {
    value += std::min(capacity, v[i].first) * (1. * v[i].second / v[i].first);
    capacity -= std::min(capacity, v[i].first);
    ++i;
  }

  return value;
}

int main()
{
  int n;
  int capacity;
  std::cin >> n >> capacity;
  std::vector<int> values(n);
  std::vector<int> weights(n);
  for (int i {0}; i < n; i++)
  {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
