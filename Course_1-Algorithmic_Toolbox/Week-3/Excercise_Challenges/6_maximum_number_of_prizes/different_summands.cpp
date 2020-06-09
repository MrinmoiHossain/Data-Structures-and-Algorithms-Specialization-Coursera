#include <iostream>
#include <vector>
#define PB push_back
using namespace std;

vector<int> optimal_summands(int n)
{
    vector<int> summands;
    for(int i = 1; i <= n; ++i){
        n -= i;

        if(n == 0 || n <= i){
            summands.PB(n + i);
            break;
        }
        else{
            summands.PB(i);
        }
    }

    return summands;
}

int main(void)
{
    int n;
    cin >> n;
  
    vector<int> summands = optimal_summands(n);
    cout << summands.size() << '\n';
    for(size_t i = 0; i < summands.size(); ++i){
        cout << summands[i] << ' ';
    }

    return 0;
}
