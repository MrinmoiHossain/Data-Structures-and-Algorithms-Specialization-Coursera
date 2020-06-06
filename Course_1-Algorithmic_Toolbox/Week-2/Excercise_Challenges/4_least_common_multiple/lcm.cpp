#include <iostream>
using namespace std;

long long lcm_naive(int a, int b)
{
    for(long long l = 1; l <= (long long) a * b; ++l)
        if(l % a == 0 && l % b == 0)
            return l;

    return (long long) a * b;
}

int gcd_euclid(int a, int b)
{
    if(b == 0)
        return a;
    return gcd_euclid(b, a % b);
}

long long lcm_fast(int a, int b)
{
    return ((long long)a * b) / gcd_euclid(a, b);
}

int main(void)
{
    int a, b;
    cin >> a >> b;

    //cout << lcm_naive(a, b) << endl;
    cout << lcm_fast(a, b) << endl;

    return 0;
}
