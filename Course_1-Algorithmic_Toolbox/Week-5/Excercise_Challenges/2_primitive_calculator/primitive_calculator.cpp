#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> optimal_sequence_dp(int n)
{
    vector<int> sequence;
    int cal[n + 1];
    cal[0] = 0;

    for(int i = 1; i <= n; ++i){
        cal[i] = cal[i - 1] + 1;
        if(i % 2 == 0){
            cal[i] = min(cal[i/2] + 1, cal[i]);
        }
        if(i % 3 == 0){
            cal[i] = min(cal[i/3] + 1, cal[i]);
        }
    }

    sequence.push_back(n);
    while(n != 1){
        if(n % 3 == 0 && cal[n] - 1 == cal[n / 3]){
            sequence.push_back(n / 3);
            n /= 3;
        }
        else if(n % 2 == 0 && cal[n] - 1 == cal[n / 2]){
            sequence.push_back(n / 2);
            n /= 2;
        }
        else{
            sequence.push_back(n - 1);
            n--;
        }
    }

    reverse(sequence.begin(), sequence.end());
    return sequence;
}

vector<int> optimal_sequence(int n)
{
    vector<int> sequence;
    while(n >= 1){
        sequence.push_back(n);
        if(n % 3 == 0){
            n /= 3;
        }
        else if(n % 2 == 0){
            n /= 2;
        }
        else{
            n -= 1;
        }
    }

    reverse(sequence.begin(), sequence.end());
    return sequence;
}

int main(void)
{
    int n;
    cin >> n;

    vector<int> sequence = optimal_sequence_dp(n);
    cout << sequence.size() - 1 << '\n';
    for(size_t i = 0; i < sequence.size(); ++i){
        cout << sequence[i] << " ";
    }
    cout << endl;

    return 0;
}
