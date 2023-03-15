
#include<iostream>
using namespace std;
class stackArray{
    int * data;
    int nextIndex;
    int capacity;

public:
    stackArray(){
        data=new int[4];
        nextIndex=0;
        capacity=4;
    }

    int size(){
        return nextIndex;
    }

    bool isEmpty(){
        return nextIndex==0;
    }

    void push(int element){
        if(nextIndex==capacity){
            int* newdata=new int[2*capacity];
            for(int i=0;i<capacity;i++){
                newdata[i]=data[i];
            }
            capacity=capacity*2;
            delete []data;
            data=newdata;
        }
        data[nextIndex]=element;
        nextIndex++;
    }

    int pop(){
        if(isEmpty()){
                cout<<"Stack empty"<<endl;
            return -1;
        }
        nextIndex--;
        return data[nextIndex];

    }

    int top(){
        if(isEmpty()){
            cout<<"Stack empty"<<endl;
            return -1;
        }
        return data[nextIndex-1];
    }
};
