#include<iostream>
using namespace std;

template<typename T>
class queue{
T* data;
int nextIndex;
int firstIndex;
int capacity;
int size;

public:
    queue(){
        data=new T[4];
        nextIndex=0;
        firstIndex=-1;
        capacity=4;
        size=0;
    }

    T getSize(){
        return this->size;
    }

    bool isEmpty(){
        return size==0;
    }

    void enqueue(T element){
        if(size==capacity){
            T* newData=new T[2*capacity];
            int k=0;
            for(int i=firstIndex;i<capacity;i++){
                newData[k++]=data[i];
            }

            for(int i=0;i<firstIndex;i++){
                newData[k++]=data[i];
            }

            firstIndex=0;
            nextIndex=capacity;
            capacity=2*capacity;
            delete []data;
            data=newData;

        }
        data[nextIndex]=element;
        nextIndex=(nextIndex+1)%capacity;
        if(firstIndex==-1){
            firstIndex=0;
        }
        size++;
    }

    T front(){
        if(isEmpty()){
            return 0;
        }
        return data[firstIndex];
    }

    T dequeue(){
        if(isEmpty()){
            return 0;
        }
        T ans=data[firstIndex];
        firstIndex=(firstIndex+1)%capacity;
        size--;
        if(size==0){
            firstIndex=-1;
            nextIndex=0;
        }
        return ans;
    }
};
