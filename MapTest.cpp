#include"MapImplementation.cpp"
#include<iostream>
using namespace std;
int main(){

Map<int>m;
m.insert("abc",3);
m.insert("def",4);
m.insert("m",5);
cout<<m.getValue("def")<<endl;
cout<<m.remove("m")<<endl;
cout<<m.size();
}
