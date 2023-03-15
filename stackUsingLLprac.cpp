#include<iostream>
#include "stack_practice.cpp"
using namespace std;

int main(){
    stack<int> s;
    s.push(20);
    s.push(30);
    cout<<s.top();
    s.pop();
    cout<<s.top();

}
