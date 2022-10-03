#include <bits/stdc++.h>
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

    void addEdge(int u, int v)
    {
        l[u].push_back(v);
    }

    bool dfsHelper(int node, bool *visited, int *parent)
    {
        for (auto x : l[node])
        {
            if (visited[x] == true and parent[node] != x)
            {
                return true;
            }
            else if (!visited[x])
            {
                visited[x] = true;
                parent[x] = node;
                bool res = dfsHelper(x, visited, parent);
                if (res == true)
                {
                    return true;
                }
                visited[x] = false;
                parent[x] = -1;
            }
        }
        return false;
    }

    bool dfs()
    {
        bool *visited = new bool[v]{false};
        int *parent = new int[v]{-1};
        for (int i = 1; i < v; i++)
        {
            if (!visited[i])
            {
                visited[i] = true;
                parent[i] = i;

                bool result = dfsHelper(i, visited, parent);
                if (result == true)
                {
                    return true;
                }
                visited[i] = false;
                parent[i] = -1;
            }
        }
        return false;
    }
    void display()
    {
        for (int i = 1; i < v; i++)
        {
            cout << i << "-->";
            for (auto x : l[i])
            {
                cout << x << " ";
            }
            cout << endl;
        }
    }
};

bool solve(int n, vector<vector<int>> edges)
{
    graph g(n + 1);
    // Iterate the vector :
    for (auto x : edges)
    {
        g.addEdge(x[0], x[1]);
    }
    // Display :
    g.display();
    // Call:
    bool result = g.dfs();
    return result;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<vector<int>> vctr = {{1, 2}, {2, 3}, {3, 4}, {1, 4}, {1, 5}, {1, 6}, {6, 5}};
    cout << solve(n, vctr) << endl;
    return 0;
}
