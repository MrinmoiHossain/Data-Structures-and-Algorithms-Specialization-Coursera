#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool IsGreaterOrEqual(string a, string b)
{
    int ia = stoi(a+b), ib = stoi(b+a);
    return ia >= ib;
}

string largest_number(vector<string> a)
{
    stringstream ret;

    while(a.size() != 0){
        string maxDigit = "0";
        int pos = 0;

        for(int i = 0; i < a.size(); ++i){
            if(IsGreaterOrEqual(a[i], maxDigit)){
                maxDigit = a[i];
                pos = i;
            }     
        }
        ret << maxDigit;
        a.erase(a.begin() + pos);
    }

    string result;
    ret >> result;
    return result;
}

int main(void)
{
    int n;
    cin >> n;

    vector<string> a(n);
    for(size_t i = 0; i < a.size(); i++){
        cin >> a[i];
    }

    cout << largest_number(a) << "\n";

    return 0;
}
