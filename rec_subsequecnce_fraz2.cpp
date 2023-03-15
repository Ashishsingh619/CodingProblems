#include<bits/stdc++.h>
using namespace std;


void getSub(vector<int>&v,int i,vector<int>&store,vector<vector<int>>&fin)
{
    if(i>=v.size())
    {
        fin.push_back(store);
        return ;
    }

    store.push_back(v[i]);
    getSub(v,i+1,store,fin);
    store.pop_back();
    getSub(v,i+1,store,fin);



}

vector<vector<int>> getSub2(vector<int>&v,int i,int target){
    if(i>=v.size()){
        return {{}};
    }

    vector<vector<int>>smallProb=getSub2(v,i+1,target-v[i]);
    vector<vector<int>>smallans;
    for(auto k:smallProb){
        smallans.push_back(k);
    }
    for(auto k:smallProb){
        vector<int>temp;
        int sum=0;
        sum+=v[i];
        temp.push_back(v[i]);
        for(int j:k){
            temp.push_back(j);
            sum+=v[i];
        }
        if(sum==target)
        smallans.push_back(temp);
    }
    return smallans;
}

int main()
{
    vector<int>v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    int k=2;
    vector<vector<int>>fin;
    vector<int>store;
    getSub(v,0,store,fin);
    for(auto i:fin){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
