#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> getSubsets(int arr[],int i,int n)
{
    if(i>=n)
    {
        return {{}};
    }
    vector<vector<int>> smallProb=getSubsets(arr,i+1,n);
    vector<vector<int>>subans;
    for(vector<int> j:smallProb)
    {
        subans.push_back(j);
    }
    for(vector<int> x:smallProb)
    {
        vector<int> temp;
        temp.push_back(arr[i]);
        for(int m:x)
        {
            temp.push_back(m);
            //cout<<k;
        }
        //cout<<endl;
        subans.push_back(temp);
    }
    return subans;
}
vector<vector<int>> pwset(int arr[],int n)
{
    //Write your code here
    return getSubsets(arr,0,n);
}
int main()
{
    int arr[]= {3,2,1};
    vector<vector<int>>ans=pwset(arr,3);
    cout<<ans.size();
    for(vector<int> i:ans)
    {
        //<<i.size()<<endl;
      for(int j:i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }

}


