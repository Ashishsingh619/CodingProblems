#include<bits/stdc++.h>
using namespace std;

int bs(int arr[],int start,int end,int key){

    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]==key){
            return mid;
        }
        else if(key<arr[mid]){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return -1;
}
int main(){
    int n=8;
    int arr[n]={11,12,15,18,2,5,6,8};
    int key=15;
    int start=0;
    int end=n-1;
    int f_mid=-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        int next=(mid+1)%n;
        int prev=(mid+n-1)%n;
        if(arr[mid]<=arr[prev]&& arr[mid]<=arr[next]){
            f_mid=mid;
            break;
        }
        if(arr[mid]>=arr[start]){
            start=mid;
        }
        else if(arr[mid]<=arr[end]){
            end=mid;
        }

    }
    int left=bs(arr,0,f_mid-1,key);
    int right=bs(arr,f_mid,n-1,key);
    if(left==-1 && right==-1){
        cout<<"Element Not found"<<endl;
    }
    cout<<left<<" "<<right<<endl;

}
