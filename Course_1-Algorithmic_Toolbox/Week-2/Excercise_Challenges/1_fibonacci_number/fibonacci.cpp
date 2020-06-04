#include <iostream>
#include <cassert>
using namespace std;


int fibonacci_naive(int n)
{
    if(n <= 1)
        return n;
    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

int fibonacci_fast(int n)
{
    int F[n+1] = {0};
    F[0] = 0;
    F[1] = 1;

    for(int i = 2; i <= n; ++i)
        F[i] = F[i - 1] + F[i - 2];

    return F[n];
}

int main(void)
{
    int n;
    cin >> n;

    //cout << fibonacci_naive(n) << '\n';
    cout << fibonacci_fast(n) << '\n';
    return 0;
}
