#include<bits/stdc++.h>
using namespace std;

//Implementation of graph
class graph
{
    int v;
    list<int> *l;
          public:
                 graph(int v)
                 {
                    this->v = v;
                    l = new list<int>[v+1];
                 }

                 void addEdge(int u , int v , bool undirected = true)
                 {
                    l[u].push_back(v);
                    if(undirected)
                    {
                        l[v].push_back(u);
                    }
                 }

                 bool bfsTraversal(int source , vector<int> sequence , vector<vector<int>> edges)
                 {
                    queue<int> qu;
                    bool *visited = new bool[v + 1];
                    int *parent = new int[v + 1];
                    for(int i=0;i<=v;i++)
                    {
                        visited[i] = false;
                        parent[i] = 0;
                    }

                    qu.push(source);
                    visited[source] = true;
                    parent[source] = 0;

                    // int idx = 1;
                    

                    while(!qu.empty())
                    {
                        int ele = qu.front();
                        cout<<ele<<endl;
                        qu.pop();

                        

                        for(auto x : l[ele])
                        {
                            if(!visited[x])
                            {
                                // us.insert(x);
                                qu.push(x);
                                
                                visited[x] = true;
                                parent[x] = ele;
                                
                            }

                        }
                        
        

                    }

                    int j=1;
                    int i=0;
                    while(j<=v)
                    {
                        if(parent[j] ==)
                    }
                    return true;

                 }


};
// /Comparator
// bool compare(vector<int> a , vector<int> b)
// {
//     if(a[0] != b[0])
//     {
//         return a[0] < b[0];
//     }
//     else{
//         return a[1] < b[1];
//     }
// }
bool validBfs(int n, vector<int> sequence , vector<vector<int>> edges)
{
 //Sort the vector edges:
//  sort(edges.begin() , edges.end() , compare);  
 //Create graph:
 graph g(n);
 for(auto x : edges)
 {
    g.addEdge(x[0] , x[1]);
 } 

 bool result = g.bfsTraversal(1 , sequence , edges);
 return result;

}


//Main Function:
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    vector<int> sequence ={1,5,2,3,4,6};
    vector<vector<int> > edges = {{1,2},{2,3},{2,4},{1,5},{5,6}};
    cout<<validBfs(n , sequence , edges)<<endl;
    /* code */
    return 0;
}
