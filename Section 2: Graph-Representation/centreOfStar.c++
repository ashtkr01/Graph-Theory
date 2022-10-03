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
      int helper()
      {
      	int count =0;
      	for(int i=1;i<v;i++)
      	{
      		count = 0;
      		for(auto x : l[i])
      		{
      			count++;
      		}
      		if(count == v-2)
      		{
      			return i;
      		}
      	}
      	return -1;
      }
};

//Function:
int findCenter(vector<vector<int>>edges)
{
    unordered_set<int> us;
    for(auto x : edges)
    {
    	us.insert(x[0]);
    	us.insert(x[1]);
    	// cout<<x[0]<<" "<<x[1]<<endl;
    }
    int v = us.size();
    v=v+1;
    // cout<<v<<endl;
    //Initialization of graph
    graph g(v);
    //Add Edge:
    for(auto x : edges)
    {
    	int a = x[0];
    	int b = x[1];
    	g.addEdge(a,b);
    }
    g.display();
    return g.helper();
    
}


int32_t main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin );
	freopen("output.txt" , "w" , stdout);
	#endif
     
     // int n;
     // cin>>n;
     // graph *g = new graph(n);
     // while (!cin.eof())
     // {
     // 	int u , v;
     // 	cin>>u>>v;
     // 	// cout<<"Hi"<<endl;
     // 	g->addEdge(u , v);
     // }
     // //Display:
     // // cout<<"Hi"<<endl;
     // g->display();
     // // cout<<"Hi"<<endl;
	vector<vector<int>> vctr = {{1,2},{2,3},{4,2}};
	cout<<findCenter(vctr)<<endl;

}