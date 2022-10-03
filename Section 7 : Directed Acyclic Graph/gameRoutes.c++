#include<bits/stdc++.h>
using namespace std;

//Graph:
class graph
{
    int v;
    list<int> *l;
                public :
                       graph(int v)
                       {
                        this->v = v;
                        l = new list<int>[v];
                       }

                       void addEdge(int u , int  v , bool undirected = false)
                       {
                        l[u].push_back(v);
                        if(undirected)
                        {
                            l[v].push_back(u);
                        }
                       }
                       //Function:
                       int routes()
                       {
                        int *indegree = new int[v]{0};
                        int *path = new int[v]{0};
                        for(int i=1;i<v;i++)
                        {
                            for(auto x : l[i])
                            {
                                indegree[x]++;
                            }
                        }

                        queue<int> qu;
                        for(int i=1;i<v;i++)
                        {
                            if(indegree[i] == 0 and i == 1)
                            {
                                path[i] = 1;
                                qu.push(i);
                            }
                        }

                        while(!qu.empty())
                        {
                            int ele = qu.front();
                            qu.pop();
                            for(auto nbr : l[ele])
                            {
                                path[nbr] = path[nbr] + path[ele];
                                indegree[nbr]--;
                                if(indegree[nbr] == 0)
                                {
                                qu.push(nbr);
                                }
                            }

                        }
                        return path[v-1];

                       }
};
int gameRoutes(int n, vector<vector<int>> edges)
{
    graph g(n+1);

    for(auto x : edges)
    {
        g.addEdge(x[0] , x[1]);
    }
    int res = g.routes();
}

//Main:
int main(int argc, char const *argv[])
{
   int n;
   cin>>n;
//    vector<vector<int>> edge = {{1 , 2} , {1 , 3} , {2 , 3} , {1 , 4} , {4 , 5}};
vector<vector<int > > edge = {{1 , 2} , {2 , 3} , { 2 , 4}, {3 , 5} , {4 , 5} , {5 , 6}, {6 , 7}, {6 , 8} , {7 , 9} , {8 , 9}};
   int ans = gameRoutes(n , edge);
   cout<<"Answer : "<<ans<<endl;
    return 0;
}
