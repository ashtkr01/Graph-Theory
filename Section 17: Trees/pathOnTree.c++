#include<bits/stdc++.h>
using namespace std;

void dfs(int node , vector<int> &dist , int par , vector<vector<pair<int , int> >> &vctr){

    for(auto x : vctr[node]){
        int nbr = x.first;
        int cost = x.second;
        if(nbr != par){
            dist[nbr] = dist[node] + cost;
            dfs(nbr , dist , node , vctr);
        }
    }
}

vector<int> pathOnTree (int n, int k, vector<vector<int>> edges, vector<vector<int>> queries)
{
    
    vector<int> res;
    vector<vector<pair<int , int>>> vctr(n + 1);
    vector<int> dist(n + 1 , 0);

    int result = 0;
    //Iterate:
    for(auto x : edges){
        int u = x[0];
        int v = x[1];
        int cost = x[2];
        vctr[u].push_back({v , cost});
        vctr[v].push_back({u , cost});
    }
    //Iterate:queries:
    for(auto x : queries){
        int u = x[0];
        int v = x[1];
        result = dist[u] + dist[v];
        res.push_back(result);
    }
    return res;
}