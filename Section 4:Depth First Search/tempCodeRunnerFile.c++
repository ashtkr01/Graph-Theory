
#include <bits/stdc++.h>
using namespace std;

// Graph:
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

    // DFS Helper:
    void dfsHelper(int node, int &cnt, bool *visited)
    {
        visited[node] = true;
        cnt++;
        for (auto x : l[node])
        {
            if (!visited[x])
            {
                dfsHelper(x, cnt, visited);
            }
        }
    }

    int dfs(vector<vector<int>> grid , int m , int n)
    {
        bool *visited = new bool[v]{false};
        int cnt = 0;
        int maximum = INT_MIN;

        for (int i = 0; i < v; i++)
        {
            cnt = 0;
            if (!visited[i] and grid[floor(i/n)][(i%n)] == 1)
            {
                dfsHelper(i, cnt, visited);
            }
            maximum = max(maximum, cnt);
        }
        return maximum;
    }
};

int maxAreaOfIsland(vector<vector<int>> grid)
{
    int m = grid.size();
    int n = grid[0].size();

    cout<<m<<" "<<n<<endl;

    int vertex = m * n;
    graph g(vertex );
    for (int i = 0; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if(j > 0)
            {
                 if (grid[i][j] == 1 and grid[i][j - 1] == 1)
            {
                g.addEdge(n * i + j - 1, n * i + j );
            }

            }
           
            if (i > 0)
            {
                if (grid[i - 1][j] == 1 and grid[i][j] == 1)
                {
                    g.addEdge(n * (i - 1) + j , n * i + j );
                }
            }
        }
    }

    int res = g.dfs(grid , m , n);
    return res;
}