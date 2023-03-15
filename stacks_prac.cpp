
#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    cin>>str;
    stack<char>s;
    cout<<endl;

    for(int i=0;i<str.size();i++){

        if(str[i]=='{'){
            s.push(str[i]);
        }
        else if(s.empty() && str[i]=='}'){
            s.push(str[i]);
        }
        else if(s.top()=='}' && str[i]=='}'){
            s.push(str[i]);
        }
        else{
            s.pop();
        }
    }
    int count=0;
    while(!s.empty()){
        char ch1=s.top();
        s.pop();
        char ch2=s.top();
        s.pop();
        if(ch1==ch2){
            count++;
        }
        else{
            count+=2;
        }
    }
    cout<<count<<endl;

}
