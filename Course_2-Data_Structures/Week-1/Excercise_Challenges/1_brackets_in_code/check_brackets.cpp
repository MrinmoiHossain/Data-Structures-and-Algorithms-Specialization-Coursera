#include <iostream>
#include <stack>
#include <string>
#include <utility> 
#define MP make_pair
#define F first
#define S second
using namespace std;

bool cmp(char a, char b)
{
    if(a == '(' && b == ')')
        return true;
    else if(a == '{' && b == '}')
        return true;
    else if(a == '[' && b == ']')
        return true;
    else
        return false;
}

int is_balanced(string text)
{
    stack<pair<char, int> > s;
    int n = text.length();

    for(int i = 0; i < n; ++i){
        if(text[i] == '(' || text[i] == '{' || text[i] == '[')
            s.push(MP(text[i], i));
        else{
            if(text[i] == ')' || text[i] == '}' || text[i] == ']'){
                if(s.empty())
                    return i + 1;
                
                char top = s.top().F;
                s.pop();
                if(cmp(top, text[i]) == false)
                    return i + 1;
            }
        }
    }

    return (s.empty()? -1 : s.top().S + 1);
}

int main(void)
{
    string text;
    getline(cin, text);

    int result = is_balanced(text);
    if(result == -1)
        cout << "Success" << "\n";
    else
        cout << result << "\n";

    return 0;
}
