#include<bits/stdc++.h>
using namespace std;
// Cycle detection in an undirected graph using DSU :
class graph{
int v;
list<pair<int , int>> l;
                        public:
                              graph (int v)
                              {
                                this->v = v;
                              }
                              void addEdge(int u , int v)
                              {
                                l.push_back(make_pair(u , v));
                              }
                              //Find function in c++
                              int find_set(int a , int *parent)
                              {
                                if(parent[a] == a)
                                {
                                    return a;
                                }
                                return find_set(parent[a] , parent);
                              }
                              //UNion Function:
                              bool union_set(int a , int b , int *parent)
                              {
                                int s1 = find_set(a , parent);
                                int s2 = find_set(b , parent);

                                if(s1 != s2)
                                {
                                    parent[s2] = s1;
                                    return false;
                                }
                                else{
                                    return true;
                                }
                              }
                              bool containsCycle()
                              {
                                int *parent = new int[v]{-1};
                                for(int i=1;i<v;i++)
                                {
                                    parent[i] = i;
                                }
                                for(auto x : l)
                                {
                                    bool res = union_set(x.first , x.second , parent);
                                    if(res == true)
                                    {
                                        return true;
                                    }
                                }
                                // delete [] parent;
                                return false;
                              }
};
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    graph g(n);

    g.addEdge(1 , 2);
    g.addEdge(2 , 3);
    // g.addEdge(3 , 4);
    g.addEdge(4 , 1);

    cout<<"Answer : "<<g.containsCycle()<<endl;

    /* code */
    return 0;
}
