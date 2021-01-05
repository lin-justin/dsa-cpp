#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

int binary_search(const vector<int> &a, int x)
{
  int left {0}, right {static_cast<int>(a.size() - 1)}; 
  
  while (left <= right)
  {
    int mid {(left + right) / 2};
    if (a.at(mid) == x)
    {
      return mid;
    }
    else if (a.at(mid) < x)
    {
      left = mid + 1;
    }
    else
    {
      right = mid - 1;
    }
  }
  return -1;
}

int linear_search(const vector<int> &a, int x)
{
  for (size_t i {0}; i < a.size(); ++i)
  {
    if (a.at(i) == x) { return i; }
  }
  return -1;
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i {0}; i < a.size(); i++)
  {
    std::cin >> a.at(i);
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i {0}; i < m; ++i)
  {
    std::cin >> b.at(i);
  }
  for (int i {0}; i < m; ++i)
  {
    //replace with the call to binary_search when implemented
    std::cout << binary_search(a, b.at(i)) << ' ';
  }
  std::cout << "\n";
}
