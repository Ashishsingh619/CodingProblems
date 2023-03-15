#include<bits/stdc++.h>
using namespace std;
int main(){
    //9,8,7,4,3,2;
    int n=10;
    int arr[n]={34,14,9,8,7,6,5,3,2,1};
    int key=1;
    int start=0;
    int end=n-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]==key){
            cout<<mid<<endl;
            return 0;
        }
        else if(key<arr[mid]){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    cout<<"Not Found"<<endl;
}
