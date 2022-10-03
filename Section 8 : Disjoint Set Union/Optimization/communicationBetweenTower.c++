#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int *row = new int[m]{0};
    int *col = new int[n]{0};
    int cnt = 0;
    int res = INT_MIN;

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(matrix[i][j] == 1)
            {
                if(row[i] == 0 and col[j] == 0)
                {
                    row[i] = ++cnt;
                    col[j] = cnt;
                    matrix[i][j] = cnt;
                }
                else if(col[j] == 0)
                {
                    col[j] = cnt;
                    matrix[i][j] = cnt;
                }
                else if(row[i] != 0 or col[j] != 0 )
                {
                    matrix[i][j] = cnt;
                }
                //Check for next row:
                if(i + 1 < m)
                {
                    if(matrix[i+1][j] == 1)
                    {
                        row[i + 1] = cnt;
                    }
                }
            }
        }
    }

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
                res = max(res , matrix[i][j]);
        }
    }
    return res;
}
//Main:
int main(int argc, char const *argv[])
{
    int m , n;
    cin>>m>>n;
    vector<vector<int> > matrix(m , vector<int> (n , 0));
    for(int i =0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>matrix[i][j];
        }
    }
    int res = solve(matrix);
    cout<<"Answer : "<<res<<endl;
    for(int i =0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
