#include <iostream>

int get_change(int m)
{
  //write your code here
  int coins[] { 10, 5, 1 };

  int coins_given {0}, current_coin {0};
  while (m > 0)
  {
    coins_given += static_cast<int>(m / coins[current_coin]);
    m %= coins[current_coin];
    ++current_coin;
  }

  return coins_given;
}

int main()
{
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
