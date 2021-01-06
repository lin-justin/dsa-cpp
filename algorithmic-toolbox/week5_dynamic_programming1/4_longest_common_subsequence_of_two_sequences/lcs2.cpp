#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <iterator>

using std::vector;
using std::string;

int lcs(vector<int> &a, vector<int> &b)
{
    size_t m {a.size()};
    size_t n {b.size()};

    vector<vector<int> >L(m + 1 , vector<int>(n + 1 , 0));

    for (size_t i {0}; i <= m; i++)
    {
        for (size_t j {0}; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                L[i][j] = 0;
            }
            else if (a[i-1] == b[j-1])
            {
                L[i][j] = L[i-1][j-1] + 1;
            }
            else
            {
                L[i][j] = std::max(L[i-1][j], L[i][j-1]);
            }
        }
    }
    return L[m][n];
}

int main()
{
    int m;
    std::cin >> m;

    vector<int> a(m);
    for (int i {0}; i < m; ++i)
    {
        std::cin >> a[i];
    }

    int n;
    std::cin >> n;

    vector<int> b(n);
    for (int i {0}; i < n; ++i)
    {
        std::cin >> b[i];
    }

    std::cout << lcs(a, b) << std::endl;

    return 0;
}
