#include<bits/stdc++.h>
using namespace std;
//Class Grapgh:
class graph{
int v;
list<pair<int , int>> *l;
            public:
                   graph(int v)
                   {
                    this->v = v;
                    l = new list<pair<int,int>>[v];
                   }
                   //Add EDgte:
                   void addEdge(int u , int v , int wt , bool undirected = true)
                   {
                    l[u].push_back({v , wt});
                    l[v].push_back({u , wt});
                   }
                   //:
                   int dijkshtraAlgo(int src , int dest)
                   {
                    vector<bool> visited(v , false);
                    vector<int> dist(v , INT_MAX);
                    set<pair<int,int>> st;

                    dist[src] = 0;
                    st.insert({dist[src] , src});

                    while(!st.empty())
                    {
                       auto it = st.begin();
                       int nodeDist = it->first;
                       int node = it->second;

                       st.erase(it);

                       //Iterate neighbours:
                       for(auto nbr : l[node])
                       {
                        if(!visited[nbr.first])
                        {
                            int tempDist = dist[node] + nbr.second;
                            if(st.find({dist[nbr.first] , nbr.first}) != st.end())
                            {
                                it = st.find({dist[nbr.first] , nbr.first});
                                if(tempDist < dist[nbr.first])
                                {
                                    st.erase(it);
                                    dist[nbr.first] = tempDist;
                                    st.insert({dist[nbr.first] , nbr.first});
                                }
                            }
                            else{
                                if(tempDist < dist[nbr.first])
                                {
                                    // st.erase(it);
                                    dist[nbr.first] = tempDist;
                                    st.insert({dist[nbr.first] , nbr.first});
                                }
                            }
                        }
                       }
                       visited[node] = true;
                    }
                    return dist[dest];

                    
                   }
};
int main(int argc, char const *argv[])
{
    graph g(5);
    //Add Edge:
    g.addEdge(0 , 1 , 1);
    g.addEdge(0 , 3 , 7);
    g.addEdge(0 , 2 , 4);
    g.addEdge(3 , 2 , 2);
    g.addEdge(1 , 2 , 1);
    g.addEdge(3 , 4 , 3);

    int answer = g.dijkshtraAlgo(0 , 3szw);
    cout<<"Answer : "<<answer<<endl;
    /* code */
    return 0;
}
