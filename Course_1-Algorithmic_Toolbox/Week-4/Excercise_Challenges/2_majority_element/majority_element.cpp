#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int get_majority_element(vector<int> &a, int left, int right)
{
    if(left == right) return -1;
    if(left + 1 == right) return a[left];

    int mid = (left + right - 1) / 2 + 1;
    int left_element = get_majority_element(a, left, mid);
    int right_element = get_majority_element(a, mid, right);

    int left_count = 0;
    for(int i = left; i < right; ++i)
        if(a[i] == left_element)
            left_count += 1;

    if(left_count > (right - left) / 2)
        return left_element;

    int right_count = 0;
    for(int i = left; i < right; ++i)
        if(a[i] == right_element)
            right_count += 1;

    if(right_count > (right - left) / 2)
        return right_element;

    return -1;
}

int main(void)
{
    int n;
    cin >> n;

    vector<int> a(n);
    for(size_t i = 0; i < a.size(); ++i){
        cin >> a[i];
    }
    cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';

    return 0;
}
