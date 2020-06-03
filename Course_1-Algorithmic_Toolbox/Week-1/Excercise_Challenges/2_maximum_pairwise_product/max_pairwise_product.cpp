#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

ll MaxPairwiseProduct(vector<int>& num)
{
    int max1 = -999, max2 = -9999, n = num.size();

    for(int i = 0; i < n; ++i){
        if(max1 < num[i]){
            max2 = max1;
            max1 = num[i];
        }
        else if(max2 < num[i]){
            max2 = num[i];
        }
    }

    return (ll)max1 * max2;
}

int main(void)
{
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; ++i)
        cin >> v[i];

    cout << MaxPairwiseProduct(v) << "\n";

    return 0;
}