#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <cstring>
#include <limits>

using std::vector;
using std::string;
using std::max;
using std::min;

long long eval(long long a, long long b, char op)
{
  if (op == '*')
  {
    return a * b;
  }
  else if (op == '+')
  {
    return a + b;
  }
  else if (op == '-')
  {
    return a - b;
  } 
  else
  {
    assert(0);
  }
}

long long get_maximum_value(const string &exp)
{
  size_t size {exp.size()};
  size_t numOfnum {(size + 1) / 2};
  long long minArray[numOfnum][numOfnum];
  long long maxArray[numOfnum][numOfnum];

  std::memset(minArray, 0, sizeof(minArray));
  std::memset(maxArray, 0, sizeof(maxArray));

  for (size_t i {0}; i < numOfnum; ++i)
  {
    minArray[i][i] = std::stoll(exp.substr(2 * i, 1));
    maxArray[i][i] = std::stoll(exp.substr(2 * i, 1));
  }

  for (size_t s {0}; s < numOfnum - 1; ++s)
  {
    for (size_t i {0}; i < numOfnum - s - 1; ++i)
    {
      size_t j {i + s + 1};
      long long minVal {std::numeric_limits<long long>::max()};
      long long maxVal {std::numeric_limits<long long>::min()};

      for (size_t k {i}; k < j; ++k)
      {
        long long a {eval(minArray[i][k],minArray[k + 1][j],exp[2 * k + 1])};
        long long b {eval(minArray[i][k],maxArray[k + 1][j],exp[2 * k + 1])};
        long long c {eval(maxArray[i][k],minArray[k + 1][j],exp[2 * k + 1])};
        long long d {eval(maxArray[i][k],maxArray[k + 1][j],exp[2 * k + 1])};

        minVal = min(minVal, min(a, min(b, min(c,d))));
        maxVal = max(maxVal, max(a, max(b, max(c,d))));
      }
      minArray[i][j] = minVal;
      maxArray[i][j] = maxVal;
    }
  }
  return maxArray[0][numOfnum - 1];
}

int main()
{
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
