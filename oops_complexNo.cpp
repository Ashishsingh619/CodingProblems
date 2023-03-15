#include<bits/stdc++.h>
using namespace std;

class Complex{
private:
    int real;
    int img;
public:
    Complex(int real,int img){
        this->real=real;
        this->img=img;
    }

    void print(){

        cout<<real<<" + "<<"i"<<img<<endl;
    }

    void add(Complex c){
        cout<<real+c.real<<" + "<<"i"<<img+c.img<<endl;

    }

};

int main(){

    Complex c1(2,4);
    c1.print();

    Complex c2(3,5);
    c1.add(c2);



}
