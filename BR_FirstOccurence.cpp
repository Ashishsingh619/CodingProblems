#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=5;
    int arr[n]={1,2,2,3,4};
    int key=2;
    int start=0;
    int end=n-1;
    int ans=-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]==key){
            ans=mid;
            end=mid-1;
        }
        else if(key<arr[mid]){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    cout<<ans<<endl;
}
