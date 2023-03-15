#include<bits/stdc++.h>
using namespace std;
class Fraction{
private:
    int num;
    int den;
public:
    Fraction(int num,int den){
        this->num=num;
        this->den=den;

    }

    void print(){
    cout<<num<<"/"<<den<<endl;
    }
    void mul(Fraction f){
        cout<<num*f.num<<"/"<<den*f.den<<endl;
    }
};

int main(){
    Fraction f1(1,2);
    f1.print();
    Fraction f2(1,2);
    f1.mul(f2);

}
