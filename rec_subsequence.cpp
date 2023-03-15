#include<bits/stdc++.h>
using namespace std;

void printSub(int i,int arr[],vector<int>&ans,int n){
    if(i==n){
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
        }
        cout<<endl;
        return;
    }
    ans.push_back(arr[i]);
    printSub(i+1,arr,ans,n);
    ans.pop_back();
    printSub(i+1,arr,ans,n);
}

int main(){
    int arr[]={3,2,5};
    int n=3;
    vector<int>ans;
    printSub(0,arr,ans,n);
}
