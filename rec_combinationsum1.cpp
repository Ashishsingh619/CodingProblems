#include<bits/stdc++.h>
using namespace std;

void getCombination(int i,int arr[],vector<int>&v,int k,int n){
    if(i==n){
        if(k==0){
            for(int i=0;i<v.size();i++){
                cout<<v[i]<<" ";
            }
            cout<<endl;
        }
        return ;
    }
    if(arr[i]<=k){
    v.push_back(arr[i]);
    getCombination(i,arr,v,k-arr[i],n);
    v.pop_back();
    }
    getCombination(i+1,arr,v,k,n);
}
int main(){

    int arr[]={2,3,6,7};
    int n=4;
    int k=7;
    vector<int>v;
    getCombination(0,arr,v,k,n);
}
