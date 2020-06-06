#include <iostream>
#define PISANO 60 // pisano period for 10
typedef long long ll;
using namespace std;

int fibonacci_sum_fast(ll n)
{
    if(n < 2)
        return (int)n;

    n %= PISANO;
    int prev = 1;
    int curr = 1;

    for(int i = 0; i < n; ++i){
        int temp = (prev + curr) % 10;
        prev = curr;
        curr = temp;
    }

    return (!curr? 9 : (curr - 1) % 10);
}

int fibonacci_sum_naive(long long n)
{
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

int main(void)
{
    ll n;
    cin >> n;
    cout << fibonacci_sum_fast(n) << "\n";

    return 0;
}
