#include <bits/stdc++.h>
using namespace std;

// Graph :
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

    void addEdge(int u, int v, bool undirected = false)
    {
        l[u].push_back(v);
        if (undirected)
        {
            l[v].push_back(u);
        }
    }
    // Maximum of unordered map
    int findMax(unordered_map<char, int> &col)
    {
        int ele = INT_MIN;
        for (auto x : col)
        {
            if (ele < x.second)
            {
                ele = x.second;
            }
        }
        return ele;
    }

    // hELPER :
    bool dfsHelper(int node, bool *visited, bool *stack, unordered_map<int, char> &um, unordered_map<char, int> &col, int &result , int *dp)
    {
        // if(dp[node] != -1 and visited[node] == true)
        // {
        //     result = result + dp[node];
        //     return false;
        // }
        visited[node] = true;
        stack[node] = true;
        col[um[node]]++;
        // Iterate Neigh bours :
        for (auto nbr : l[node])
        {
            if (stack[nbr] == true)
            {
                return true;
            }
            else if (!stack[nbr])
            {
                bool res = dfsHelper(nbr, visited, stack, um, col, result , dp);
                if (res == true)
                {
                    return true;
                }
            }
        }
      
        int maximum = findMax(col);
        result = max(result, maximum);
        // dp[node] = result;
        stack[node] = false;
        col[um[node]]--;

        return false;
    }

    int dfs(unordered_map<int, char> um, unordered_map<char, int> col)
    {
        bool *visited = new bool[v]{false};
        bool *stack = new bool[v]{false};
        int *dp = new int[v]{-1};
        int result = 0;

        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                bool res = dfsHelper(i, visited, stack, um, col, result , dp);
                if (res == true)
                {
                    return -1;
                }
            }
        }
        return result;
    }
};
int largestPathValue(string colors, vector<vector<int>> edges)
{
    int n = colors.size();
    unordered_map<int, char> um;
    unordered_map<char, int> col;
    unordered_set<char> us;
    for (int i = 0; i < n; i++)
    {
        // us.insert(colors[i]);
        um[i] = colors[i];
    }

    // for(auto x : us)
    // {
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    // for(auto x : um)
    // {
    //     cout<<x.first<<" "<<x.second<<endl;
    // }
    cout << "Total Nodes : " << n << endl;
    cout << "Total Color : " << us.size() << endl;

    // for (auto x : us)
    // {
    //     col[x] = 0;
    // }

    graph g(n);

    for (auto x : edges)
    {
        g.addEdge(x[0], x[1]);
    }
    // Call to the main Function :
    int result = g.dfs(um, col);
    return result;
}
// Main:
int main(int argc, char const *argv[])
{
    string str;
    cin >> str;
    // vector<vector<int>> vctr = {{0, 1}, {0, 2}, {2, 3}, {3, 4}};
    vector< vector<int > > vctr = {{0 , 1} , {1 , 2} , {2 , 3} , {3 , 4} , {3 , 5} , {4 , 5} , {3 , 6} , {5 , 6} , {6 , 7} , {5 , 7} , {3 , 7} , {6 , 8} , {5 , 8} , {4 , 8} , {8 , 9} , {9 , 10} , {10 , 11} , {9 , 11} , {9 , 12} , {11 , 12} , {6 , 12} , {11 , 13} , {9 , 13} , {13 , 14} , {12 , 14} , {10 , 14} , {11 , 14} , {13 , 15} , {14 , 15} , {12 , 16} , {9 , 16} , {7 , 16} , {15 , 17} , {13 , 17} , {17 , 18} , {11 , 18} , {17 , 19} , {18 , 19} , {13 , 19} , {17 , 20} , {18 , 20} , {19 , 21} , {17 , 21} , {12 , 22} , {21 , 22} , {16 , 22} , {22 , 23} , {21 , 23} , {16 , 24} , {22 , 24} , {15 , 25} , {24 , 25} , {20 , 25} , {12 , 25} , {23 , 26} , {26 , 27} , {13 , 27} , {27 , 28} , {21 , 28} , {26 , 28} , {28 , 29} , {15 , 30} , {27 , 30} , {24 , 30} , {21 , 30} , {27 , 31} , {30 , 31} , {25 , 32} , {29 , 32} , {17 , 33} , {31 , 33} , {32 , 33} , {25 , 34} , {33 , 35} , {31 , 35} , {34 , 35} , {30 , 36} , {35 , 37} , {36 , 37} , {26 , 38} , {36 , 38} , {34 , 38} , {37 , 38} , {38 , 39} , {22 , 39} , {39 , 40} , {40 , 41} , {38 , 41} , {20 , 41} , {41 , 42} , {37 , 42} , {40 , 43} , {42 , 43} , {43 , 44} , {41 , 44} , {32 , 44} , {38 , 44} , {39 , 44} , {43 , 45} , {44 , 45} , {44 , 46} , {45 , 46} , {45 , 47} , {42 , 47} , {43 , 48} , {45 , 49} , {45 , 50} , {48 , 51} , {30 , 51} , {46 , 52} , {48 , 52} , {38 , 52} , {51 , 52} , {47 , 53} , {45 , 53} , {53 , 54} , {48 , 54} , {30 , 54} , {50 , 55} , {30 , 55} , {36 , 55} , {55 , 56} , {39 , 56} , {54 , 56} , {50 , 57} , {56 , 58} , {32 , 58} , {57 , 59} , {49 , 59} , {38 , 60} , {60 , 61} , {35 , 61} , {54 , 61} , {53 , 61} , {54 , 62} , {58 , 62} , {62 , 63} , {40 , 63} , {58 , 63} , {49 , 64} , {63 , 64} , {47 , 64} , {39 , 64} , {45 , 64} , {62 , 65} , {64 , 65} , {54 , 65} , {52 , 66} , {61 , 66} , {60 , 66} , {55 , 67} , {65 , 67} , {45 , 68} , {56 , 68} , {36 , 68} , {67 , 69} , {66 , 69} , {27 , 70} , {60 , 70} , {67 , 70} , {48 , 71} , {70 , 71} , {53 , 71} , {62 , 72} , {72 , 73} , {73 , 74} } ;
    // vector<vector<int> > vctr ={{0 , 0}};
    cout << largestPathValue(str, vctr) << endl;
    return 0;
}
