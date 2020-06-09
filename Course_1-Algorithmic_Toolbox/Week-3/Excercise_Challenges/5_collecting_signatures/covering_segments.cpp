#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#define PB push_back
#define MP make_pair
#define F first
#define S second
using namespace std;

vector<int> optimal_points(vector<pair<int, int> > &segments)
{
    vector<int> points;
    int last = segments[0].S;
    points.PB(last);
    int n = segments.size();

    for(int i = 1; i < n; ++i){
        if(segments[i].F <= last)
            continue;
        last = segments[i].S;
        points.PB(last);
    }

    return points;
}

bool cmp(pair<int, int> A, pair<int, int> B)
{
    if(A.S != B.S) return A.S < B.S;
    return A.F < B.S;
}

int main(void)
{
    int n;
    cin >> n;
  
    vector<pair<int, int> > segments;
    for(int i = 0, a, b; i < n; ++i) {
        cin >> a >> b;
        segments.PB(MP(a, b));
    }

    sort(segments.begin(), segments.end(), cmp);

    
    vector<int> points = optimal_points(segments);
    cout << points.size() << "\n";

    for(size_t i = 0; i < points.size(); ++i) {
        cout << points[i] << " ";
    }
    

    return 0;
}
