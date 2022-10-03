#include <bits/stdc++.h>
using namespace std;

void reverse(vector<int> &arr,int i,int j){
    int mid = ceil((i+j)/2);
    int temp =j;
    for (int k = i; k < mid; k++)
    {
        /* code */
        int temp2=arr[temp];
        arr[temp]=arr[k];
        arr[k]=temp2;
        temp--;

    }
    
}

vector<int> performOperations(vector<int> arr ,  vector<vector<int> > operation)
{
    for(auto x : operation)
    {
        int a = x[0];
        int b = x[1];
        reverse(arr , a , b);
    }
    return arr;
}
int main(int argc, char const *argv[])
{
    /* code */
    vector<int> vctr ={9,8,7,6,5,4,3,2,1,0};
    vector<vector<int > > temp= {{0 , 9} , { 4 , 5} , {3 , 6} , { 2 , 7} , {1 , 8} , {0 , 9}};

    vctr = performOperations(vctr , temp );

    for(auto x : vctr)
    {
        cout<<x<<" ";
    }
    cout<<endl;

    return 0;
}
