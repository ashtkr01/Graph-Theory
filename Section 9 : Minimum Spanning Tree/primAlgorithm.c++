/* Prim Algorithm :
--> Weighted Undirected Graph
--> Greedy Algorithm:

Terms :
      MST set : []
      Active Edge = An edge from a vertex in MST set to V.
      MST Edge = An edge that has been included in MST till now

//Algorithm:
1--> Start from any source vertex .
2--> Out of all active edge pick the one with smallest weight,
    --> Select in Y in MST
    --> add edge starting from Y in the active edge list
*/
#include<bits/stdc++.h>
using namespace std;
//Class :
class edge
{
    public:
    int u;
    int v;
    int wt;
                 edge(int u , int v , int wt)
                 {
                    this->u = u;
                    this->v = v;
                    this->wt = wt;
                 }
};
//MyComparator:
class myComparator
{
    public:
    bool operator() (const edge &a , const edge &b)
    {
        return a.wt > b.wt;
    }
};
//Grap:
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
                                   //AddEDge:
                                   void addEdge(int u , int v , int wt , bool undirected = true)
                                   {
                                    l[u].push_back(make_pair(v , wt));
                                    if(undirected)
                                    {
                                        l[v].push_back(make_pair(u , wt));
                                    }
                                   }
                                   vector<vector<int> >  prim_Algorithm(int source)
                                   {
                                    vector<vector<int>> res;
                                    unordered_set<int> us;
                                    priority_queue<edge , vector<edge> , myComparator> pq;

                                    //Push first element:
                                    us.insert(source);
                                    for(auto nbr : l[source])
                                    {
                                        cout<<"Hello "<<endl;
                                    pq.push(edge(source , nbr.first , nbr.second));
                                    }

                                    while(!pq.empty())
                                    {
                                        edge ele = pq.top();
                                        pq.pop();
                                        
                                        if(us.find(ele.v) != us.end())
                                        {
                                            continue;
                                        }
                                        us.insert(ele.v);
                                        res.push_back({ele.u , ele.v , ele.wt});
                                        cout<<"Hi"<<endl;
                                        for(auto x : l[ele.v])
                                        {
                                            pq.push(edge(ele.v , x.first , x.second));
                                        }
                                    }
                                    return res;
                                   }
};
//Main:
//Output:
/*
9 14
1 2 10
1 3 12
2 4 8
3 6 1
3 3 5
5 4 7
5 6 3
4 6 10
4 7 8
4 8 5
6 8 6
7 8 9
7 9 2
8 9 11 */
int main(int argc, char const *argv[])
{
    /* code */
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
    result = g.prim_Algorithm(1);
    //Print the vector:
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
