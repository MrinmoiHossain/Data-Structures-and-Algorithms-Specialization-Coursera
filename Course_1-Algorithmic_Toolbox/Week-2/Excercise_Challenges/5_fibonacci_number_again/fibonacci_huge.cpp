#include <iostream>
typedef long long ll;
using namespace std;

int pisano_period(int m)
{
    int prev = 0;
    int curr = 1;

    for(int i = 0; i < m * m; ++i){
        int temp = (prev + curr) % m;
        prev = curr;
        curr = temp;

        if(prev == 0 && curr == 1)
            return i + 1;
    }
}

ll get_fibonacci_huge_fast(ll n, int m)
{
    n %= pisano_period(m);

    ll prev = 0;
    ll curr = 1;

    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    for(ll i = 0; i < n - 1; ++i){
        ll temp = (prev + curr) % m;
        prev = curr;
        curr = temp;
    }

    return (curr % m);
}

long long get_fibonacci_huge_naive(long long n, int m)
{
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i){
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

int main(void)
{
    ll n;
    int m;
    cin >> n >> m;

    cout << get_fibonacci_huge_fast(n, m) << '\n';

    return 0;
}
