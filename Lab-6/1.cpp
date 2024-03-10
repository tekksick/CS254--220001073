#include <bits/stdc++.h>
using namespace std;

void TS(int v, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &Stack)
{
	visited[v] = true;

	for (int i : adj[v])
	{
		if (!visited[i]) TS(i, adj, visited, Stack);
	}

	Stack.push(v);
}

void topologicalSort(vector<vector<int>> &adj, int V)
{
	stack<int> Stack; 
	vector<bool> visited(V, false);

	for (int i = 0; i < V; i++)
	{
		if (!visited[i])
			TS(i, adj, visited, Stack);
	}

	while (!Stack.empty())
	{
		cout << Stack.top() << " ";
		Stack.pop();
	}
}

int main()
{
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
	int V,no_edges;
	cin >> V>>no_edges;
	vector<vector<int>> adj(V);

	for (int i = 0; i < no_edges;i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}

	cout << "Topological sorting of the graph: ";
	topologicalSort(adj, V);
}
