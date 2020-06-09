#include <iostream>
#include <vector>
using namespace std;

int max_index_value_weight_ratio(vector<int> values, vector<int> weights)
{
    int index = 0;
    int n = values.size();
    double max_ratio = 0.0;

    for(int i = 0; i < n; ++i){
        if(weights[i] > 0 && (double) values[i] / weights[i] > max_ratio){
            index = i;
            max_ratio = (double) values[i] / weights[i];
        }
    }

    return index;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values)
{
    double value = 0.0;
    int n = weights.size();

    for(int i = 0; i < n; ++i){
        if(capacity == 0)
            return value;

        int index = max_index_value_weight_ratio(values, weights);

        int a = min(capacity, weights[index]);
        value += (a * (double)values[index]) / weights[index];
        weights[index] -= a;
        capacity -= a;
    }

    return value;
}

int main(void)
{
    int n;
    int capacity;
    cin >> n >> capacity;

    vector<int> values(n);
    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> values[i] >> weights[i];
    }

    double optimal_value = get_optimal_value(capacity, weights, values);

    cout.precision(10);
    cout << optimal_value << endl;
    return 0;
}
