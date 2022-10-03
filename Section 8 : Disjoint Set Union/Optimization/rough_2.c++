//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class graph
{
    int v; 
    list<int> *l;
                 public :
                         graph(int v)
                         {
                            this->v = v;
                            l = new list<int>[v];
                         }
                         //AddEDge:
                         void addEdge(int u , int v , bool undirected = true)
                         {
                            l[u].push_back(v);
                            if(undirected)
                            {
                                l[v].push_back(u);
                            }
                         }
                         //bfs:
                         int bfs(int source , int dest)
                         {
                            bool *visited = new bool[v]{false};
                            int *dist = new int[v]{-1};

                            queue<int> qu;
                            qu.push(source);
                            visited[source] = true;
                            dist[source] = 0;

                            while(!qu.empty())
                            {
                                int ele = qu.front();
                                qu.pop();

                                for(auto nbr : l[ele])
                                {
                                    if(!visited[nbr])
                                    {
                                        visited[nbr] = true;
                                        dist[nbr] = dist[ele] + 1;
                                        qu.push(nbr);
                                    }
                                }
                            }
                            return dist[dest];

                         }

};

// } Driver Code Ends
class Solution {
public:
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	    // Code here
        int size = N*N;
        graph g(size + 1);

        int source = (KnightPos[0] * N) + KnightPos[1];
        int dest = (TargetPos[0] * N) + TargetPos[1];

        vector<int> x = {-2 , -2 , -1 , 1 , 2 , 2 , 1 , -1};
        vector<int> y = {-1 , 1 , 2 , 2 , 1 , -1 , -2 , - 2 };

        //Build edges:
        for(int i=1;i<=N;i++)
        {
            for(int j = 1;j<=N;j++)
            {
                for(int k = 0;k<8;k++)
                {
                    int o = i + x[k];
                    int p = j + y[k];
                    if( o >= 1 and o <= N and p >= 1 and p <= N)
                    {
                        int uu = (i*N) + j;
                        int vv = (o*N) + p;
                        g.addEdge(uu , vv);
                    }
                }
            }
        }
        int result = g.bfs(source , dest);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends