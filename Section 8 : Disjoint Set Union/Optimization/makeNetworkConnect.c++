#include<bits/stdc++.h>
using namespace std;
// Find By Compression:
int find_set(int a , int *parent)
{
    if(parent[a] == a)
    {
        return parent[a];
    }
    return parent[a] = find_set(parent[a] , parent);
}
//UNion By Compression :
void union_set(int a , int b , int *rank , int *parent , int &cnt)
{
    int s1 = find_set(a , parent);
    int s2 = find_set(b , parent);

    if(s1 != s2)
    {
        if(rank[s1] < rank[s2])
        {
            parent[s1] = s2;
            rank[s2] += rank[s1];
        }
        else{
            parent[s2] = s1;
            rank[s1] += rank[s2];
        }
    }
    else{
        cnt++;
    }
}
int makeConnected(int n, vector<vector<int>> connections) {
    int cnt = 0;
    int result = 0;
    int size = connections.size();
    int *rank = new int[n]{1};
    int *parent = new int[n]{-1};
    for(int i=0;i<n;i++)
    {
        parent[i] = i;
    }
    for(int i=0;i<size;i++)
    {
        union_set(connections[i][0] , connections[i][1] , rank , parent , cnt);
    }

    for(int i=0;i<n;i++)
    {
        if(parent[i] == i)
        {
            result++;
        }
    }
    // cout<<result<<" "<<cnt<<endl;
    if(result - 1 <= cnt)
    {
        return result - 1;
    }
    return -1;

}
//Main:
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    vector<vector<int> > vctr = {{0 , 1} , {0 , 2} , {1 , 2}};
    cout<<"Answer : "<<makeConnected(n , vctr)<<endl;
    return 0;
}
