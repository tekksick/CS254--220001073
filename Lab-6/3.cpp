#include <iostream>
#include <list>
#include <stack>

using namespace std;

class Graph
{
	int V;
	list<int> *adj;
	void fillOrder(int s, bool visitedV[], stack<int> &Stack);
	void DFS(int s, bool visitedV[]);

public:
	Graph(int V);
	void addEdge(int s, int d);
	void printSCC();
	Graph transpose();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

// DFS
void Graph::DFS(int s, bool visitedV[])
{
	visitedV[s] = true;
	cout << s << " ";

	list<int>::iterator i;
	for (i = adj[s].begin(); i != adj[s].end(); ++i)
		if (!visitedV[*i])
			DFS(*i, visitedV);
}

// Transpose
Graph Graph::transpose()
{
	Graph g(V);
	for (int s = 0; s < V; s++)
	{
		list<int>::iterator i;
		for (i = adj[s].begin(); i != adj[s].end(); ++i)
		{
			g.adj[*i].push_back(s);
		}
	}
	return g;
}

// Add edge into the graph
void Graph::addEdge(int s, int d)
{
	adj[s].push_back(d);
}

void Graph::fillOrder(int s, bool visitedV[], stack<int> &Stack)
{
	visitedV[s] = true;

	list<int>::iterator i;
	for (i = adj[s].begin(); i != adj[s].end(); ++i)
		if (!visitedV[*i])
			fillOrder(*i, visitedV, Stack);

	Stack.push(s);
}

// Print strongly connected component
void Graph::printSCC()
{
	stack<int> Stack;

	bool *visitedV = new bool[V];
	for (int i = 0; i < V; i++)
		visitedV[i] = false;

	for (int i = 0; i < V; i++)
		if (visitedV[i] == false)
			fillOrder(i, visitedV, Stack);

	Graph gr = transpose();

	for (int i = 0; i < V; i++)
		visitedV[i] = false;

	while (Stack.empty() == false)
	{
		int s = Stack.top();
		Stack.pop();

		if (visitedV[s] == false)
		{
			gr.DFS(s, visitedV);
			cout << endl;
		}
	}
}

int main()
{
	freopen("input3.txt", "r", stdin);
	freopen("output3.txt", "w", stdout);
	int n;
	cin >> n;
	Graph g(n);
	int no_edges;
	cin >> no_edges;
	for (int i = 0; i < no_edges;i++) {
		int u, v;
		cin >> u >> v;
		g.addEdge(u, v);
	}

	cout << "Strongly Connected Components:\n";
	g.printSCC();
}
//tc: o(v+e)