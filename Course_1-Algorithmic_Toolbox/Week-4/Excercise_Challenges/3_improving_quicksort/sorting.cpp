#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int partition2(vector<int> &a, int l, int r)
{
    int x = a[l];
    int j = l;
    for(int i = l + 1; i <= r; i++){
        if(a[i] <= x){
            j++;
            swap(a[i], a[j]);
        }
    }
    swap(a[l], a[j]);
    return j;
}

vector<int> partition3(vector<int> &a, int l, int r)
{
    vector<int> m(2);
    int pivot = a[l];
    int mid = l;

    while(mid <= r){
        if(a[mid] < pivot){
            swap(a[mid++], a[l++]);
        }
        else if(a[mid] == pivot){
            mid++;
        }
        else if(a[mid] > pivot){
            swap(a[mid], a[r--]);
        }
    }
    m[0] = l;
    m[1] = r;

    return m;
}

void randomized_quick_sort(vector<int> &a, int l, int r)
{
    if(l >= r){
        return;
    }

    int k = l + rand() % (r - l + 1);
    swap(a[l], a[k]);
    vector<int> m = partition3(a, l, r);

    randomized_quick_sort(a, l, m[0] - 1);
    randomized_quick_sort(a, m[1] + 1, r);
}

int main(void)
{
    int n;
    cin >> n;
  
    vector<int> a(n);
    for(size_t i = 0; i < a.size(); ++i){
        cin >> a[i];
    }

    randomized_quick_sort(a, 0, a.size() - 1);
    for(size_t i = 0; i < a.size(); ++i){
        cout << a[i] << ' ';
    }

    return 0;
}
