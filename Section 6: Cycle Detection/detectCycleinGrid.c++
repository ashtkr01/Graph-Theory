#include<bits/stdc++.h>
using namespace std;

class graph{
    int v;
    list<int> *l;
                 public :
                        graph(int v)
                        {
                            this->v = v;
                            l = new list<int>[v];
                        }
                        void addEdge(int u , int v , bool undirected = true)
                        {
                            l[u].push_back(v);
                            if(undirected)
                            {
                            l[v].push_back(u);
                            }
                        }
                        //DFS Cycle Helper :
                        bool dfsCycleHelper(int node , bool *visited , int *parent)
                        {
                            for(auto nbr : l[node])
                            {
                                if(visited[nbr] == true and parent[node] != nbr)
                                {
                                    return true;
                                }
                                if(!visited[nbr])
                                {
                                    visited[nbr] = true;
                                    parent[nbr] = node;
                                    bool res = dfsCycleHelper(nbr , visited , parent);
                                    if(res)
                                    {
                                        return true;
                                    }
                                }
                            }
                            return false;
                        }

                        bool dfsCycle()
                        {
                            bool *visited = new bool[v]{false};
                            int *parent = new int[v]{-1};

                            for(int i=0;i<v;i++)
                            {
                                if(!visited[i])
                                {
                                    visited[i] = true;
                                    parent[i] = -1;
                                    bool result = dfsCycleHelper( i , visited , parent);
                                    if(result)
                                    {
                                        return true;
                                    }
                                }
                            }
                            return false;
                        }

};

bool containsCycle(vector<vector<char>> grid) {
    int row = grid.size();
    int col = grid[0].size();

    //Graph
    int n = row * col;
    graph g(n);

    for(int i = 0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(i > 0)
            {
                if(grid[i][j] == grid[i-1][j])
                {
                    g.addEdge(col * (i-1) + j , col * (i) + j);
                }

            }
            if(j != col-1)
            {
                if(grid[i][j] == grid[i][j+1])
                {
                    g.addEdge(col * i + j , col * i + (j + 1));
                }
            }
        }
    }
    bool result = g.dfsCycle();
    //Return Answer :
    return result;
}

//Main:
int main(int argc, char const *argv[])
{
    vector<vector<char> > vctr = {{'a' , 'e' , 'a' , 'b'} , 
                                    {'a' , 'e' , 'a' , 'b'} , 
                                    {'c' , 'a' , 'c' , 'b'} , 
                                    {'c' , 'a' , 'c' , 'b'} };
    
    //Calling:
    cout<<containsCycle(vctr)<<endl;
    return 0;
}
