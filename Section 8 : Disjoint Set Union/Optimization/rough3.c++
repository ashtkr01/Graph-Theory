#include<bits/stdc++.h>
using namespace std;

int minStepsHelper(int target_x, int target_y, int knight_x, int knight_y, int n){
        if(knight_x == target_x && knight_y == target_y){
            return 0;
        }
        
        if(knight_x < 1 || knight_x > n || knight_y<1 || knight_y>n){
            return INT32_MAX;
        }

        int ans = INT32_MAX;
        
        if(knight_x+1 > 0 && knight_x+1 <= n && knight_y+2>0 && knight_y+2<=n){
            ans = min(minStepsHelper(target_x, target_y, knight_x+1, knight_y+2, n), ans);
        }
        if(knight_x-1 > 0 && knight_x-1 <= n && knight_y+2>0 && knight_y+2<=n){
            ans = min(minStepsHelper(target_x, target_y, knight_x-1, knight_y+2, n), ans);
        }
        if(knight_x+2 > 0 && knight_x+2 <= n && knight_y+1>0 && knight_y+1<=n){
            ans = min(minStepsHelper(target_x, target_y, knight_x+2, knight_y+1, n), ans);
        }
        if(knight_x+2 > 0 && knight_x+2 <= n && knight_y-1>0 && knight_y-1<=n){
            ans = min(minStepsHelper(target_x, target_y, knight_x+2, knight_y-1, n), ans);
        }
        if(knight_x-2 > 0 && knight_x-2 <= n && knight_y+1>0 && knight_y+1<=n){
            ans = min(minStepsHelper(target_x, target_y, knight_x-2, knight_y+1, n), ans);
        }
        if(knight_x-2 > 0 && knight_x-2 <= n && knight_y-1>0 && knight_y-1<=n){
            ans = min(minStepsHelper(target_x, target_y, knight_x-2, knight_y-1, n), ans);
        }
        if(knight_x+1 > 0 && knight_x+1 <= n && knight_y-2>0 && knight_y-2<=n){
            ans = min(minStepsHelper(target_x, target_y, knight_x+1, knight_y-2, n), ans);
        }
        if(knight_x-1 > 0 && knight_x-1 <= n && knight_y-2>0 && knight_y-2<=n){
            ans = min(minStepsHelper(target_x, target_y, knight_x-1, knight_y-2, n), ans);
        }

        return 1+ans;
    }
    
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    int knight_x = KnightPos[0];
	    int knight_y = KnightPos[1];
	    
	    int target_x = TargetPos[0];
	    int target_y = TargetPos[1];
        int count = 0;
	    count = minStepsHelper(target_x, target_y, knight_x, knight_y, N);
	    return count;
	}

int main()
{
vector<int> pos = {4,5};
vector<int> target = {1,1};
cout<<minStepToReachTarget(pos , target , 5);
cout<<"hi"<<endl;
return 0;
}