#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

int binary_search(const vector<int> &a, int x)
{
    int left = 0, right = a.size() - 1;
    while(left <= right){
        int mid = left + (right - left) / 2;

        if(a[mid] == x)
            return mid;
        else if(a[mid] > x)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

int linear_search(const vector<int> &a, int x)
{
    for(size_t i = 0; i < a.size(); ++i){
        if(a[i] == x) return i;
    }
    return -1;
}

int main(void)
{
    int n;
    cin >> n;
    
    vector<int> a(n);
    for(size_t i = 0; i < n; ++i){
        cin >> a[i];
    }
  
    int m;
    cin >> m;
  
    vector<int> b(m);
    for(size_t i = 0; i < m; ++i){
        cin >> b[i];
    }

    for(size_t i = 0; i < m; ++i){
        cout << binary_search(a, b[i]) << ' ';
    }

    return 0;
}
