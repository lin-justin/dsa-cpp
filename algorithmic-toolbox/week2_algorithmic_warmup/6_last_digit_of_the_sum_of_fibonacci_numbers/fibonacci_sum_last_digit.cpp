#include <iostream>

// int fibonacci_sum_naive(long long n)
// {
//     if (n <= 1)
//         return n;

//     long long previous = 0;
//     long long current  = 1;
//     long long sum      = 1;

//     for (long long i = 0; i < n - 1; ++i) {
//         long long tmp_previous = previous;
//         previous = current;
//         current = tmp_previous + current;
//         sum += current;
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

int main()
{
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum(n) << std::endl;
}