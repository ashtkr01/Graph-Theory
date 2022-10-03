#include<bits/stdc++.h>
using namespace std;
//Class:
class edge
{
    public:
          int u , v , wt;
          edge(int u , int v , int wt)
          {
            this->u = u;
            this->v = v;
            this->wt = wt;
          }
};
class myComparator
{
    public:
           int operator()(const edge &e1 , const edge &e2)
           {
               return e1.wt > e2.wt;
           }
};
//Graph:
class graph
{
    int v;
    list<pair<int , int>> *l;
                              public:
                                    graph(int v)
                                    {
                                        this->v = v;
                                        l = new list<pair<int , int>>[v];
                                    }
                                    void addEdge(int u , int v , int wt)
                                    {
                                        l[u].push_back(make_pair(v , wt));
                                    }
                                    //Find by Compression:
                                    int find_set(int a , int *parent)
                                    {
                                        if(parent[a] == a)
                                        {
                                            return a;
                                        }
                                        parent[a] = find_set(parent[a] , parent);
                                        //REturn :
                                        return parent[a];
                                    }
                                    //UNion By Compression:
                                    int union_set(int a , int b , int *rank , int *parent)
                                    {
                                        int s1 = find_set(a , parent);
                                        int s2 = find_set(b , parent);
                                        if(s1 != s2)
                                        {
                                            if(rank[s1] < rank[s2])
                                            {
                                                parent[s1] = s2;
                                                rank[s2] += s1;
                                            }
                                            else{
                                                parent[s2] = s1;
                                                rank[s1] += rank[s2];
                                            }
                                            return true;
                                        }
                                        else{
                                            return false;
                                        }
                                    }
                                    vector<vector<int>  > mstGenerate()
                                    {
                                        vector<vector<int> > result;
                                        int *parent = new int[v]{-1};
                                        int *rank = new int[v]{1};
                                        //Iterate all the vertex:
                                        for(int i=0;i<v;i++)
                                        {
                                            parent[i] = i;
                                        }
                                        priority_queue<edge , vector<edge> , myComparator> p;

                                        for(int i=0;i<v;i++)
                                        {
                                            for(auto x : l[i])
                                            {
                                                p.push(edge(i , x.first , x.second));
                                            }
                                        }
                                        //Iterate till queue become empty:
                                        while(!p.empty())
                                        {
                                            edge element = p.top();
                                            p.pop();
                                            bool res = union_set(element.u , element.v , rank , parent);
                                            if(res == true)
                                            {
                                                result.push_back({element.u , element.v , element.wt});
                                            }

                                        }
                                        return result;
                                    }
};

int main(int argc, char const *argv[])
{
    int n , edge;
    vector<vector<int> > result;
    cin>>n>>edge;
    graph g(n+1);
    int a , b ,c;
    while(edge--)
    {
        cin>>a>>b>>c;
        g.addEdge(a , b , c);
    }
    result = g.mstGenerate();
    //Print the vector:
    cout<<"Answer : "<<endl;
    for(int i=0;i<result.size();i++)
    {
        for(int j=0;j<result[0].size();j++)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
