#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class DisjointSets{
private:
	int n;
	int m;
	vector<int> list;
	vector<int> parent;
	vector<int> rank;
	int mx_size = 0;

	void write_data(void)
	{
		cout << mx_size << endl;
	}

	int getParent(int table)
	{
		vector<int> v;
		int root = table;

		while(root != parent[root]){
			v.push_back(parent[root]);
			root = parent[root];
		}

		for(auto a : v)
			parent[a] = root;

		return root;
	}

	void merge(int destination, int source)
	{
		int d_i = getParent(destination - 1);
		int s_i = getParent(source - 1);

		if(d_i == s_i)
			return;

		if(rank[s_i] >= rank[d_i])
			parent[s_i] = d_i;
		else{
			parent[d_i] = s_i;
			if(rank[s_i] == rank[d_i])
				rank[s_i] += 1;
		}

		list[d_i] += list[s_i];
		list[s_i] = 0;
		mx_size = max(mx_size, list[d_i]);
	}

	void read_data(void)
	{
		cin >> n >> m;

		parent.resize(n);
		for(int i = 0; i < n; ++i){
			parent[i] = i;
		}
		
		rank.resize(n, 0);

		list.resize(n);
		for(int i = 0; i < n; ++i){
			cin >> list[i];
			mx_size = max(mx_size, list[i]);
		}

		for(int i = 0, d, s; i < m; ++i){
			cin >> d >> s;

			merge(d, s);
			write_data();
		}
	}

public:
	void solve(void)
	{
		read_data();
	}
};

int main(void)
{
	ios_base::sync_with_stdio(false);
	DisjointSets disjoint;
	disjoint.solve();

	return 0;
}
