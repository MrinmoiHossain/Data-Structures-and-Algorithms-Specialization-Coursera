#include <iostream>
#include <vector>
using namespace std;

bool partition3(int total, vector<int> &A)
{
    int W = total / 3;
    if(W * 3 != total)
        return 0;
    
    int n = A.size();
    vector<vector<int> > dp(n + 1, vector<int>(W+1));

    for(int i = 0; i < n + 1; ++i){
        for(int j = 0; j < W + 1; ++j){
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(A[i - 1] <= j)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - A[i - 1]] + A[i - 1]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return (dp[n][W] == W);
}

int main(void)
{
    int n;
    cin >> n;
    vector<int> A(n);
    int total = 0;

    for(int i = 0; i < n; ++i){
        cin >> A[i];
        total += A[i];
    }
    cout << partition3(total, A) << '\n';

    return 0;
}
