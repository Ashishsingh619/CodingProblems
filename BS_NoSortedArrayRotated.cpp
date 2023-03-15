#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=8;
    int arr[n]={11,12,15,18,2,5,6,8};
    int start=0;
    int end=n-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        int next=(mid+1)%n;
        int prev=(mid+n-1)%n;
        if(arr[mid]<=arr[prev] && arr[mid]<=arr[next]){
            cout<<mid<<endl;
            return 0;
        }
        if(arr[mid]>=arr[start]){
            start=mid;
        }
        else if(arr[mid]<=arr[end]){
            end=mid;
        }
    }

}
