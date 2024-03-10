#include <bits/stdc++.h>
using namespace std;

int dfs(int u, int p, vector<vector<int>> &adj, vector<int> &disc, vector<int> &low, int &timer, vector<bool> &ap, vector<pair<int, int>> &bridges)
{
	int children = 0;
	disc[u] = low[u] = timer++;
	for (int v : adj[u])
	{
		if (v == p)
			continue;
		if (disc[v] == 0)
		{
			children++;
			dfs(v, u, adj, disc, low, timer, ap, bridges);
			if (disc[u] <= low[v])
				ap[u] = true;
			if (disc[u] < low[v])
				bridges.emplace_back(u, v);
			low[u] = min(low[u], low[v]);
		}
		else
		{
			low[u] = min(low[u], disc[v]);
		}
	}
	return children;
}

int main()
{
	freopen("input5.txt", "r", stdin);
	freopen("output5.txt", "w", stdout);
	int v, e;
	cin >> v >> e;
	vector<vector<int>> adj(v + 1);
	vector<int> disc(v + 1);
	vector<int> low(v + 1);
	vector<bool> ap(v + 1);
	vector<pair<int, int>> bridges;
	for (int i = 0; i < e; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int timer = 0;
	for (int i = 1; i <= v; i++)
	{
		if (disc[i] == 0)
		{
			if (dfs(i, 0, adj, disc, low, timer, ap, bridges) > 1)
				ap[i] = true;
		}
	}
	cout << "Articulation Points:\n";
	for (int i = 1; i <= v; i++)
	{
		if (ap[i])
			cout << i << " ";
	}
	cout << "\nBridges:\n";
	for (auto bridge : bridges)
	{
		cout << "(" << bridge.first << "," << bridge.second << ") ";
	}
}