#include<bits/stdc++.h>
using namespace std;

//Graph : 
class graphs
{
    int v;
    list<int> *l;

public:
    graphs(int v)
    {
        this->v = v;
        l = new list<int>[v];
    }

    void addEdge(int u, int v, bool undirected = true)
    {
        l[u].push_back(v);
        if (undirected)
        {
            l[v].push_back(u);
        }
    }

    //Helper :
    bool oddLengthCycleHelper(int node , bool *visited ,int *color , int colour , int parent)
    {
        for(auto nbr : l[node])
        {
            if(visited[nbr] and nbr != parent and color[nbr] == color[node])
            {
                return true;
            }
            if(!visited[nbr])
            {
                visited[nbr] = true;
                color[nbr] = 3 - colour;
                bool res = oddLengthCycleHelper(nbr , visited , color , 3-colour , node);
                if(res == true)
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool oddLengthCycle()
    {
        bool *visited = new bool[v]{false};
        int *color = new int[v]{0};
        
        for(int i=0;i<v;i++)
        {
            if(!visited[i])
            {
            visited[i] = true;
            color[i] = 1;
            bool result = oddLengthCycleHelper( i , visited , color , 1 , -1);
            if(result == true)
            {
                return true;
            } 
            }
        }
        return false;
    }
};

bool solve(vector<vector<int>> graph)
{
    int n = graph.size();

    graphs g(n);

    for(int i = 0;i<n;i++)
    {
        for(int j=0;j<graph[i].size();j++)
        {
            g.addEdge( i , graph[i][j]);
        }
    }
    bool result = g.oddLengthCycle();
    return result;
}

//Main:
int main(int argc, char const *argv[])
{
    // vector<vector<int> > vctr ={{1 , 2 , 3} , { 0 , 2},{0 , 1 , 3} , { 0 , 2}};
    vector<vector<int> > vctr ={{1 , 2} , { 0 , 3},{0 , 3} , { 1 , 2}};
    cout<<solve(vctr)<<endl;
    /* code */
    return 0;
}
