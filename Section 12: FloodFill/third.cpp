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
        vector<vector<char>> vctr(8, vector<char>(8));
        for(int i = 0;i<8;i++){
            for(int j = 0;j<8;j++){
                cin>>vctr[i][j];
            }
        }
        int flag = 0;
        int cntR = 0, cntC = 0;
        //Check for Row:If answer is present:
        for(int j = 0;j<8;j++){
                cntC = 0;
                for(int i = 0;i<8;i++){
                    if(vctr[i][j] == 'B'){
                        cntC++;
                    }
                }
                if(cntC == 8){
                    cout<<"B"<<endl;
                    break;
                }
            }


            //Check for Column :If answer is present:
        

        if(!flag){

        	for(int i = 0;i<8;i++){
            cntR = 0;
            for(int j = 0;j<8;j++){
                if(vctr[i][j] == 'R'){
                    cntR++;
                }
            }
            if(cntR == 8){
                flag = 1;
                cout<<"R"<<endl;
                break;
            }
        }
            
        }
    }



}