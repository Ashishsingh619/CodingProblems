#include<bits/stdc++.h>
using namespace std;
int cnt=0;
void f(){
    if(cnt==3){
        return ;
    }
    cout<<cnt<<endl;
    cnt++;
    f();
}
int main(){
    f();
}

