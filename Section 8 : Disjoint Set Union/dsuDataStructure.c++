#include<bits/stdc++.h>
using namespace std;
//Find :
int find(int a , int *parent)
{
    if(parent[a] == a)
    {
        return a;
    }
    return find(parent[a] , parent);
}

//UNion:
void unionFun(int a , int b , int *parent)
{
    int s1 = find(a , parent);
    int s2 = find(b , parent);
    if(s1 != s2)
    {
        parent[s2] = s1;
    }
}
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int *parent = new int[n+1]{0};
    for(int i =1;i<=n;i++)
    {
        parent[i] = i;
    }
    unionFun(2 , 3 , parent);
    unionFun(3 , 4 , parent);
    int a = find(2 , parent);
    int b = find(4 , parent);
    cout<<a<<"  "<<b<<endl;

    return 0;
}
