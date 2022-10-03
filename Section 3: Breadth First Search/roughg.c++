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
	                //Add edge:
	                void addEdge(int u , int v , bool undirected = true)
					{
						l[u].push_back(v);
						if(undirected)
						{
							l[v].push_back(u);
						}
					}
	//Find MinimumDistance :
	void minimumDistance(vector<int> &path , vector<int> &testCase , int &ans)
	{
		unordered_set<int> us;
		for(auto x : path)
		{
			us.insert(x);
		}
		
		//bFS
		if(testCase.size() > 0)
		{
			
			
			
			for(int i=0;i<testCase.size();i++)
			{
				queue<int> qu;
				int answer = INT_MAX;
				
				vector<bool> visit(v , false);
			vector<int> dist(v , 0);
				qu.push(testCase[i]);
				dist[testCase[i]] = 0;
				if(us.find(testCase[i]) != us.end())
					{
						answer = min(answer , dist[testCase[i]]);
					     continue;
					}
			     while (!qu.empty())
		{
			int ele = qu.front();
// 			cout << ele << endl;
			qu.pop();

			// Iterate the neighbours :
			for (auto x : l[ele])
			{
				if (!visit[x])
				{
// 					parent[x] = ele;
					dist[x] = dist[ele] + 1;
					qu.push(x);
					visit[x] = true;
					if(us.find(x) != us.end())
					{
						answer = min(answer , dist[x]);
					}
				}
			}
		}
				
				ans = max(ans , answer);
			}
		}
		
	}
	                 void maximumPath(int node ,vector<bool> &visited , vector<int> &path ,vector<int> &testCase, int &result)
					 {
						 visited[node] = true;
						 path.push_back(node);
						 //Visiting neighbours:
						 for(auto nbr : l[node])
						 {
							 if(!visited[nbr])
							 {
								 maximumPath(nbr , visited , path , testCase , result);
							 }
						 }
						 //Call:
						 int ans = INT_MIN;
						 minimumDistance(path , testCase , ans);
						 result = min(ans , result);
						 path.pop_back();
					 }
	                
	                
};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n , q;
		cin>>n>>q;
		graph g(n+1);
		int temp = n-1;
		while(temp--)
		{
			int a , b;
			cin>>a>>b;
			g.addEdge(a , b);
		}
		int finalanswer = INT_MAX;
		while(q--)
		{
			int size;
			cin>>size;
			vector<int> query(size);
			for(int i=0;i<size;i++)
			{
				cin>>query[i];
			}
// 			for(int i=0;i<size;i++)
// 			{
// 				cout<<query[i];
// 			}
// 			cout<<endl;
			for(int i=1;i<=n;i++)
			{
				int result = INT_MAX;
				vector<bool> visited(n+1 , false);
				vector<int> path;
				g.maximumPath(i , visited , path ,query ,  result);
				finalanswer = min(finalanswer , result);
			}
			cout<<finalanswer<<endl;
		}
	}
}

/*********************************************LeetCode************************************************/
class Solution {
public:
    //find 
  int findParent(int num , vector<int> &parent , int ans)
  {
      if(parent[num] == num)
      {
          parent[num] = ans;
          return ans;
      }
      return parent[num] = findParent(parent[num] , parent , ans);
  } 
    //Helper:
    int findparent(int num , vector<int> &parent)
  {
      if(parent[num] == num)
      {
          return num;
      }
      return parent[num] = findparent(parent[num] , parent);
  }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
       
        //REmove duplicate information for a particular person :
        int x = accounts.size();
        vector<vector<string> > account(x);
        int tt = 0;
        for(int i=0;i<x;i++)
        {
            //Name :
            account[i].push_back(accounts[i][0]);
            unordered_set<string> duplicateEmail;
            for(int j = 1;j<accounts[i].size();j++)
            {
                duplicateEmail.insert(accounts[i][j]);
            }
            for(auto o : duplicateEmail)
            {
                account[i].push_back(o);
            }
            tt++;
        }
        /***************************************************************************/
        /******************Reverse a Vector*****************************************/
        
//         vector<vector<string>> account(x);
//         int tempv = 0;
//         for(int i=x-1;i>=0;i--)
//         {
//             for(int j = 0;j<vctrs[i].size();j++)
//             {
//                 account[tempv].push_back(vctrs[i][j]);
                
//             }
//             tempv++;
//         }
//         // reverse(account.begin() , account.end());
        
        
        
        
        
        
        
        vector<int> parent(1000005 , -1);
        int cnt = -1;
        
        int size = account.size();
        // int x = size;
        unordered_map<int , string> parentMap;
        // vector<int > namesParent;
        for(int i =0;i<size;i++)
        {
            cnt++;
            int paren = cnt;
            parent[cnt] = cnt;
            parentMap[cnt] = account[i][0];
            
            for(int j = 1;j<account[i].size();j++)
            {
                cnt++;
                parent[cnt] = paren;
            }
        }
        
        
        
        int count = -1;
        
        unordered_map<string , int> emailToId;
        vector<int> idToParent;
        for(int i =0;i<size;i++)
        {
            count++;
            int parents = count;
            for(int j = 1;j<account[i].size();j++)
            {
                count++;
                if(emailToId.find(account[i][j]) == emailToId.end())
                {
                    emailToId[account[i][j]] = count;
                    parent[count] = parents;
                }
                else
                {
                    // emailToId[accounts[i][j]] = count;
                    int cn = emailToId[account[i][j]];
                    parent[cn] = findParent(cn , parent , parents);
                    emailToId[accounts[i][j]] = count;
                    // parent[parent[count]] = parents;
                }
            }
        }
        
        int hellp = -1;
        for(int i = 0;i<size;i++)
        {
            for(int j=0;j<account[i].size();j++)
            {
                hellp++;
                parent[hellp] = findparent(hellp , parent);
            }
        }
        
        // int xxx = -1;
        // for(int i =0;i<x;i++)
        // {
        //     for(int j=0;j<account[i].size();j++)
        //     {
        //         xxx++;
        //         cout<<parent[xxx]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        /*******************Till Here it is OK****************************/
        int udx = 0;
        unordered_set<int> us;
        vector<int> vctr;
        int hellps = -1;
        unordered_map<int,int> parentToUdx;
        for(int i = 0;i<x;i++)
        {
            hellps++;
            if(us.find(parent[hellps]) == us.end())
            {
                us.insert(parent[hellps]);
                vctr.push_back(parent[hellps]);
                
                parentToUdx[parent[hellps]] = udx; 
                    udx++;
                
            }
            for(int j=1;j<accounts[i].size();j++)
            {
                hellps++;
            }
        }
        
        vector<vector<string> > result(udx);
        
        int index = 0;
        for(auto x : vctr)
        {
            result[index].push_back(parentMap[x]);
            index++;
        }
        
        int yyy = -1;
        unordered_set<string> temp;
        for(int i =0;i<x;i++)
        {
            yyy++;
            for(int j=1;j<account[i].size();j++)
            {
                yyy++;
                 if(temp.find(account[i][j]) == temp.end())
                {
                result[parentToUdx[parent[yyy]]].push_back(account[i][j]);
                temp.insert(account[i][j]);
                }
            }
            // cout<<endl;
        }
        
        // vector<vector<string>> result;
        //Sort the vector:
        // Sort the vector :
        for(int i = 0;i<result.size();i++)
        {
            sort(result[i].begin() + 1 , result[i].end());
        }
        return result;
    }
};