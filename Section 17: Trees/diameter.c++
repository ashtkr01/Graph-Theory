#include<bits/stdc++.h>
using namespace std;

pair<int , int> helper(int node , int par , vector<vector<int>> &vctr){
    int maximum = 0;
    int firstMax = -1;
    int secondMax = -1;

    for(auto x : vctr[node]){
        if(x != par){
            pair<int , int> pr = helper(x , node , vctr);
            int a = pr.first;
            int b = pr.second;

            maximum = max(maximum , b);

            if(a >= firstMax){
                secondMax = firstMax;
                firstMax = a;
            }
            else{
                if(a > secondMax){
                    secondMax = a;
                }
            }
        }
    }
    int a = 1 + firstMax;
    int b = max(maximum , 2 + firstMax + secondMax);
    return {a , b};
}

int treeDiameter(vector<vector<int>> edges)
{
    int n = edges.size() + 2;

    vector<vector<int>> vctr(n);
    //Pair:
    pair<int , int> pr;
    for(auto x : edges){
        int u = x[0];
        int v = x[1];
        vctr[u].push_back(v);
        vctr[v].push_back(u);
    }

    pr = helper(1 , 0 , vctr);
    int a = pr.first;
    int b = pr.second;

    return max(a , b);
}