#include<bits/stdc++.h>
using namespace std;

int dfs(int node , int par , vector<int> &res , vector<vector<int>> &vctr){
    int cnt = 0;
    for(auto x : vctr[node]){
        if(x != par){
            int a = dfs(x , node , res , vctr);
            cnt += a;
        }
    }
    res[node] = 1 + cnt;
    return res[node];
}

vector<int> subtreeProblem (int n, vector<vector<int>> edges, vector<int> queries)
{
    vector<int> res(n + 1 , 0);
    vector<int> result;
    //Retur:
    vector<vector<int>> vctr(n + 1);

    for(auto x : edges){
        int u = x[0];
        int v = x[1];
        vctr[u].push_back(v);
        vctr[v].push_back(u);
    }
    int val = dfs(1 , 0 , res , vctr);
    //Itereate:
    for(auto x : queries){
        int ans = res[x];
        result.push_back(ans);
    }
    //Return:
    return result;
}