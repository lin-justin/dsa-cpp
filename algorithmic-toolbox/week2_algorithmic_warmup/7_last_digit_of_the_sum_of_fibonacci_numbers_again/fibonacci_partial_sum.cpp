#include <iostream>
#include <vector>
using std::vector;

// long long get_fibonacci_partial_sum_naive(long long from, long long to) {
//     long long sum = 0;

//     long long current = 0;
//     long long next  = 1;

//     for (long long i = 0; i <= to; ++i) {
//         if (i >= from) {
//             sum += current;
//         }

//         long long new_current = next;
//         next = next + current;
//         current = new_current;
//     }

//     return sum % 10;
// }

long long int get_pisano_period(long long m)
{
    long long a {0}, b {1}, c {a + b};
    for (int i {0}; i < m * m; ++i)
    {
        c = (a + b) % m;
        a = b;
        b = c;
        if (a == 0 && b == 1)
        {
            return i + 1;
        }
    }
}

long long int get_fibonacci_mod(long long int n, long long int m)
{
    if (n <= 1) { return n; }

    long long int previous {0};
    long long int current {1};

    for (long long i {2}; i <= n; ++i)
    {
        long long int tmp_previous {previous};
        previous = current;
        current = (tmp_previous + current) % m;
    }
    
    return current;
}

long long int get_fibonacci_huge_opt(long long int n, long long int m)
{
    long long int period {get_pisano_period(m)};
    long long remainder {n % period};
    return get_fibonacci_mod(remainder, m);
}

int fibonacci_sum(long long int n)
{
    return (get_fibonacci_huge_opt(n + 2, 100) - 1) % 10;
}

long long get_fibonacci_partial_sum(long long from, long long to)
{
    int sum {fibonacci_sum(to) - fibonacci_sum(from - 1)};
    if (sum < 0) { sum += 10; }
    return sum;
}

int main()
{
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum(from, to) << '\n';
}
