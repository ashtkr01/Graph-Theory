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
                        int *initialindegree = new int[v]{0};
                        bool *taken = new bool[v]{false};
                        for(int i=0;i<v;i++)
                        {
                            for(auto nbr : l[i])
                            {
                                indegree[nbr]++;
                                initialindegree[nbr]++;
                            }
                        }
                       
                    //    cout<<"Indegree of 13 :"<<indegree[13]<<endl;
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
                        //Restore the indegree :
                        for(int i=0;i<v;i++)
                        {
                            if(indegree[i] != 0)
                            {
                                indegree[i] = initialindegree[i];
                            }
                        }
                        //  for(int i=0;i<v;i++)
                        // {
                        //     cout<<"Indegree of "<<i<<" "<<indegree[i]<<endl;
                        // }
                        // cout<<"Indegree of 13 :"<<indegree[13]<<endl;
                        
                        // cout<<qu.size()<<endl;
                        // while(!qu.empty())
                        // {
                        //     cout<<qu.front()<<" ";
                        //     result.push_back(qu.front());
                        //     qu.pop();
                        // }
                        // cout<<endl;
                            vector<int> temp;
                        while(!qu.empty())
                        {
                            int ele = qu.front();
                            // cout<<ele<<" -->";
                            result.push_back(ele);
                            qu.pop();
                            for(auto nbr : l[ele])
                            {
                                if(indegree[nbr] > 0 and taken[nbr] == false)
                                {
                                    // cout<<nbr<<" "<<"Hi"<<indegree[nbr];
                                indegree[nbr]--;
                                if(indegree[nbr] == 0)
                                {
                                    taken[nbr] = true;
                                    qu.push(nbr);
                                    // temp.push_back(nbr);
                                }
                                }
                                else if(indegree[nbr] == 0 and taken[nbr] == false)
                                {
                                    // cout<<nbr<<" ";
                                    
                                     taken[nbr] = true;
                                      qu.push(nbr);
                                    // temp.push_back(nbr);
                                }
                            }
                            // cout<<endl;
                            // if(qu.empty() == 1)
                            // {
                            // sort(temp.begin() , temp.end());
                            // for(auto x : temp)
                            // {
                            //     qu.push(x);
                            // }
                            // temp.clear();
                            // }
                        }
                        
                        return result;
                       }

                       void display()
                       {
                        for(int i=0;i<v;i++)
                        {
                            cout<<i<<"-->";
                            for(auto x : l[i])
                            {
                                cout<<x<<" ";
                            }
                            cout<<endl;
                        }
                       }
};

vector<int> findOrder(int numCourses, vector<vector<int>> prerequisites) {
    graph g(numCourses);
    vector<int> empty;
    for(int i=0;i<prerequisites.size();i++)
    {
        g.addEdge(prerequisites[i][1] , prerequisites[i][0]);
    }
    // g.display();
    // cout<<"End :"<<endl;
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
