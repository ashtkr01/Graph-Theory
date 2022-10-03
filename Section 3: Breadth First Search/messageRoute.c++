#include<bits/stdc++.h>
using namespace std;

class graph{
    int v;
    list<int> *l;
            public:
                  graph(int v)
                  {
                    this->v = v;
                    l = new list<int>[v + 1];
                  }

                  void addEdge(int u , int v , bool undirected = true)
                  {
                    l[u].push_back(v);
                    if(undirected)
                    {
                        l[v].push_back(u);
                    }
                  }

                  int bfsTraversal(int source , int destination)
                  {
                    bool *visited = new bool[v + 1];
                    int *dist = new int[v + 1];
                    for(int i=1;i<=v;i++)
                    {
                        visited[i] = false;
                        dist[i] = -1;
                    }

                    queue<int> qu;
                    qu.push(source);
                    visited[source] = true;
                    dist[source] = 1;

                    while(!qu.empty())
                    {
                        int ele = qu.front();
                        qu.pop();

                        for(auto x : l[ele])
                        {
                            if(!visited[x])
                            {
                                qu.push(x);
                                visited[x] = true;
                                dist[x] = dist[ele] + 1;
                            }
                        }
                    }
                    return dist[destination];


                  }
};

int messageRoute(int n, vector<vector<int>>edges)
{
    graph g(n);
    for(auto x : edges)
    {
        g.addEdge(x[0] , x[1]);
    }
    return g.bfsTraversal(1 , n);
}