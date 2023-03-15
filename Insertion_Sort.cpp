#include<bits/stdc++.h>
using namespace std;

void InsertionSort(int arr[],int n){
    for(int i=1;i<n;i++){

        int j=i-1;
        int k=i;
        while(j>=0){
            if(arr[k]<arr[j]){
                int temp=arr[k];
                arr[k]=arr[j];
                arr[j]=temp;
                k=j;
            }
            j--;
        }
    }
}
int main(){

    int n=5;
    int arr[n]={5,34,4,4,1};

    InsertionSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

}
