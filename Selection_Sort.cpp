#include<bits/stdc++.h>
using namespace std;

void SelectionSort(int arr[],int n){
    for(int i=0;i<n;i++){
            int min=arr[i];
            int index=i;
        for(int j=i;j<n;j++){
            if(arr[j]<min){
                min=arr[j];
                index=j;
            }
        }
        int temp=arr[i];
        arr[i]=min;
        arr[index]=temp;
    }
}




int main(){
    int n=5;
    int arr[n]={5,4,4,3,1};

    SelectionSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
