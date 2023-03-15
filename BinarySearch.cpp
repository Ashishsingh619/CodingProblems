#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=10;

    int arr[n]={1,2,3,4,5,6,9,12,13,14};

    int start=0;
    int end=n-1;
    int key=1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]==key){
            cout<<mid<<endl;
            return mid;

        }
        else if(key<arr[mid]){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    cout<<"Element Not found";
}
