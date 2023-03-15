#include<bits/stdc++.h>
using namespace std;


void getPerm(vector<int>&v,int k,vector<vector<int>>&ans)
{
    if(k>=v.size()){
        ans.push_back(v);
        return;
    }
    set<int>s;
    for(int i=k;i<v.size();i++){
        if(s.find(v[i])!=s.end()){continue;}
        s.insert(v[i]);
        swap(v[i],v[k]);
        getPerm(v,k+1,ans);
        swap(v[i],v[k]);
    }
}
int main()
{

    vector<int>v;
    v.push_back(3);
    v.push_back(1);
    v.push_back(2);
    vector<vector<int>>ans;
     set<int>s;
    getPerm(v,0,ans);

    for(vector<int>i:ans){
        for(int j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
