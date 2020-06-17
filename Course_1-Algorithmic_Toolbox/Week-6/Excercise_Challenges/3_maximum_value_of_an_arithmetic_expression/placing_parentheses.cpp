#include <iostream>
#include <cassert>
#include <string>
#include <cstring>
#include <climits>
#include <vector>
typedef long long ll;
using namespace std;

ll min4(ll a, ll b, ll c, ll d)
{
    return min(a, min(b, min(c, d)));
}

ll max4(ll a, ll b, ll c, ll d)
{
    return max(a, max(b, max(c, d)));
}

ll eval(ll a, ll b, char op)
{
    if(op == '*')
        return a * b;
    else if(op == '+')
        return a + b;
    else if(op == '-')
        return a - b;
}

long long get_maximum_value(const string &exp)
{
    int len = exp.size();
    int operation = (len + 1) / 2;

    ll Min[operation][operation];
    ll Max[operation][operation];

    memset(Min, 0, sizeof(Min));
    memset(Max, 0, sizeof(Max));

    for(int i = 0; i < operation; ++i){
        Min[i][i] = stoll(exp.substr(2 * i, 1));
        Max[i][i] = stoll(exp.substr(2 * i, 1));
    }

    for(int i = 0; i < operation - 1; ++i){
        for(int j = 0; j < operation - i - 1; ++j){
            int k = i + j + 1;
            ll min_value = LLONG_MAX;
            ll max_value = LLONG_MIN;

            for(int l = j; l < k; ++l){
                ll a = eval(Min[j][l], Min[l + 1][k], exp[2 * l + 1]);
                ll b = eval(Min[j][l], Max[l + 1][k], exp[2 * l + 1]);
                ll c = eval(Max[j][l], Min[l + 1][k], exp[2 * l + 1]);
                ll d = eval(Max[j][l], Max[l + 1][k], exp[2 * l + 1]);

                min_value = min(min_value, min4(a, b, c, d));
                max_value = max(max_value, max4(a, b, c, d));
            }
            Min[j][k] = min_value;
            Max[j][k] = max_value;
        }
    }

    return Max[0][operation - 1];
}

int main(void)
{
    string s;
    cin >> s;

    cout << get_maximum_value(s) << '\n';

    return 0;
}
