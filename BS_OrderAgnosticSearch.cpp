#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=5;
    int arr[n]={1,2,3,4,5};
    //int arr[n]={5,4,3,2,1};
    int key=2;
    int start=0;
    int end=n-1;
    int check=true;
    if(arr[start]>arr[end]){
        check=false;
    }
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]==key){
            cout<<mid<<endl;
            return 0;
        }
        else if(key<arr[mid]){
            if(check){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        else{
            if(check){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
    }
    cout<<"Element Not found"<<endl;
    return 0;
}
