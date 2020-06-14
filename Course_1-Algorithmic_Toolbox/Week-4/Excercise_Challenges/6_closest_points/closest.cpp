#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <cfloat>
#define PB push_back
#define MP make_pair
#define F first
#define S second
using namespace std;

bool cmp(pair<int, int> A, pair<int, int> B)
{
    if(A.F != B.F) return A.F < B.F;
    return A.S < B.S;
}

bool cmp_y(pair<int, int> A, pair<int, int> B)
{
    return A.S < B.S;
}

double dist(int x1, int y1, int x2, int y2)
{
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}


double naive_minimal_distance(vector<pair<int, int> > v)
{
    double min_dist = FLT_MAX;
    int n = v.size();

    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            double dist_value = dist(v[i].F, v[i].S, v[j].F, v[j].S);
            if(dist_value < min_dist)
                min_dist = dist_value;
        }
    }
    return min_dist;
}

double strip_closest(vector<pair<int, int> > strip, double d)
{
    int n = strip.size();

    sort(strip.begin(), strip.end(), cmp_y);

    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n && (strip[j].S - strip[i].S) < d; ++j){
            d = min(d, dist(strip[i].F, strip[i].S, strip[j].F, strip[j].S));
        }
    }
    return d;
}

double fast_minimal_distance(vector<pair<int, int> > v)
{
    int n = v.size();
    if(n <= 3)
        return naive_minimal_distance(v);

    int mid = n / 2;
    int x = v[mid].F;

    vector<pair<int, int> > left(v.begin(), v.begin() + mid);
    vector<pair<int, int> > right(v.begin() + mid, v.end());
    
    double dl = fast_minimal_distance(left);
    double dr = fast_minimal_distance(right);

    double d = min(dl, dr);

    vector<pair<int, int> > strip;
    for(int i = 0; i < n; ++i)
        if(abs(v[i].F - x) < d)
            strip.PB(MP(v[i].F, v[i].S));

    return min(d, strip_closest(strip, d));
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int> > v;
    for(int i = 0, x, y; i < n; ++i){
        cin >> x >> y;
        v.PB(MP(x, y));
    }
    sort(v.begin(), v.end(), cmp);
    
    cout << fixed;
    cout << setprecision(9) << fast_minimal_distance(v) << "\n";

    return 0;
}
