#include<bits/stdc++.h>
using namespace std;

//Find By Compression :
int find_by_compression(int a , int *parent)
{
    if(parent[a] == a)
    {
        return a;
    }
    return parent[a] = find_by_compression(parent[a] , parent);
}
//UNion By Rank:
void union_by_rank(int a , int b , int *rank , int *parent)
{
    int s1 = find_by_compression(a , parent);
    int s2 = find_by_compression(b , parent);

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
}
int main(int argc, char const *argv[])
{
    /* code */
    int n;
    cin>>n;
    int *parent = new int[n + 1]{-1};
    int *rank = new int[n + 1]{1};
    for(int i=1;i<=n;i++)
    {
        parent[i] = i;
    }
    union_by_rank(2,3 , rank , parent);
    union_by_rank(1,2 , rank , parent);
    cout<<"Parent of 3 : "<<find_by_compression(2 , parent)<<endl;
    return 0;
}
