#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;
vector<int> l[N];
int dist[N] , ans[N];
//Case 1:
void dfs(int node , int par){

    for(auto x : l[node]){
        if(x != par){
            dfs(x , node);
            dist[node] = max(dist[node] , dist[x] + 1);
        }
    }
}

//Case 2:
void helper(int curr , int par , int dis_par , vector<int> &answer){
    
    int firstMax = -1;
    int secondMax = -1;
    //Caluculate new despair:
    for(auto x : l[curr]){
        if(x != par){
            if(dist[x] >= firstMax){
            secondMax = firstMax;
            firstMax = dist[x];
            }
        else{
            if(dist[x] > secondMax){
                secondMax = dist[x];
            }
        }
        }
    }
    for(auto x : l[curr]){
        if(x != par){
            int new_dispar = dis_par;
            if(dist[x] != firstMax){
                new_dispar = max(new_dispar , firstMax);
            }
            else{
                new_dispar = max(new_dispar , secondMax);
            }
            helper(x , curr , 1 + new_dispar , answer);
            answer[curr - 1] = max(answer[curr - 1] , 1 + dist[x]);
        }
    }
    answer[curr - 1] = max(answer[curr - 1] , 1 + dis_par);
}

vector<int> treeDistances(int n, vector<vector<int>>edges)
{
    vector<int> answer(n , 0);
    for(auto x : edges){
        int u = x[0];
        int v = x[1];
        l[u].push_back(v);
        l[v].push_back(u);
    }
    //Call:
    dfs(1 , 0);
    //Helper:
    helper(1 , 0 , -1 , answer);
    //Return:
    return answer;
}

//Main:
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    vector<vector<int>> vctr(n - 1 , vector<int> (2 , 0));
    for(int i=0;i<n-1;i++){
        cin>>vctr[i][0]>>vctr[i][1];
    }
    vector<int> res = treeDistances(n , vctr);
    //Print:
    for(auto x : res){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}
