#include<bits/stdc++.h>
using namespace std;
//Graph:
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
                                    return true;
                                }
                                else{
                                    return false;
                                }
                              }
                              bool contain_forests()
                              {
                              int cnt = 0;
                                int *parent = new int[v]{-1};
                                for(int i=0;i<v;i++)
                                {
                                    parent[i] = i;
                                }
                                for(auto x : l)
                                {
                                    bool res = union_set(x.first , x.second , parent);
                                    if(res == false)
                                    {
                                        return false;
                                    }
                                }
                                for(int i=0;i<v;i++)
                                {
                                    if(parent[i] == i)
                                    {
                                        cnt++;
                                    }
                                }
                                if(cnt > 0)
                                {
                                    return true;
                                }
                                // delete [] parent;
                                return false;
                              }
};
bool solve(vector<vector<int>> edges) {
    int res = INT_MIN;
    for(auto x : edges)
    {
        res = max(res , max(x[0] , x[1]));
    }
    //Graph:
    graph g(res + 1);

    for(auto x : edges)
    {
        g.addEdge(x[0] , x[1]);
    }
    bool result = g.contain_forests();
    return result;
}
//Main:
int main(int argc, char const *argv[])
{
    vector<vector<int> > edges = {{0 , 1} , {0 , 2} , {3 , 4} , {4 , 5}};
    bool result = solve(edges);
    cout<<"Answer : "<<result<<endl;
    /* code */
    return 0;
}
