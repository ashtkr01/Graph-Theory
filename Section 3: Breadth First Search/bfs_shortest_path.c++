#include <bits/stdc++.h>
#define int long long int
#define F first
#define S second
#define pb push_back

using namespace std;

class graph
{
	int v;
	list<int> *l;

public:
	graph(int v)
	{
		this->v = v;
		l = new list<int>[v];
	}
	void addEdge(int u, int v, bool undirected = true)
	{
		// cout<<"Hi"<<endl;
		l[u].push_back(v);
		if (undirected)
		{
			l[v].push_back(u);
		}
	}
	void display()
	{
		for (int i = 0; i < v; i++)
		{
			cout << i << " --> ";
			for (auto x : l[i])
			{
				cout << x << "--";
			}
			cout << endl;
		}
	}
	// BFS:
	void bfs_shortest_path(int src, int dest)
	{
		int cnt = 0;
		queue<int> qu;
		bool *visited = new bool[v]{0};
		int *dist = new int[v]{0};
		int *parent = new int[v]{-1};
		qu.push(src);
		visited[src] = true;
		parent[src] = src;
		dist[src] = 0;

		while (!qu.empty())
		{
			int ele = qu.front();
			cout << ele << endl;
			qu.pop();

			// Iterate the neighbours :
			for (auto x : l[ele])
			{
				if (!visited[x])
				{
					parent[x] = ele;
					dist[x] = dist[ele] + 1;
					qu.push(x);
					visited[x] = true;
				}
			}
		}
		cout << "Distance between source " << src << " and destination " << dest << " is : " << dist[dest] << endl;
		cout << "Print the path :" << endl;
		int curr = dest;
		cout << dest << "<--";
		while (curr != src)
		{
			cout << parent[curr] << "<--";
			curr = parent[curr];
		}
	}
};
int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	graph *g = new graph(n);
	while (!cin.eof())
	{
		int u, v;
		cin >> u >> v;
		// cout<<"Hi"<<endl;
		g->addEdge(u, v);
	}
	// Display:
	//  cout<<"Hi"<<endl;
	g->display();
	// Bfs Traversal:
	g->bfs_shortest_path(1, 6);
	// cout<<"Hi"<<endl;
}