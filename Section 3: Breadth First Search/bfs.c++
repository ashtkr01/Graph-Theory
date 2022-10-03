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
      	for(int i=0;i<v;i++)
      	{
      		cout<<i<<" --> ";
      		for(auto x : l[i])
      		{
      			cout<<x<<"--";
      		}
      		cout<<endl;
      	}
      }
      //BFS:
      void bfs()
      {
      	queue<int> qu;
      	bool *visited = new bool[v]{0};
      	qu.push(0);
      	visited[0] = true;

      	while(!qu.empty())
      	{
      		int ele = qu.front();
      		cout<<ele<<endl;
      		qu.pop();
      		//Iterate the neighbours :
      		for(auto x : l[ele])
      		{
      			if(!visited[x])
      			{
      				qu.push(x);
      				visited[x] = true;
      			}
      		}
      	}
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
     graph *g = new graph(n);
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
     //Bfs Traversal:
     g->bfs();
     // cout<<"Hi"<<endl;

}