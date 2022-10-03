#include<bits/stdc++.h>
#define int long long int
#define F first
#define S second
#define pb push_back

using namespace std;

class graph{
    int v;
    list<int> *l;
public:
	   graph(int v)
	   {
	   	this->v = v;
	   	l = new list<int>[v];
	   }
	   void addEdge(int u , int v , bool undirected = true)
	   {
	   	// cout<<"Hi"<<endl;
	   	l[u].push_back(v);
	   	if(undirected)
	   	{
	   		l[v].push_back(u);
	   	}
      }
      void display()
      {
      	for(int i=1;i<v;i++)
      	{
      		cout<<i<<" --> ";
      		for(auto x : l[i])
      		{
      			cout<<x<<"--";
      		}
      		cout<<endl;
      	}
      }
      //Helper:
      bool helper(int node , vector<bool> &visited , unordered_map<int,int> &um , int & count)
      {
      	count++;
      	visited[node] = true;
      	um[node] = count;
      	for(auto nbr : l[node])
      	{
      		if((visited[nbr]) and (count - um[nbr] == 2) )
      		{
      			return true;
      		}
      		else if(!visited[nbr])
      		{
      			bool res = helper(nbr , visited , um , count);
      			if(res == true)
      			{
      				return true;
      			}
      		}
      	}
      	count--;
      	visited[node] = false;
      	um.erase(node);
      	return false;

      }
      void traverse()
      {
      	vector<int> result;
      	vector<bool> visited(v,false);
      	unordered_map<int,int> um;      	
      	int count =0;
      	int cnt = 0;
      	int node=1;
      	bool res = false;
      	res = helper(node , visited , um , count);
      	int ans = 0 , ans2 = 0 , ans3 = 0;
      	cout<<count<<endl;
      	//Finding the trio node:
      	for(auto x : um)
      	{
      		if(x.second == count)
      		{
      			ans = x.first;
      			result.push_back(ans);
      		}
      		else if(x.second == count - 1)
      		{
      			ans2 = x.first;
      			result.push_back(ans2);
      		}
      		else if(x.second == count - 2)
      		{
      			ans3 = x.first;
      			result.push_back(ans3);
      		}
      	}
      	// cout<<ans<<" "<<ans2<<" "<<ans3<<endl;
      	for(auto x : result)
      	{
      		for(auto y : l[x])
      		{
      			cnt++;
      		}
      	}
      	cout<<cnt - 6<<endl;
      }
};
int32_t main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin );
	freopen("output.txt" , "w" , stdout);
	#endif
     
     int n;
     cin>>n;
     graph *g = new graph(n+1);
     while (!cin.eof())
     {
     	int u , v;
     	cin>>u>>v;
     	// cout<<"Hi"<<endl;
     	g->addEdge(u , v);
     }
     //Display:
     // cout<<"Hi"<<endl;
     g->display();

     g->traverse();

}