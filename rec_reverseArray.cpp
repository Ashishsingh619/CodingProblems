#include<bits/stdc++.h>
using namespace std;

void f(int l,int r,int arr[]){
    if(l>=r){
        return;
    }
    swap(arr[l],arr[r]);
    f(l+1,r-1,arr);
}
void f2(int i,int n,int arr[]){
    if(i>n/2){
        return;
    }
    swap(arr[i],arr[n-i-1]);
    f2(i+1,n,arr);
}
int main(){

    int arr[5]={1,2,3,4,5};
    int n=5;
    //f(0,n-1,arr);
    f2(0,n,arr);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

