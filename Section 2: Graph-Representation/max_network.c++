#include<bits/stdc++.h>
#define int long long int
#define F first
#define S second
#define pb push_back

using namespace std;


int maximalNetworkRank(int n, vector<vector<int>> roads) {
   
    vector<vector<int>> vctr(n , vector<int> (n, 0));
    vector<int> vctr1(n);
    
    //print:
    cout<<n<<endl;
    for(auto x : roads)
    {
        cout<<x[0]<<" "<<x[1]<<endl;
    }

for(int i=0;i<roads.size();i++)
{
    vctr[roads[i][0]][roads[i][1]]=1;
    vctr[roads[i][1]][roads[i][0]]=1;
}

//Display the graph as adjacency matrix
// for(int i=0;i<vctr.size();i++)
// {
//     for(int j=0;j<vctr[i].size();j++)
//     {
//         cout<<vctr[i][j]<<" ";
//     }
//     cout<<endl;
// }
// cout<<roads.size()<<endl;

for(int i=0;i<roads.size();i++)
    {  
        // cout<<edges[i][0]<<endl;
        // cout<<edges[i][1]<<endl;
        

       vctr1[roads[i][0]]++;
       vctr1[roads[i][1]]++;
    }
    for(auto x : vctr)
    {
        for(auto y: x)
        {
            cout<<y<<"  ";
        }
        cout<<endl;
    }
    

//     for(int i=0;i<vctr1.size();i++)
//     {
//         cout<<vctr1[i]<<" ";
//     }
// cout<<endl;

    int max=-1;
    int max_element=-1;
    int min_element=-1;
    int min=-1;

    for(int k=0;k<n;k++)
    {
        if(max<=vctr1[k])
        {
            min_element=max_element;
            min=max;
            max=vctr1[k];
            max_element=k;
        }
        else if(vctr1[k]>=min && max>=vctr1[k])
        {
            min=vctr1[k];
            min_element=k;
        }
    }
    // cout<<max<<endl;
    // cout<<min<<endl;
    // cout<<"***********"<<endl;
    // cout<<max_element<<endl;
    // cout<<min_element<<endl;
    cout<<"max-min"<<max<<"  "<<min<<endl;
    cout<<max_element<<" "<<min_element<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<i<<"-->"<<vctr1[i]<<endl;
    }
    for(int i=0;i<n;i++)
    {
        if((min == vctr1[i]) and (vctr[i][max_element] != 1) and ( i != max_element))
        {
            cout<<i<<" "<<max_element<<endl;
            cout<<"Hi"<<endl;
            return max+min;
        }
    }
         return max+min-1;

}

int32_t main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin );
	freopen("output.txt" , "w" , stdout);
	#endif
    
    int n;
    cin>>n;
    vector<vector<int>> roads;
    
    while(!cin.eof())
    {
    	int a , b;
    	cin>>a>>b;
    	vector<int> helper;
        helper.push_back(a);
        helper.push_back(b);
        roads.push_back(helper);
    }
    // print:
    // for(a)
    //Call:
    cout<<maximalNetworkRank(n , roads)<<endl;
     return 0;
}
