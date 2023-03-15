#include<bits/stdc++.h>
using namespace std;

bool f(string str,int i,int n){
    if(i>=n/2){
        return true;
    }
    if(str[i]!=str[n-i-1]){
        return false;
    }
    return f(str,i+1,n);
}
int main(){
    string str="madai";
     cout<<f(str,0,str.size());
}
