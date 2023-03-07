#include<bits/stdc++.h>
using namespace std;
//Comparator:
bool comparator(vector<int> &a , vector<int> &b){
    return a[2] <= b[2];
}
//Compare:
bool compare(pair<int , int> &a , pair<int , int> &b){
    return a.first <= b.first;
}
//parent:
int findParent(int a , vector<int> &parent){
    if(parent[a] == a){
        return a;
    }
    //else:
    return parent[a] = findParent(parent[a] , parent);
}
//Union:
void findUnion(int a , int b , vector<int> &parent , vector<int> &sizeSet){
    int s1 = findParent(a , parent);
    int s2 = findParent(b , parent);

    if(sizeSet[s1] > sizeSet[s2]){
        parent[s2] = s1;
        sizeSet[s1] += sizeSet[s2];
    }
    else{
        parent[s1] = s2;
        sizeSet[s2] += sizeSet[s1];
    }
}

vector<int> pathQueries(int n, vector<vector<int>> edges, vector<int>queries)
{
    //Declare a Union set:
    vector<int> parent(n + 1 , 0);
    //Parent:
    for(int i=1;i<=n;i++){
        parent[i] = i;
    }
    vector<int> sizeSet(n + 1 , 1);
    //Query:
    vector<pair<int , int>> query;
    vector<int> answer(queries.size());
    //Store Answer:
    int result = 0;

    for(int i=0;i<queries.size();i++){
        query.push_back({queries[i] , i});
    }

    //Sort the edges:
    sort(edges.begin() , edges.end() , comparator);
    //Sort the query:
    sort(query.begin() , query.end() , compare);

    //int 
    int size = queries.size();
    int i=0;
    int idx = 0;

        unordered_set<int> us;
        //SEt containing parent:
        unordered_set<int> par;

    while(i < size){
        pair<int , int> pr = query[i];
        int value = pr.first;
        int index = pr.second;

        result = 0;
        //set:


        while(idx < edges.size() and edges[idx][2] <= value ){
            int u = edges[idx][0];
            int v = edges[idx][1];
            //insert inset:
            us.insert(u);
            us.insert(v);
            //Union 
            findUnion(u , v , parent , sizeSet);
            idx++;
        }
        //iterate::
        for(auto x : us){
            parent[x] = findParent(x , parent);
        }

        for(auto x : us){
            par.insert(parent[x]);
        }

        for(auto x : par){
            int elements = sizeSet[x];
            if(elements >= 2 and parent[x] == x){
                result += (elements * (elements - 1)) / 2;
            }
        }
        answer[index] = result;
        i++;
    }
    return answer;
}
//Main:
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int edgesSize;
    cin>>edgesSize;
    int querySize;
    cin>>querySize;

    vector<int> query(querySize);

    vector<vector<int>> edges;

    for(int i=0;i<edgesSize;i++){
        int a , b , c;
        cin>>a>>b>>c;
        edges.push_back({a , b , c});
    }

    for(int i=0;i<querySize;i++){
        cin>>query[i];
    }

    //Call:
    vector<int> res = pathQueries(n , edges , query);

    for(auto x : res){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}
