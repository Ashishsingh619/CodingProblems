#include<bits/stdc++.h>
using namespace std;

void getSub(int i,int arr[],int k,vector<int>&ans,int s,int n){

    if(i==n){
        if(s==k){
            for(int i=0;i<ans.size();i++){
                cout<<ans[i]<<" ";
            }
            cout<<endl;
        }
        return;
    }

    ans.push_back(arr[i]);
    getSub(i+1,arr,k,ans,s+arr[i],n);
    ans.pop_back();
    getSub(i+1,arr,k,ans,s,n);

}

bool getSub1(int i,int arr[],int k,vector<int>&ans,int s,int n){

    if(i==n){
        if(s==k){
            for(int i=0;i<ans.size();i++){
                cout<<ans[i]<<" ";
            }
            cout<<endl;
            return true;
        }
        return false;
    }

    ans.push_back(arr[i]);
    if(getSub1(i+1,arr,k,ans,s+arr[i],n)){
        return true;
    }
    ans.pop_back();
    if(getSub1(i+1,arr,k,ans,s,n)){
        return true;
    }
    return false;
}

int getSubCount(int i,int arr[],int k,int s,int n){

    if(i==n){
        if(s==k){
            return 1;
        }
        return 0;
    }

    int left=getSubCount(i+1,arr,k,s+arr[i],n);
    //ans.pop_back();
    int right=getSubCount(i+1,arr,k,s,n);

    return left+right;
}

int main(){

    int arr[]={1,2,1};
    int k=2;
    int n=3;
    vector<int>ans;
    //getSub(0,arr,k,ans,0,n);
   // getSub1(0,arr,k,ans,0,n);
    cout<<getSubCount(0,arr,k,0,n);
}
