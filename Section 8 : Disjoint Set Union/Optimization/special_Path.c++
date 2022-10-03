#include<bits/stdc++.h>
using namespace std;
//Graph :
class graph{
int v;
list<pair<int , int> > *l;
                         public:
                                graph(int v)
                                {
                                    this->v = v;
                                    l = new list<pair<int , int>>[v];
                                }

                                void addEdge(int u , int v , int wt , bool undirected = true)
                                {
                                    l[u].push_back(make_pair(v , wt));
                                    if(undirected)
                                    {
                                        l[v].push_back(make_pair(u , wt));
                                    }
                                }
                                //Dfs:
                                bool dfs(int node , int *visited , int &min_dist , int source , int dest)
                                {
                                    visited[node] = true;
                                    for(auto nbr : l[node])
                                    {
                                        if(!visited[nbr.first])
                                        {
                                        int ele = min_dist;
                                        min_dist = max(min_dist , nbr.second);
                                        if(nbr.first == dest)
                                        {
                                            return true;
                                        }
                                        bool res = dfs(nbr.first , visited , min_dist , source , dest);
                                        if(res == true)
                                        {
                                            return true;
                                        }
                                        min_dist = ele;

                                        }
                                    }
                                    return false;
                                }
                                //Helper:
                                int helper(int source , int dest )
                                {
                                    int *visited = new int[v]{0};
                                    int min_dist = INT_MIN;

                                    // for(int i=0;i<v;i++)
                                    // {
                                    //     if(!visited[i])
                                    //     {
                                          bool res =   dfs( source , visited , min_dist , source , dest);
                                          if(res == true)
                                          {
                                            return min_dist;
                                          }
                                    //     }
                                    // }
                                    return 0;
                                }

};
//Find By Union:
int find_set(int a , int *parent)
{
    if(parent[a] == a)
    {
        return a;
    }
    return parent[a] = find_set(parent[a] , parent);
}
//Union BY Rank:
bool union_set(int a , int b , int *rank , int *parent)
{
    int s1 = find_set(a , parent);
    int s2 = find_set(b , parent);

    if(s1 != s2)
    {
        if(rank[s1] < rank[s2])
        {
            parent[s1] = s2;
            rank[s2] += rank[s1];
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
//Comparator:
bool comparator(vector<int> a , vector<int> b)
{
    return a[2] < b[2];
}
int specialPath(int n, vector<int> a, vector<vector<int>> edges,int start, int end)
{
    vector<vector<int> > edge;
    int size = edges.size();
    for(int i=0;i<size;i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = abs(a[u - 1] - a[v - 1]);
        edge.push_back({u , v , wt});
    }
    //Sort the vector:
    sort(edge.begin() , edge.end() , comparator);
    graph g(n + 1);
    int *parent = new int[n + 1]{-1};
    for(int i=1;i<=n;i++)
    {
        parent[i] = i;
    }
    int *rank = new int[n + 1]{1};

    for(auto x : edge)
    {
        if(union_set(x[0] , x[1] , rank , parent)){
            g.addEdge(x[0] , x[1] , x[2]);
        }
    }
    //Call to the main function :
    int result = g.helper(start , end);
    //Return 
    return result;


}
//Main:
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    vector<int> vctr(n , 0);
    for(int i=0;i<n;i++)
    {
        cin>>vctr[i];
    }
    vector<vector<int> > edges = {{5 , 3} , {4 , 5} , {5 , 1} , {5 , 2}};

    //Call:
    int answer = specialPath(n , vctr , edges , 1 , 2);
    cout<<"Answer : "<<answer<<endl;
    return 0;
}
