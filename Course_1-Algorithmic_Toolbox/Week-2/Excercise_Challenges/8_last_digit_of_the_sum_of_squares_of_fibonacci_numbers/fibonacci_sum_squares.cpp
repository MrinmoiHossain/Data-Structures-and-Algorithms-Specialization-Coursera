#include <iostream>
#define PISANO 60
typedef long long ll;
using namespace std;

int last_digt_of_fibonacci(int n)
{
    if(n < 2)
        return n;

    int prev = 0;
    int curr = 1;

    for(int i = 2; i <= n; ++i){
        int temp = (prev + curr) % 10;
        prev = curr;
        curr = temp;
    }

    return curr % 10;
}

int fibonacci_sum_squares_fast(ll n)
{
    int one_side = last_digt_of_fibonacci((n + 1) % PISANO);
    int other_side = last_digt_of_fibonacci(n % PISANO);

    return (one_side * other_side) % 10;
}

int fibonacci_sum_squares_naive(long long n)
{
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i){
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}

int main(void)
{
    ll n;
    cin >> n;
    cout << fibonacci_sum_squares_fast(n) << "\n";

    return 0;
}
