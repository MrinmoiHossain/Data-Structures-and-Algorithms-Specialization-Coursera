#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void max_sliding_window_naive(vector<int> const & A, int w)
{
    for(size_t i = 0; i < A.size() - w + 1; ++i){
        int window_max = A[i];
        for(size_t j = i + 1; j < i + w; ++j)
            window_max = max(window_max, A[j]);

        cout << window_max << " ";
    }

    return;
}

void max_sliding_window_fast(vector<int>& A, int w)
{
    int n = A.size();
    deque<int> dq;

    for(int i = 0; i < w; ++i){
        while(!dq.empty() && A[i] >= A[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }

    for(int i = w; i < n; ++i){
        cout << A[dq.front()] << " ";

        while(!dq.empty() && dq.front() <= i - w)
            dq.pop_front();

        while(!dq.empty() && A[i] >= A[dq.back()])
            dq.pop_back();

        dq.push_back(i);
    }
    cout << A[dq.front()] << "\n";
}

int main(void)
{
    int n;
    cin >> n;

    vector<int> A(n);
    for(int i = 0; i < n; ++i)
        cin >> A[i];

    int w;
    cin >> w;

    max_sliding_window_fast(A, w);

    return 0;
}
