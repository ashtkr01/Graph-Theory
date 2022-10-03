#include <bits/stdc++.h>
using namespace std;

class graph
{
    int v;
    list<int> *l;

public:
    graph(int v)
    {
        this->v = v;
        l = new list<int>[v];
    }

    void addEdge(int u, int v)
    {
        l[u].push_back(v);
    }

    bool dfsHelperCycle(int node, bool *visited, int *parent)
    {
        for (auto x : l[node])
        {
            if (visited[x] == true and parent[node] == x)
            {
                return true;
            }
            else if (!visited[x])
            {
                visited[x] = true;
                parent[x] = node;
                bool res = dfsHelperCycle(x, visited, parent);
                if (res == true)
                {
                    return true;
                }
                visited[x] = false;
                parent[x] = -1;
            }
        }
        return false;
    }

    bool dfsCycle()
    {
        bool *visited = new bool[v]{false};
        int *parent = new int[v]{-1};
        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                visited[i] = true;
                parent[i] = i;

                bool result = dfsHelperCycle(i, visited, parent);
                if (result == true)
                {
                    return true;
                }
                visited[i] = false;
                parent[i] = -1;
            }
        }
        return false;
    }

     bool dfsHelperComplete(int node, bool *visited, int &cnt)
    {
        if(cnt == v)
        {
            return true;
        }
        for (auto x : l[node])
        {
            if (!visited[x])
            {
                visited[x] = true;
                cnt++;
                bool res = dfsHelperComplete(x, visited, cnt);
                if (res == true)
                {
                    return true;
                }
                visited[x] = false;
                cnt--;
            }
        }
        return false;
    }

    bool dfsComplete()
    {
         bool *visited = new bool[v]{false};
        int cnt = 0;
        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                visited[i] = true;
               cnt++;

                bool result = dfsHelperComplete(i, visited, cnt);
                if (result == true)
                {
                    return true;
                }
                visited[i] = false;
               cnt--;
            }
        }
        return false;
    }
    void display()
    {
        for (int i = 1; i < v; i++)
        {
            cout << i << "-->";
            for (auto x : l[i])
            {
                cout << x << " ";
            }
            cout << endl;
        }
    }
};


bool canFinish(vector<vector<int>> prerequisites,int numCourses) {
    graph g(numCourses);
    for(auto x : prerequisites)
    {
        g.addEdge(x[1] , x[0]);
    }
    cout<<"DFS-Complete : "<<g.dfsComplete()<<endl;
    cout<<"DFS-Cycle  "<<g.dfsCycle()<<endl;
    if(g.dfsComplete() == true and g.dfsCycle() == false)
    {
        return true;
    }
    else{
        return false;
    }
        
}
//Main:
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    vector<vector<int> > vctr {{1 , 0} };
    cout<<canFinish(vctr , n)<<endl;
    return 0;
}
