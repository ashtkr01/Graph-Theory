#include<bits/stdc++.h>
using namespace std;

class graph{
   int v;
   list<int> *l;
               public:
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

                      //DFS Helper:
                      void dfsHelper(int node , int &cnt , bool *visited)
                      {
                        visited[node] = true;
                        cnt++;
                        for(auto x : l[node])
                        {
                            if(!visited[x])
                            {
                                dfsHelper(x , cnt , visited);
                            }
                        }
                      }

                      bool dfs(int source)
                      {
                        bool *visited = new bool[v]{false};
                        int cnt = 0;

                        dfsHelper(source , cnt , visited);
                        if(cnt == v)
                        {
                            return true;
                        }

                        return false;

                       
                      }

};

bool canVisitAllRooms(vector<vector<int>> rooms) {
    int size = rooms.size();
    graph g(size);
    for(int i=0;i<size;i++)
    {
        for(auto x : rooms[i])
        {
            g.addEdge(i , x);
        }
    }

    return g.dfs(0);
   
}

//Main Function:
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
