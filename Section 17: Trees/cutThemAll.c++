#include<bits/stdc++.h>
using namespace std;

int cntNode(int node , int par ,vector<vector<int>> &vctr , int &res){

    int cnt = 0;
    for(auto x : vctr[node]){
        if(x != par){
            int a = cntNode(x , node , vctr , res);
            if(a % 2 == 0){
                res++;
            }
            else{
                cnt += a;
            }
        }
    }
    cnt++;
    return cnt;
}

// int cut(int node , int par , vector<int> &subSize , vector<vector<int>> &vctr , int &res , int n){
//     int cnt = 0;

//     for(auto x : vctr[node]){
//         if(x != par){
//             int a = cut(x , node , subSize , vctr , res , n);
//             if(a % 2 == 0 and ((n - 2) % 2 == 0)){
//                 res++;
//             }
//             else{
//                 cnt += a;
//             }
//         }
//     }
//     cnt++;
//     return cnt;
// }

int solve(int n, vector<vector<int>> edges)
{
    vector<int> subtreeSize(n + 1 , 0);
    vector<vector<int>> vctr(n + 1);
    int res = 0;
    //Base Case:
    if(n % 2 == 1){
        return -1;
    }
    //Insert:
    for(auto x : edges){
        int u = x[0];
        int v = x[1];
        vctr[u].push_back(v);
        vctr[v].push_back(u);
    }
    //Call 1:
    int val = cntNode(1 , 0 , vctr , res);
    res;
}