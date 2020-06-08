#include <iostream>
using namespace std;

int get_change(int m)
{
    int coin[] = {1, 5, 10};
    int con = 0;

    for(int i = 2; i >= 0; --i){
        while(coin[i] <= m){
            con++;
            m -= coin[i];   
        }
    }
    return con;
}

int main(void)
{
    int m;
    cin >> m;
    cout << get_change(m) << '\n';

    return 0;
}
