#include<bits/stdc++.h>
#define int long long int
#define F first
#define S second
#define pb push_back

using namespace std;


bool gcd(int a , int b){
	if(b == 0){
		if(a == 1){
			return true;
		}
		else{
			return false;
		}
	}
	return gcd(b , a%b);
}

int32_t main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin );
	freopen("output.txt" , "w" , stdout);
	#endif

	int t;
	cin>>t;

	vector<vector<int> > dp(1005 , vector<int> (1005 , -1));
	for(int i =1;i<=1000;i++){
		for(int j=1;j<=1000;j++){
			if(i >= j){
				dp[i][j] = gcd(i , j);
			}
			
		}
	}
	while(t--){
		int n;
		int maxi = -1;
		cin>>n;
		vector<int> vctr2(n , 0);

		for(int i=0;i<n;i++){
			cin>>vctr2[i];
		}



		for(int i=n-1;i>=0;i--){
			for(int j=i;j>=0;j--){
				int a = max(vctr2[j] , vctr2[i]);
				int b = min(vctr2[i] ,vctr2[j]);
				if(dp[a][b] == 1){
					maxi = max(maxi , i + 1 + j + 1);
				}
			}
		}
		cout<<maxi<<endl;
	}

}