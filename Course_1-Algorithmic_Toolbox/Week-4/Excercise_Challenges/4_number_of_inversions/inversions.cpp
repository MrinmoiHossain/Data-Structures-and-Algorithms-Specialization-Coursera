#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

int get_number_of_inversions(vector<int> &a, vector<int> &b, int left, int mid, int right)
{
    int inv = 0;
    int i = left, j = mid, k = left;

    while(i <= mid - 1 && j <= right){
        if(a[i] <= a[j]){
            b[k++] = a[i++];
        }
        else{
            b[k++] = a[j++];
            inv += (mid - i);
        }
    }

    while(i <= mid - 1)
        b[k++] = a[i++];
    while(j <= right)
        b[k++] = a[j++];

    for(int i = left; i <= right; ++i)
        a[i] = b[i];

    return inv;
}

int merge_sort(vector<int>& a, vector<int>& b, int left, int right)
{
    int inv_count = 0;
    if(left >= right)
        return inv_count;

    int mid = left + (right - left) / 2;
    inv_count += merge_sort(a, b, left, mid);
    inv_count += merge_sort(a, b, mid + 1, right);
    inv_count += get_number_of_inversions(a, b, left, mid + 1, right);

    return inv_count;
}

int main(void)
{
    int n;
    cin >> n;

    vector<int> a(n);
    for(size_t i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<int> b(a.size());
    cout << merge_sort(a, b, 0, a.size() - 1) << '\n';

    return 0;
}
