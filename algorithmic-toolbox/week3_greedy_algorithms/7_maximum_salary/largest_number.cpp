#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

bool is_greater_or_equal(const string s, const string max_digit)
{
  string concat1 {s + max_digit};
  string concat2 {max_digit + s};

  return concat1.compare(concat2) >= 0;
}

string largest_number(vector<string> a)
{
  //write your code here
  std::stringstream ret;
  while(!a.empty())
  {
    int max_digit_idx {0};
    for (size_t i {1}; i < a.size(); ++i)
    {
      if (is_greater_or_equal(a[i], a[max_digit_idx]))
      {
        max_digit_idx = i;
      }
    }
    ret << a[max_digit_idx];
    a.erase(a.begin() + max_digit_idx, a.begin() + max_digit_idx + 1);
  }
  string result;
  ret >> result;
  return result;
}

int main()
{
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++)
  {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
