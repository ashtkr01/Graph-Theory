#include<bits/stdc++.h>
#define int long long int
#define F first
#define S second
#define pb push_back

using namespace std;

int32_t main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin );
	freopen("output.txt" , "w" , stdout);
	#endif

	int t;
    cin>>t;
    while(t--){
        int n;
        int flag = 0;
        unordered_set<int> us;
        cin>>n;
        vector<int> vctr(n , 0);
        for(int i =0;i<n;i++){
            cin>>vctr[i];
        }
        for(int i=0;i<n;i++){
            if(us.find(vctr[i]) != us.end()){
                flag = 1;
                cout<<"NO"<<endl;
                break;
            }
            us.insert(vctr[i]);
        }

        if(flag == 0){
            cout<<"YES"<<endl;
        }


    }


}