#include <iostream>
using namespace std;

int get_fibonacci_last_digit_naive(int n)
{
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int get_fibonacci_last_digit_fast(int n)
{
    if(n <= 1)
        return n;

    int prev = 0;
    int curr = 1;

    for(int i = 0; i < n - 1; ++i){
        int temp = (prev + curr) % 10;
        prev = curr;
        curr = temp;
    }

    return curr % 10;
}

int main(void)
{
    int n;
    cin >> n;

    int c = get_fibonacci_last_digit_fast(n);
    cout << c << '\n';

    return 0;
}
