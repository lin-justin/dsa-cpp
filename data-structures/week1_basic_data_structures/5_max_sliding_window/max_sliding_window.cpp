#include <iostream>
#include <vector>
#include <stack>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::max;

void max_sliding_window_naive(vector<int> const &A, int w)
{
    size_t size {A.size()};
    vector<size_t> max_window(size);

    std::stack<int> S;
    S.push(0);

    for (size_t i {1}; i < size; ++i)
    {
        while (!S.empty() && A[S.top()] < A[i])
        {
            max_window[S.top()] = i - 1;
            S.pop();
        }
        S.push(i);
    }

    while (!S.empty())
    {
        max_window[S.top()] = size - 1;
        S.pop();
    }
    size_t k {0};
    for (size_t i {0}; i <= size - w; ++i)
    {
        while (k < i || max_window[k] < i + w - 1)
        {
            ++k;
        }
        cout << A[k] << " ";
    }
    cout << endl;
    return;
}

int main()
{
    int n {0};
    cin >> n;

    vector<int> A(n);
    for (int i {0}; i < n; ++i)
    {
        cin >> A.at(i);
    }

    int w {0};
    cin >> w;

    max_sliding_window_naive(A, w);

    return 0;
}
