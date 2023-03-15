#include<bits/stdc++.h>
using namespace std;
int main(){

    int n=9;
    int arr[n]={1,2,3,4,8,10,10,12,19};
    int key=9;
    int start=0;
    int end=n-1;
    int ans=-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]==key){
            ans=mid;
            break;
        }
        else if(arr[mid]>key){
            ans=mid;
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    cout<<ans<<endl;
}
