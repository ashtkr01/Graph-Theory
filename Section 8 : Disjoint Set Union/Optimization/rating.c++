#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin>>t;

    int idx = 1;

    while(t--)
    {
        int n;
        cin>>n;

        vector<int> vctr(n , 0);
        vector<int> parent(n , 0);
        vector<int> res(n , 0);
        unordered_map<int,int> um;
        set<int> st;
        for(int i=0;i<n;i++)
        {
            cin>>vctr[i];
            parent[i] = vctr[i];
            st.insert(vctr[i]);
            um[vctr[i]]++;
        }
        //Sort :
        sort(parent.begin() , parent.end() , greater<int>());

        for(int i=0;i<n;i++)
        {
            um[vctr[i]]--;
            int flag = 0;

            int j = 0;

            while(2*vctr[i] < parent[j])
            {
                j++;
            }

            if(j < n)
            {
                if(parent[j] == vctr[i] and um[vctr[i]] == 0)
                {
                    j++;
                }
                if(j < n)
                {
                    res[i] = parent[j];
                    flag = 1;
                }
            }
            if(flag == 0)
            {
                res[i] = -1;
            }

            
            // for(int o=0;o<n;o++)
            // {
            //     if(um[parent[o]] > 0 and parent[o] <= 2*vctr[i] )
            //     {
            //         flag = 1;
            //         res[i] = parent[o];
            //         break;
            //     }
            // }


            // for(auto x : st)
            // {
            //     if(um[x] > 0 and x <= 2*vctr[i] )
            //     {
            //         flag = 1;
            //         res[i] = x;
            //     }
            // }
            // if(flag == 0)
            // {
            //     res[i] = -1;
            // }
            um[vctr[i]]++;
        }
        //Print:
        cout<<"Case #"<<idx<<": ";
        for(auto x : res)
        {
          cout<<x<<" ";
        }
        idx++;
        cout<<endl;
    }
    return 0;
}
