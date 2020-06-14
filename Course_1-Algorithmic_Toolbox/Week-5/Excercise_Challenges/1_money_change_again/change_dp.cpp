#include <iostream>
#include <climits>
using namespace std;

int get_change(int m)
{
    int coins[] = {1, 3, 4};
    int min_num_coins[m+1];
    min_num_coins[0] = 0;

    for(int i = 1; i <= m; ++i){
        min_num_coins[i] = INT_MAX;
        for(int j = 0; j < 3; ++j){
            if(i >= coins[j]){
                int num_coins = min_num_coins[i - coins[j] ] + 1;
                min_num_coins[i] = min(min_num_coins[i], num_coins);
            }
        }
    }

    return min_num_coins[m];
}

int main(void)
{
    int m;
    cin >> m;
    cout << get_change(m) << '\n';

    return 0;
}
