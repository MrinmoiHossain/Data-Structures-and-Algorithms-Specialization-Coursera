#include <iostream>
#include <vector>
using namespace std;

int max3(int a, int b, int c)
{
    return max(max(a, b), c);
}

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c)
{
    int n = a.size(), m = b.size(), l = c.size();
    int dp[n + 1][m + 1][l + 1];


    for(int i = 0; i < n + 1; ++i){
        for(int j = 0; j < m + 1; ++j){
            for(int k = 0; k < l + 1; ++k){
                if(i == 0 || j == 0 || k == 0)
                    dp[i][j][k] = 0;
                else if(a[i - 1] == b[j - 1] && a[i - 1] == c[k - 1])
                    dp[i][j][k] = 1 + dp[i - 1][j - 1][k - 1];
                else
                    dp[i][j][k] = max3(dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]);
            }
        }
    }

    return dp[n][m][l];
}

int main(void)
{
    int an;
    cin >> an;
    vector<int> a(an);
    for(int i = 0; i < an; i++){
        cin >> a[i];
    }
  
    int bn;
    cin >> bn;
    vector<int> b(bn);
    for(int i = 0; i < bn; i++){
        cin >> b[i];
    }

    int cn;
    cin >> cn;
    vector<int> c(cn);
    for(int i = 0; i < cn; i++){
        cin >> c[i];
    }

    cout << lcs3(a, b, c) << "\n";

    return 0;
}
