#include <iostream>
#include <vector>
#include <algorithm>
#define PB push_back
#define MP make_pair
#define F first
#define S second
using namespace std;

bool cmp(pair<int, int> A, pair<int, int> B)
{
    return A.F < B.F;
}

vector<int> fast_count_segments(vector<pair<int, int> > v, vector<int> points)
{
    vector<int> cnt(points.size());
    for(int i = 0; i < points.size(); ++i){
        int con = 0;
        for(int j = 0; j < v.size(); ++j){
            if(v[j].F > points[i] || v[j].S < points[i])
                continue;
            else
                con++;
        }
        cnt[i] = con;
    }
    return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points)
{
    vector<int> cnt(points.size());
    for (size_t i = 0; i < points.size(); i++) {
        for (size_t j = 0; j < starts.size(); j++) {
            cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
        }
    }
    return cnt;
}

int main(void)
{
    int n, m;
    cin >> n >> m;

    vector<pair<int, int> > v;
    for(int i = 0, a, b; i < n; i++){
        cin >> a >> b;
        v.PB(MP(a, b));
    }
    sort(v.begin(), v.end(), cmp);

    vector<int> points(m);
    for(size_t i = 0; i < m; i++){
        cin >> points[i];
    }

    vector<int> cnt = fast_count_segments(v, points);
    for(size_t i = 0; i < cnt.size(); i++){
        cout << cnt[i] << ' ';
    }

    return 0;
}
