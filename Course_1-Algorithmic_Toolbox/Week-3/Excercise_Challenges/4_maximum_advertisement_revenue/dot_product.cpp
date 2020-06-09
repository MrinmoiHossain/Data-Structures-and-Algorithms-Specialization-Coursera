#include <algorithm>
#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

ll max_dot_product(vector<int> a, vector<int> b)
{
    ll result = 0;
    int n = a.size();
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    for(int i = 0; i < n; ++i)
        result += (ll)a[i] * b[i];

    return result;
}

int main(void)
{
    int n;
    cin >> n;
    
    vector<int> a(n), b(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> b[i];
    }

    cout << max_dot_product(a, b) << endl;
    
    return 0;
}
