#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>
using namespace std;

class StackWithMax{
    public:
        vector<int> stack;
        vector<int> max_stack;

        void Push(int value){
            stack.push_back(value);
            
            if(max_stack.size() == 0)
                max_stack.push_back(value);
            else
                max_stack.push_back(max(max_stack.back(), value));
        }

        void Pop(){
            assert(stack.size());
            stack.pop_back();
            max_stack.pop_back();
        }

        int Max(){
            assert(stack.size());
            return max_stack.back();
        }
};

int main(void)
{
    int num_queries;
    cin >> num_queries;

    StackWithMax stack;
    string query;
    for(int i = 0; i < num_queries; ++i){
        cin >> query;

        if(query == "push"){
            int value;
            cin >> value;
            stack.Push(value);
        }
        else if(query == "pop"){
            stack.Pop();
        }
        else if(query == "max"){
            cout << stack.Max() << "\n";
        }
        else{
            assert(0);
        }
    }
    
    return 0;
}