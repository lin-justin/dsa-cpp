#include <iostream>
#include <vector>
#include <limits>

int get_change(int m)
{
  std::vector<int> coins {1, 3, 4};
  std::vector<int> dp(m + 11, std::numeric_limits<int>::max());

  dp[0] = 0;
  dp[1] = 1;
  dp[3] = 1;
  dp[4] = 1;

  for (int i {2}; i <= m; i++)
  {
    for (auto j : coins)
    {
      if (i - j >= 0)
      {
        dp[i] = std::min(dp[i], dp[i - j] + 1);
      }
    }
  }
  return dp[m];
}

int main()
{
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
