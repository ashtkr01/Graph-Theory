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
        int a , b , c;
        cin>>a>>b>>c;
        if(a > b){
            if(a > c){
                if(a == (b + c)){
                    cout<<"YES"<<endl;
                }
                else{
                    cout<<"NO"<<endl;
                }
            }
            else{
                if(c == (a + b)){
                    cout<<"YES"<<endl;
                }
                else{
                    cout<<"NO"<<endl;
                }
            }
        }
        else{
            if(b > c){
                if(b == (a + c)){
                    cout<<"YES"<<endl;
                }
                else{
                    cout<<"NO"<<endl;
                }
            }
            else{
                if(c == (a + b)){
                    cout<<"YES"<<endl;
                }
                else{
                    cout<<"NO"<<endl;
                }
            }
        }
    }


}