#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=7;
    int arr[n]={2,4,10,10,10,18,20};
    int key=10;
    int start=0;
    int end=n-1;
    int first=-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]==key){
            first=mid;
            end=mid-1;
        }
        else if(key<arr[mid]){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    start=0;
    end=n-1;
    int second=-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]==key){
            second=mid;
            start=mid+1;
        }
        else if(key<arr[mid]){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    cout<<second-first+1<<endl;

}
