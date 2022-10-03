#include<bits/stdc++.h>
using namespace std;
// Helper Function:
 void helper(vector<vector<int>> &grid ,vector<vector<bool>> &visited , int i , int  j , int numOfIsland , vector<int> &track)
{
	int m = grid.size();
	int n = grid[0].size();
	visited[i][j] = true;
	track[numOfIsland] += 1;
	grid[i][j] = numOfIsland;

	vector<int> disti = {1 , -1 , 0 ,0 };
	vector<int> distj = {0 , 0 , 1 , -1};

	for(int k=0;k<4;k++)
	{
		int ii = i + disti[k];
		int jj = j + distj[k];

		if(ii >=0 and ii<m and jj>=0 and jj<n and grid[ii][jj] == 1 and visited[ii][jj] == false)
		{
			helper(grid , visited , ii , jj , numOfIsland , track);
		} 
	}
}
//Helper:
int largestIsland(vector<vector<int>> &grid) {
	int m = grid.size();
	int n = grid[0].size();
	vector<int> track(m*n , 0);

vector<vector<bool> > visited(m, vector<bool> (n , false));
int numOfIsland = 0;

for(int i=0;i<m;i++)
{
	for(int j=0;j<n;j++)
	{
		if(grid[i][j] == 1 and visited[i][j] == false)
		{
			numOfIsland++;
			helper(grid , visited , i , j ,  numOfIsland , track);
		}
	}
}
//Print:
// for(int i=0;i<m;i++)
// {
// 	for(int j=0;j<n;j++)
// 	{
// 		cout<<grid[i][j]<<" ";
// 	}
// 	cout<<endl;
// }
// //Print:
int maxOne = 0;
for(int i=1;i<=numOfIsland;i++)
{
	maxOne = max(maxOne , track[i]);
}
// cout<<endl;
   //Call:


int result = maxOne;
// int flag = 0;
for(int i=0;i<m;i++)
{
	for(int j=0;j<n;j++)
	{
		if(grid[i][j] == 0)
		{
			unordered_set<int> st;
			vector<int> disti = {1 , -1 , 0 ,0 };
	        vector<int> distj = {0 , 0 , 1 , -1};

	for(int k=0;k<4;k++)
	{
		int ii = i + disti[k];
		int jj = j + distj[k];

		if(ii >=0 and ii<m and jj>=0 and jj<n and grid[ii][jj] != 0)
		{
			st.insert(grid[ii][jj]);
		} 
	}
	int temp = 0;
	for(auto c : st)
	{
		temp += track[c];

		}
		result = max(result , 1 + temp);
	}
	} 
}
return result;
}
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin );
	freopen("output.txt" , "w" , stdout);
	#endif
	int m , n;
	cin>>m>>n;

	vector<vector<int> > vctr(m , vector<int> (n , 0));

	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>vctr[i][j];
		}
	}
	//Call:
	int answer = largestIsland(vctr);
	cout<<answer<<endl;
	return 0;
}