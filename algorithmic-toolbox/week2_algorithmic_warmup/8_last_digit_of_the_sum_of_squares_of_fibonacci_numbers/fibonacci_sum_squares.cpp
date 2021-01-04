#include <iostream>

// int fibonacci_sum_squares_naive(long long n) {
//     if (n <= 1) { return n; }

//     long long previous = 0;
//     long long current  = 1;
//     long long sum      = 1;

//     for (long long i = 0; i < n - 1; ++i)
//     {
//         long long tmp_previous = previous;
//         previous = current;
//         current = tmp_previous + current;
//         sum += current * current;
//     }

//     return sum % 10;
// }

long long fib(long long n)
{
    if (n <= 1) { return n; }

    long long fib1 {0}, fib2 {1}, fib3 {0};

    for (long long i {2}; i <= n; ++i)
    {
        fib3 = fib1 + fib2;
        fib1 = fib2;
        fib2 = fib3;
    }
    return fib3;
}

int fibonacci_sum_squares(long long n)
{
    if (n <= 1) { return n; }

    long long current = fib(n % 60);
    long long next = fib((n + 1) % 60);

    return ((current % 10) * (next % 10) % 10);
}

int main()
{
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares(n) << std::endl;
}
