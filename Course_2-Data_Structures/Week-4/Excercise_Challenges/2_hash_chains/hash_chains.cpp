#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#define MOD 1000000007
typedef long long ll;
using namespace std;


int hash_func(string a, int m)
{
    int len = a.length();

    ll v = 0;
    for(int i = len - 1; i >= 0; --i){
        v = (v * 263 + (int)a[i]) % MOD;
    }

    return v % m; 
}

bool search(string s, vector<string> v)
{
    for(auto a : v){
        if(a == s)
            return true;
    }
    return false;
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int q;
    cin >> q;

    string a, b;
    int temp;

    map<int, vector<string>> m;
    for(int i = 0; i < q; ++i){
        cin >> a;

        if(a == "add"){
            cin >> b;

            temp = hash_func(b, n);
            bool flag = search(b, m[temp]);
            if(!flag)
                m[temp].push_back(b);
        }
        else if(a == "check"){
            cin >> temp;

            if(m.count(temp)){
                for(int j = m[temp].size() - 1; j >= 0; --j)
                    cout << m[temp][j] << " ";
                cout << endl;
            }
            else
                cout << endl;
        }
        else if(a == "find"){
            cin >> b;

            temp = hash_func(b, n);
            if(m.count(temp)){
                bool flag = search(b, m[temp]);

                if(flag)
                    cout << "yes" << endl;
                else
                    cout << "no" << endl;
            }
            else{
                cout << "no" << endl;
            }
        }
        else if(a == "del"){
            cin >> b;

            temp = hash_func(b, n);
            if(m.count(temp)){
                int nlen = m[temp].size();
                for(int j = 0; j < nlen; ++j){
                    if(m[temp][j] == b){
                        m[temp].erase(m[temp].begin() + j);
                        break;
                    }
                }
            }
        }
    }
    

    return 0;
}
