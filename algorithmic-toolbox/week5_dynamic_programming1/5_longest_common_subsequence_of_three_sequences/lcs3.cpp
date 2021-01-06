#include <iostream>
#include <vector>

using std::vector;

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c)
{
  size_t m {a.size()};
  size_t n {b.size()};
  size_t o {c.size()};

  vector<vector<vector<int>>> L(m + 1, vector<vector<int>>(n + 1, vector<int>(o + 1, 0)));

  for (size_t i {0}; i <= m; i++)
  {
    for (size_t j {0}; j <= n; j++)
    {
      for (size_t k {0}; k<= o; k++)
      {
        if (i == 0 || j == 0 || k == 0)
        {
          L[i][j][k] = 0;
        }
        else if (a[i - 1] == b[j - 1] && a[i - 1] == c[k - 1])
        {
          L[i][j][k] = L[i - 1][j - 1][k - 1] + 1;
        }
        else
        {
          L[i][j][k] = std::max(std::max(L[i - 1][j][k], L[i][j - 1][k]), L[i][j][k - 1]);
        }
        
      }
    }
  }
  return L[m][n][o];
}

int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i {0}; i < an; i++)
  {
    std::cin >> a[i];
  }

  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i {0}; i < bn; i++)
  {
    std::cin >> b[i];
  }
  
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i {0}; i < cn; i++)
  {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << std::endl;
}
