#include<bits/stdc++.h>
using namespace std;
//Helper:
vector<vector<long long int>> floydWarshal(vector<vector<long long int> > graph)
{
    vector<vector<long long int> > dp = graph;
    int v = graph.size();
    int l = 0;

    for(int i=0;i<v;i++)
    {

        for(int j=0;j<v;j++)
        {
            for(int k=0;k<v;k++)
            {
                if(j != l or k != l)
                {
                    dp[j][k] = min(graph[j][k] , graph[j][l] + graph[l][k]);  
                }
            }
        }
        //Update:
        for(int j=0;j<v;j++)
        {
            for(int k=0;k<v;k++)
            {
                graph[j][k] = dp[j][k];
            }
        }
        l++;
    }
    return dp;
}
int main(int argc, char const *argv[])
{
    vector<vector<long long int> > vctr = {{0 , INT_MAX , -2 , INT_MAX} ,
                                           {4 , 0 , 3 , INT_MAX} ,
                                           {INT_MAX , INT_MAX , 0 , 2} ,
                                           {INT_MAX , -1 , INT_MAX , 0} };

    vector<vector<long long int> >  res = floydWarshal(vctr);

    for(auto x : res)
    {
        for(auto y : x)
        {
            cout<<y<<"   ";
        }
        cout<<endl;
    }
    return 0;
}
