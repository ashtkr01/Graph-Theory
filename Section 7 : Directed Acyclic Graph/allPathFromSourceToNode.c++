#include<bits/stdc++.h>
using namespace std;

class Graph{
    int v;
    list<int> *l;
                public :
                       Graph(int v)
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
                       //Helper :
                       void dfsHelper(int node , int dest , vector<vector<int> > &vctr , vector<int> &temp , bool *stack)
                       {
                        if(node == dest)
                        {
                            vctr.push_back(temp);
                        }
                        for(auto nbr : l[node])
                        {
                            if(!stack[nbr])
                            {
                                stack[nbr] = true;
                                temp.push_back(nbr);
                                dfsHelper(nbr , dest , vctr , temp , stack);
                                temp.pop_back();
                                stack[nbr] = false;
                            }
                        }
                       }

                       vector<vector<int> > dfs()
                       {
                        vector<vector<int>> vctr;
                        vector<int> temp;
                        bool *stack = new bool[v]{false};

                        temp.push_back(0);
                        stack[0] = true;

                        dfsHelper( 0 , v-1 , vctr , temp , stack);
                        return vctr;

                       }
};

vector<vector<int>> allPathsSourceTarget(vector<vector<int>> graph) {
     int n = graph.size();
     Graph g(n);

     for(int i=0;i<n;i++)
     {
        for(int j = 0;j<graph[i].size();j++)
        {
            g.addEdge(i , graph[i][j]);
        }
     }
     vector<vector<int> > results = g.dfs();
     return results;
}

//Main:
int main(int argc, char const *argv[])
{
    vector<vector<int> > vctr = {{1 , 2} , {3} , {3} , {}};
    // cout<<vctr.size()<<endl;
    vector<vector<int> > result = allPathsSourceTarget(vctr);
    for(auto x : result )
    {
        for(auto y : x)
        {
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;
}
