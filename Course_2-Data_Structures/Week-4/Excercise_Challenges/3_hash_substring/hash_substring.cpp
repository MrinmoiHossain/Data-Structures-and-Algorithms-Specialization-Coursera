#include <iostream>
#include <string>
#include <vector>
using namespace std;

int hash_func(string s)
{
    int hash = 0;
    for(int i = 0; i < s.length(); ++i)
        hash += int(s[i]);

    return hash;
}

vector<int> precompute_hashes(string p, string t)
{
    vector<int> h;
    int pl = p.length(), bound = t.length() - p.length() + 1;

    h.push_back(hash_func(t.substr(0, pl)));
    
    for(int i = 1; i < bound; ++i){
        int old_hash = h[i - 1];
        int left_hash = int(t[i - 1]);
        int right_hash = int(t[i + pl - 1]);

        int ith_hash = old_hash - left_hash + right_hash;

        h.push_back(ith_hash);
    }

    return h;
}

vector<int> get_occurrences_rabin_karp(string p, string t)
{
    vector<int> ans;
    int pattern_hash = hash_func(p);

    vector<int> H = precompute_hashes(p, t);

    for(int i = 0; i <= t.length() - p.length(); ++i){
        if(pattern_hash == H[i]){
            string s = t.substr(i, p.length());
            if(p == s)
                ans.push_back(i);
        }
    }

    return ans;
}

vector<int> get_occurrences_naive(string p, string t)
{    
    vector<int> ans;
    for(int i = 0; i + p.size() <= t.size(); ++i)
        if(t.substr(i, p.size()) == p)
            ans.push_back(i);
    return ans;
}


int main(void)
{
    ios_base::sync_with_stdio(false);
    string pattern, text;
    cin >> pattern;
    cin >> text;

    vector<int> res = get_occurrences_rabin_karp(pattern, text);
    for(int i = 0; i < res.size(); ++i)
        cout << res[i] << " ";
    cout << endl;

    return 0;
}
