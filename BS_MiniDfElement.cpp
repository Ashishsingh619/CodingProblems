
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=5;
    int arr[n]={1,3,8,10,15};
    int key=8;
    int start=0;
    int end=n-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]==key){
            cout<<arr[mid]<<endl;
            return 0;
        }
        else if(key<arr[mid]){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    if((abs(arr[start]-key))<(abs(arr[end]-key))){
        cout<<arr[start];
        }
        else{
            cout<<arr[end];
        }
}
