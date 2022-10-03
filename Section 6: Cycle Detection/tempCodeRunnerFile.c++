
#include<bits/stdc++.h>
using namespace std;

class graph{
    int v;
    list<int> *l;
                 public :
                        graph(int v)
                        {
                            this->v = v;
                            l = new list<int>[v];
                        }
                        void addEdge(int u , int v , bool undirected = true)
                        {
                            l[u].push_back(v);
                            if(undirected)
                            {
                            l[v].push_back(u);
                            }
                        }
                        //DFS Cycle Helper :
                        void dfsCycleHelper(int node , bool *visited , bool *stack , int *parent , int *dist , int &distance)
                        {
                            for(auto nbr : l[node])
                            {
                                if(stack[nbr] == true and parent[node] != nbr and dist[node] != -1)
                                {
                                    int temp = abs(dist[node] - dist[nbr]);
                                    distance = min(distance , dist[node]);
                                    // return;
                                    // cout<<distance<<endl;
                                }
                                else if(!visited[nbr])
                                {
                                    visited[nbr] = true;
                                    parent[nbr] = node;
                                    dist[nbr] = dist[node] + 1;
                                    dfsCycleHelper(nbr , visited , stack, parent , dist ,  distance);
                                    // if(res)
                                    // {
                                    //     return true;
                                    // }
                                    visited[nbr] = false;
                                    stack[nbr] = false;
                                    dist[nbr] = -1;
                                }
                            }
                            // return false;
                        }

                        int dfsCycle()
                        {
                            bool *visited = new bool[v]{false};
                            bool *stack = new bool[v]{false};
                            int *parent = new int[v]{-1};
                            int *dist = new int[v]{-1};
                            int distance = INT_MAX;

                            for(int i=0;i<v;i++)
                            {
                                if(!visited[i])
                                {
                                    visited[i] = true;
                                    parent[i] = i;
                                    dist[i] = 1;
                                    stack[i] = true;
                                    dfsCycleHelper( i , visited , stack , parent , dist , distance);
                                    // if(result)
                                    // {
                                    //     return true;
                                    // }
                                    // visited[i] = false;
                                    dist[i] = -1;
                                    stack[i] = false;
                                }
                            }
                            return distance;
                        }

};


int solve(int n,vector<vector<int>> edges){
    
    graph g(n);

    for(auto x : edges)
    {
        g.addEdge(x[0] , x[1]);
    }
    int result = g.dfsCycle();
    if(result == INT_MAX)
    {
        return -1;
    }
    return result;
}