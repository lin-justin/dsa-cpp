#include <iostream>

// int get_fibonacci_last_digit_naive(int n)
// {
//     if (n <= 1)
//         return n;

//     int previous = 0;
//     int current  = 1;

//     for (int i = 0; i < n - 1; ++i) {
//         int tmp_previous = previous;
//         previous = current;
//         current = tmp_previous + current;
//     }

//     return current % 10;
// }

int get_fibonacci_last_digit(long long n)
{
    int first {0};
    int second {1};

    int result {0};

    for (int i {2}; i <= n; ++i)
    {
        result = (first + second) % 10;
        first = second;
        second = result;
    }
    return result;
}

int main()
{
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit(n);
    std::cout << c << '\n';
}
