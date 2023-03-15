#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=5;
    int arr[n]={5,10,30,20,40};
    int start=0;
    int end=n-1;
    int key=20;
    while(start<=end){
    int mid=start+(end-start)/2;
    if(arr[mid]==key){
        cout<<mid;
        break;
    }
    if(mid-1>=start && arr[mid-1]==key){
        cout<<mid-1<<endl;
        break;
    }
    if(mid+1<=end && arr[mid+1]==key){
        cout<<mid+1<<endl;
        break;
    }
    if(key<arr[mid]){
        end=mid-2;
    }
    else{
        start=mid+2;
    }
    }
}
