#include <iostream>
#include <vector>
using namespace std;

int lcs2(vector<int>& a, vector<int>& b)
{
    int n = a.size(), m = b.size();
    int D[n + 1][m + 1];

    for(int i = 0; i <= n; ++i)
        D[i][0] = 0;

    for(int i = 0; i <= m; ++i)
        D[0][i] = 0;

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(a[i - 1] == b[j - 1])
                D[i][j] = 1 + D[i - 1][j - 1];
            else
                D[i][j] = max(D[i - 1][j], D[i][j - 1]);
        }
    }

    return D[n][m];
}

int main(void)
{
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int m;
    cin >> m;

    vector<int> b(m);
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }

    cout << lcs2(a, b) << "\n";

    return 0;
}
