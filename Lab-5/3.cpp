#include <bits/stdc++.h>
using namespace std;

int n;

bool is_bipartite(int s, int c, vector<int> &temp, vector<vector<bool>> &g)
{
	if (temp[s] > -1)
	{
		if (c != temp[s])
			return false;
		return true;
	}
	temp[s] = c;
	for (int i = 0; i < n; i++)
		if (g[s][i] && !is_bipartite(i, 1 - c, temp, g))
			return false;
	return true;
}

int main()
{
	freopen("input3.txt", "r", stdin);
	freopen("output3.txt", "w", stdout);
	cin >> n;
	vector<vector<int>> adj(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)		
			cin>>adj[i][j];
	}
	vector<int> temp(n, -1);
	int ans = -1, d = 0;
	for (int i = 0; i < n; i++) {
		if (temp[i] == -1) {
			if (ans != -1) {
				cout << "No"<<endl;
				d = 1;
				break;
			}
			if (is_bipartite(i, 0, temp, adj))
				ans = 1;
			else
				ans = 0;
		}
	}
	if(d!=1){
	if (ans)
		cout << "Yes"<<endl;
	else
		cout << "No"<<endl;
	}
}