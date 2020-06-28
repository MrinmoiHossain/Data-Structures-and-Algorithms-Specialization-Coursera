#include <iostream>
#include <queue>
#include <vector>
#define PB push_back
#define MP make_pair
#define F first
#define S second
using namespace std;

int s;
queue<int> q;

int Processing(pair<int, int> p)
{
    while(!q.empty() && q.front() <= p.F)
        q.pop();

    if(q.size() < s){
        if(q.empty()){
            q.push(p.F + p.S);
            return p.F;
        }
        else{
            int st = max(p.F, q.back());
            q.push(st + p.S);
            return st;
        }
    }
    else{
        return -1;
    }
}

vector<int> ProcessRequests(vector<pair<int, int> > v)
{
    vector<int> response;
    for(int i = 0; i < v.size(); ++i){
        response.PB(Processing(v[i]));
    }

    return response;
}

int main(void)
{
    int n;
    cin >> s >> n;

    vector<pair<int, int> > v;
    for(int i = 0, start, process; i < n; ++i){
        cin >> start >> process;
        v.PB(MP(start, process));
    }

    vector<int> result = ProcessRequests(v);

    for(int i = 0; i < result.size(); ++i)
        cout << result[i] << endl;

    return 0;
}