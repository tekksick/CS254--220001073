#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class UnionFind
{
private:
	vector<int> parent;
	vector<int> rank;

public:
	UnionFind(int n)
	{
		parent.resize(n);
		rank.resize(n);
		for (int i = 0; i < n; ++i)
		{
			parent[i] = i;
			rank[i] = 0;
		}
	}

	int find(int x)
	{
		if (parent[x] != x)
		{
			parent[x] = find(parent[x]);
		}
		return parent[x];
	}

	void unionSets(int x, int y)
	{
		int rootX = find(x);
		int rootY = find(y);
		if (rootX != rootY)
		{
			if (rank[rootX] < rank[rootY])
			{
				parent[rootX] = rootY;
			}
			else if (rank[rootX] > rank[rootY])
			{
				parent[rootY] = rootX;
			}
			else
			{
				parent[rootY] = rootX;
				rank[rootX]++;
			}
		}
	}
};

struct Edge
{
	int u, v, weight;
	Edge(int _u, int _v, int _weight) : u(_u), v(_v), weight(_weight) {}
};

bool compareEdges(const Edge &e1, const Edge &e2)
{
	return e1.weight > e2.weight;
}

vector<Edge> maximumSpanningTree(vector<vector<int>> &graph)
{
	int n = graph.size();
	vector<Edge> edges;
	for (int u = 0; u < n; ++u)
	{
		for (int v = u + 1; v < n; ++v)
		{
			if (graph[u][v] != 0)
			{
				edges.push_back(Edge(u, v, graph[u][v]));
			}
		}
	}
	sort(edges.begin(), edges.end(), compareEdges);

	UnionFind uf(n);
	vector<Edge> mstEdges;

	for (const Edge &edge : edges)
	{
		if (uf.find(edge.u) != uf.find(edge.v))
		{
			mstEdges.push_back(edge);
			uf.unionSets(edge.u, edge.v);
		}
	}

	return mstEdges;
}

int main()
{
	vector<vector<int>> graph = {
		{0, 2, 0, 6, 0},
		{2, 0, 3, 8, 5},
		{0, 3, 0, 0, 7},
		{6, 8, 0, 0, 9},
		{0, 5, 7, 9, 0}};

	vector<Edge> mst = maximumSpanningTree(graph);

	cout << "Maximum Spanning Tree Edges:" << endl;
	for (const Edge &edge : mst)
	{
		cout << edge.u << " - " << edge.v << " : " << edge.weight << endl;
	}

	return 0;
}
