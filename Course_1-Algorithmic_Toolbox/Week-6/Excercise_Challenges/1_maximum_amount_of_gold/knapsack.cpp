#include <iostream>
#include <vector>
using namespace std;

int optimal_weight(int W, vector<int> &w)
{
    int n = w.size();
    vector<vector<int> > dp(n + 1, vector<int>(W + 1));

    for(int i = 0; i < n + 1; ++i){
        for(int j = 0; j < W + 1; ++j){
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(w[i - 1] <= j)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + w[i - 1]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][W];
}

int main(void)
{
    int n, W;
    cin >> W >> n;
    vector<int> w(n);
    for(int i = 0; i < n; i++){
        cin >> w[i];
    }
    cout << optimal_weight(W, w) << '\n';

    return 0;
}
