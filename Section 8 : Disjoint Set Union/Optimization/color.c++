#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        int botTurn = 1;
        int cnt = 0;
        while(botTurn <= n)
        {
            int johnTurn = botTurn + 3;
            cnt++;
            botTurn = johnTurn + 2;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
