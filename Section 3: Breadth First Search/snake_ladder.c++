#include<bits/stdc++.h>
// // #define int long long int
// #define F first
// #define S second
// #define pb push_back

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
	   void addEdge(int u , int v , bool undirected = false)
	   {
	   	// cout<<"Hi"<<endl;
	   	l[u].push_back(v);
	   	if(undirected)
	   	{
	   		l[v].push_back(u);
	   	}
      }

      int bfsTraversal( int n , int source)
      {
      	bool *visited = new bool[n+1];
      	int *dist = new int[n+1];
		for(int i=1;i<=n;i++)
		{
			visited[i] = false;
			dist[i] = -1;
		}
      	queue<int> qu;
      	visited[1] = true;
      	dist[1] = 0;
      	qu.push(1);

      	while(!qu.empty())
      	{
      		int ele = qu.front();
      		qu.pop();
      		for(auto x : l[ele])
      		{
      			if(!visited[x])
      			{
      				qu.push(x);
      				visited[x] = true;
      				dist[x] = dist[ele] + 1;
      			}
      		}
      	}
      	return dist[n];
		// cout<<dist[n]<<endl;


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
};




int min_dice_throws(int n,vector<pair<int,int> > snakes, vector<pair<int,int> > ladders){
    graph *g = new graph(n+1);
    //For dic
	vector<int> board(n+1 , 0);

	for(auto x : ladders)
	{
		board[x.first] = x.second - x.first;
	}

	for(auto x : snakes)
	{
		board[x.first] = x.second - x.first;
	}
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=6;j++)
    	{
			if(i+j <= n)
			{
				g->addEdge(i , i + j + board[i+j]);
			}
            
    	}
    }
    
	int res = g->bfsTraversal(n, 1);
	return res;
	// return 0;

}

int main()
{
	int n;
	cin>>n;

	vector<pair<int,int>> ladders = {{2,15},{5,7},{9,27},{18,29},{25,35}};
	vector<pair<int , int>> snakes = {{17,4},{20,6},{34,12},{24,16},{32,30}};

	cout<<min_dice_throws(n , snakes , ladders)<<endl;
    

	return 0;

}