#include <iostream>

// long long lcm_naive(int a, int b) {
//   for (long l = 1; l <= (long long) a * b; ++l)
//     if (l % a == 0 && l % b == 0)
//       return l;

//   return (long long) a * b;
// }

int euclid_gcd(int a, int b)
{
  if (b == 0)
  {
    return a;
  }

  return euclid_gcd(b, a % b);
}

long long lcm(long long a, long long b)
{
  return (a * b) / euclid_gcd(a, b);
}

int main()
{
  long long a, b;
  std::cin >> a >> b;
  std::cout << lcm(a, b) << std::endl;
  return 0;
}
