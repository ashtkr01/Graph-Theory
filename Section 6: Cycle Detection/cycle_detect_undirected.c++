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

    void addEdge(int u, int v, bool undirected = true)
    {
        l[u].push_back(v);
        if (undirected)
        {
            l[v].push_back(u);
        }
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
            }
        }
        return false;
    }
};

bool solve(int n, vector<vector<int>> edges)
{
    graph g(n + 1);
    for (auto x : edges)
    {
        g.addEdge(x[0], x[1]);
    }
    bool result = g.dfs();
}

// Main:
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
