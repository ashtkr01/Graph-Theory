#include <bits/stdc++.h>
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

      // BFS:
	int bfs_shortest_path(int src, int dest)
	{
		int cnt = 0;
		queue<int> qu;
		bool *visited = new bool[v]{0};
		int *dist = new int[v]{0};
		int *parent = new int[v]{-1};
		qu.push(src);
		visited[src] = true;
		parent[src] = src;
		dist[src] = 0;

		while (!qu.empty())
		{
			int ele = qu.front();
			// cout << ele << endl;
			qu.pop();

			// Iterate the neighbours :
			for (auto x : l[ele])
			{
				if (!visited[x])
				{
					parent[x] = ele;
					dist[x] = dist[ele] + 1;
					qu.push(x);
					visited[x] = true;
				}
			}
		}
		// cout << "Distance between source " << src << " and destination " << dest << " is : " << dist[dest] << endl;
		// cout << "Print the path :" << endl;
		// int curr = dest;
		// cout << dest << "<--";
		// while (curr != src)
		// {
		// 	cout << parent[curr] << "<--";
		// 	curr = parent[curr];
		// }
        return dist[dest];
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

//   return the similar type of words:
vector<string> similarWord(string word, unordered_set<string> us)
{
    int length = word.length();
    vector<string> vctr;

    int idx = 0;

    while (length--)
    {
        string str = word;
        char character = word[idx];
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            if (ch != character)
            {
                str[idx] = ch;
                if (us.find(str) != us.end())
                {
                    vctr.push_back(str);
                }
            }

        }
            idx++;
    }
    return vctr;
}

int ladderLength(string beginWord, string endWord, vector<string> wordList)
{
    int length = wordList.size();
    graph g(length +1);
    unordered_map<string , int> um;
    unordered_set<string> us;
    um[beginWord] = 0;
    us.insert(beginWord);
    int idx = 0;
    for (auto x : wordList)
    {
        us.insert(x);
        um[x] = ++idx;
        // idx++;
    }
    
    for(auto x : us)
    {
        vector<string> res;
        res = similarWord(x , us);

        for(auto y : res)
        {
            g.addEdge(um[x] , um[y]);
        }


    }
    //Display:
    // g.display();
    //
    int result = g.bfs_shortest_path(um[beginWord] , um[endWord]);
    if(result == 0)
    {
        return 0;
    }
    return result + 1;
}

//Main:
int main(int argc, char const *argv[])
{
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    cout<<ladderLength(beginWord , endWord , wordList)<<endl;
    return 0;
}
