#include<bits/stdc++.h>
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
            l[u].push_back(v);
            if(undirected)
            {
                l[v].push_back(u);
            }
        }

        void dfsHelper(int node , bool *visited , int &cnt)
        {
            visited[node] = true;
            cnt++;

            for(auto x : l[node])
            {
                if(!visited[x])
                {
                dfsHelper(x , visited , cnt);
                }   
            }

        }

        int dfs()
        {
            bool *visited = new bool[v]{false};
            int res = 0;
            int res1 = 0;
            int cnt = 0;
            for(int i=0;i<v;i++)
            {
                cnt = 0;
                if(!visited[i])
                {
                    dfsHelper( i , visited , cnt);

                }
                if(cnt != 0)
                {
                    if(cnt >= 2)
                    {
                        res1 += (cnt * (cnt-1))/2;
                    }
                res = cnt + res;
                }
            }
            int answer = (res * (res-1))/2;
            // cout<<answer<<" "<<res1<<endl;
            answer = answer - res1;
            return answer;
        }
};

int count_pairs(int N, vector<pair<int,int> > astronauts){
    graph g(N);

    for(auto x : astronauts)
    {
        g.addEdge(x.first , x.second);
    }
    int result = g.dfs();
    return result;
    
}

//Main:
int main(int argc, char const *argv[])
{
    int n = 5;
    vector<pair<int , int>> vctr ={{0,1},{2,3},{0,4}};

    cout<<count_pairs(n , vctr)<<endl;
    /* code */
    return 0;
}
