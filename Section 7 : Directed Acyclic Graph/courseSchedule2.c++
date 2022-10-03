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

                       void addEdge(int u , int  v , bool undirected = false)
                       {
                        l[u].push_back(v);
                        if(undirected)
                        {
                            l[v].push_back(u);
                        }
                       }
                       vector<int> tapologicalSort()
                       {
                        queue<int> qu;
                        vector<int> result;
                        int *indegree = new int[v]{0};
                        bool *taken = new bool[v]{false};
                        for(int i=0;i<v;i++)
                        {
                            for(auto nbr : l[i])
                            {
                                indegree[nbr]++;
                            }
                        }
                        
                        while(qu.size() != v)
                        {
                        for(int i =0;i<v;i++)
                        {
                            if(indegree[i] == 0)
                            {
                                if(taken[i] == false)
                                {
                                    taken[i] = true;
                                qu.push(i);
                                for(auto nbr : l[i])
                                {
                                    indegree[nbr]--;
                                }
                                }
                            }
                        }
                        }
                        // cout<<qu.size()<<endl;
                        while(!qu.empty())
                        {
                            // cout<<qu.front()<<" ";
                            result.push_back(qu.front());
                            qu.pop();
                        }
                        // cout<<endl;
                        // while(!qu.empty())
                        // {
                        //     int ele = qu.front();
                        //     result.push_back(ele);
                        //     qu.pop();
                        //     vector<int> temp;
                        //     for(auto nbr : l[ele])
                        //     {
                        //         if(indegree[nbr] > 0 and taken[nbr] == false)
                        //         {
                        //         indegree[nbr]--;
                        //         if(indegree[nbr] == 0)
                        //         {
                        //             taken[nbr] = true;
                        //             temp.push_back(nbr);
                        //         }
                        //         }
                        //         if(indegree[nbr] == 0 and taken[nbr] == false)
                        //         {
                        //              taken[nbr] = true;
                        //             temp.push_back(nbr);
                        //         }
                        //     }
                        //     sort(temp.begin() , temp.end());
                        //     for(auto x : temp)
                        //     {
                        //         qu.push(x);
                        //     }
                        // }
                        
                        return result;
                       }
};

vector<int> findOrder(int numCourses, vector<vector<int>> prerequisites) {
    graph g(numCourses);
    vector<int> empty;
    for(int i=0;i<prerequisites.size();i++)
    {
       
        g.addEdge(prerequisites[i][1] , prerequisites[i][0]);
    }
    vector<int> result =  g.tapologicalSort();
    if(result.size() == numCourses)
    {
        return result;
    }
    // cout<<"Hi"<<endl;
    return empty;
}
//Main:
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    // vector<vector<int> > vctr = {{1 , 0} , {2 , 0} , {3 , 2} , {3 , 1}};
    vector<vector<int> > vctr = {{3 , 1} , {13 , 3} , {9 , 14} , {6, 2} , {13 , 11} , {1 , 9} , {10 , 8}};
    vector<int> result = findOrder(n , vctr);
    for(auto x : result)
    {
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}
