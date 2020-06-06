#include <iostream>
#include <vector>
#define PISANO 60
typedef long long ll;
using namespace std;

int F[PISANO];

void fibonacci_series(void)
{
    F[0] = 0;
    F[1] = 1;
    for(int i = 2; i < PISANO; ++i)
        F[i] = (F[i - 1] + F[i - 2]) % 10;
}

int get_fibonacci_partial_sum_fast(ll from, ll to)
{
    from %= PISANO;
    to %= PISANO;
    if(to < from)
        to += PISANO;

    int sum = 0;
    for(int i = from; i <= to; ++i)
        sum = (sum + F[i % PISANO]) % 10;

    return sum % 10;
}

long long get_fibonacci_partial_sum_naive(long long from, long long to)
{
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

int main(void)
{
    fibonacci_series();
    ll from, to;
    cin >> from >> to;
    cout << get_fibonacci_partial_sum_fast(from, to) << '\n';

    return 0;
}
