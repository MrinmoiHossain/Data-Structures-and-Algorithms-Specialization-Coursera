#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class HeapBuilder{
private:
    vector<int> data_;
    vector<pair<int, int> > swaps_;

    void ReadData(void)
    {
        int n;
        cin >> n;
        data_.resize(n);

        for(int i = 0; i < n; ++i)
            cin >> data_[i];
    }

    int LeftChild(int index)
    {
        return 2 * index + 1;
    }

    int RightChild(int index)
    {
        return 2 * index + 2;
    }

    void ShiftDown(int index)
    {
        int n = data_.size();
        int min_index = index;
        int l = LeftChild(index);
        if(l < n && data_[l] < data_[min_index])
            min_index = l;

        int r = RightChild(index);
        if(r < n && data_[r] < data_[min_index])
            min_index = r;

        if(index != min_index){
            swaps_.push_back(make_pair(index, min_index));
            swap(data_[index], data_[min_index]);
            ShiftDown(min_index);
        }
    }

    void GenerateSwaps(void)
    {
        swaps_.clear();
        int n = data_.size();

        for(int i = n / 2; i >= 0; --i){
            ShiftDown(i);
        }
    }

    void WriteResponse(void)
    {
        cout << swaps_.size() << "\n";
        for(int i = 0; i < swaps_.size(); ++i){
            cout << swaps_[i].first << " " << swaps_[i].second << "\n";
        }
    }

public:
    void Solve(void)
    {
        ReadData();
        GenerateSwaps();
        WriteResponse();
    }
};

int main(void)
{
    ios_base::sync_with_stdio(false);
    HeapBuilder heap_builder;
    heap_builder.Solve();
  
    return 0;
}
