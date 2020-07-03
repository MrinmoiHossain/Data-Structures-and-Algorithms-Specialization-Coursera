#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(void)
{
    int n;
    cin >> n;

    map<int, string> m;
    string a, c;
    int b;

    for(int i = 0; i < n; ++i){
        cin >> a;

        if(a == "add"){
            cin >> b >> c;
            m[b] = c;
        }
        else if(a == "del"){
            cin >> b;

            if(m.count(b)){
                auto it = m.find(b);
                m.erase(it);
            }                
        }
        else if(a == "find"){
            cin >> b;
            if(m.count(b))
                cout << m[b] << endl;
            else
                cout << "not found" << endl;
        }
    }

    return 0;
}