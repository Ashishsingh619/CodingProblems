#include<bits/stdc++.h>
using namespace std;

void getSube(vector<int>&v,int i,vector<int>&store,vector<vector<int>>&ans)
{
    if(i>=v.size()){

        ans.push_back(store);
        return;
    }
   // while(i+1<v.size() && v[i]==v[i+1]){i++;}
    store.push_back(v[i]);
    getSube(v,i+1,store,ans);
    store.pop_back();
    while(i+1<v.size() && v[i]==v[i+1]){i++;}
    getSube(v,i+1,store,ans);

}
int main()
{

    vector<int>v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    vector<vector<int>>ans;
    vector<int>store;
    getSube(v,0,store,ans);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
