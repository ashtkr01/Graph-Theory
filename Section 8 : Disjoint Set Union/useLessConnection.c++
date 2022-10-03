#include <bits/stdc++.h>
using namespace std;

// Find function in c++
int find_set(int a, int *parent)
{
    if (parent[a] == a)
    {
        return a;
    }
    return find_set(parent[a], parent);
}
// UNion Function:
bool union_set(int a, int b, int *parent)
{
    int s1 = find_set(a, parent);
    int s2 = find_set(b, parent);

    if (s1 != s2)
    {
        parent[s2] = s1;
        return false;
    }
    else
    {
        return true;
    }
}

vector<int> findUselessConnection(vector<vector<int>> edges)
{
    vector<int> result;
    int res = INT_MIN;
    for (auto x : edges)
    {
        res = max(res, max(x[0], x[1]));
    }
    int *parent = new int[res + 1]{-1};
    for (int i = 1; i <= res; i++)
    {
        parent[i] = i;
    }
    for (auto x : edges)
    {
        bool res = union_set(x[0], x[1], parent);
        if (res == true)
        {
            result = {x[0], x[1]};
            return result;
        }
    }
    return result;
}
//Main:
int main(int argc, char const *argv[])
{
    vector<vector<int> > vctr = {{1 , 2} , {2 , 3} , {3 , 4} , {4 , 1}};
    vector<int> result = findUselessConnection(vctr);
    cout<<result[0]<<" "<<result[1]<<endl;
    return 0;
}
