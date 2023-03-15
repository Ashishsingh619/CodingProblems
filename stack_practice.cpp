
#include<iostream>
using namespace std;

template <typename T>
class Node{
public:
    T data;
    Node<T>* next;
    Node(T element){
        data=element;
        next=NULL;
    }
};


template <typename T>
class stack{
    Node<T>* head;
    int count;
public:
    stack(){
        head=NULL;
        count=0;
    }

   void push(T element){
        Node<T>* newNode=new Node<T>(element);
        if(head==NULL){
            head=newNode;
        }
        else{
            newNode->next=head;
            head=newNode;
        }
        count++;
    }

    void pop(){
        Node<T>* temp=head;
        head=head->next;
        delete temp;
    }

    T top(){
        return head->data;
    }

};
