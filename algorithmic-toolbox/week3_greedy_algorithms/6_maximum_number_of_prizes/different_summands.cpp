#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n)
{
  vector<int> summands;
  int total_candies {0};
  for (int k {1}; total_candies + k <= n; ++k)
  {
    summands.push_back(k);
    total_candies += k;
  }

  size_t last {summands.size() - 1};
  summands[last] += (n - total_candies);
  return summands;
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> summands {optimal_summands(n)};
  std::cout << summands.size() << '\n';
  for (size_t i {0}; i < summands.size(); ++i)
  {
    std::cout << summands[i] << ' ';
  }
  std::cout << std::endl;
}
