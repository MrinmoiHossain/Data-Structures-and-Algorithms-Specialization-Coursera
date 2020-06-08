#include <iostream>
#include <vector>
#define PB push_back
using namespace std;

int compute_min_refills(int stops[], int n, int L)
{
    int num_refil = 0, current_refil = 0;

    while(current_refil <= n){
        int last_refil = current_refil;

        while(current_refil <= n && stops[current_refil + 1] - stops[last_refil] <= L)
            current_refil++;

        if(current_refil == last_refil)
            return -1;

        if(current_refil <= n)
            num_refil++;
    }

    return num_refil;
}


int main(void)
{
    int d, m, n;
    cin >> d;
    cin >> m;
    cin >> n;

    int stops[n + 2] = {0};

    for(int i = 1; i <= n; ++i)
        cin >> stops[i];
    stops[n + 1] = d;


    cout << compute_min_refills(stops, n, m) << "\n";

    return 0;
}
