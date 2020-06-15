#include <iostream>
#include <string>
using namespace std;

int min3(int a, int b, int c)
{
    return min(min(a, b), c);
}

int edit_distance(const string &str1, const string &str2)
{
    int n = str1.length(), m = str2.length();
    int D[n + 1][m + 1];

    for(int i = 0; i <= m; ++i)
        D[0][i] = i;

    for(int i = 0; i <= n; ++i)
        D[i][0] = i;

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            int match = D[i - 1][j - 1];
            int mismatch = D[i - 1][j - 1] + 1;
            int deletion = D[i - 1][j] + 1;
            int insertion = D[i][j - 1] + 1;

            if(str1[i - 1] == str2[j - 1])
                D[i][j] = min3(insertion, deletion, match);
            else
                D[i][j] = min3(insertion, deletion, mismatch);
        }
    }

    return D[n][m];
}

int main(void)
{
    string str1, str2;
    cin >> str1;
    cin >> str2;

    cout << edit_distance(str1, str2) << endl;
    return 0;
}
