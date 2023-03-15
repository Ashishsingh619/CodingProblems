
#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Node{
public:
    T data;
    Node<T>* next;

    Node(T data){
        this->data=data;
        next=NULL;
    }
};

template<typename T>
class stackLL{
Node<T>* head;
int sizeLL;
public:
    stackLL(){
        head=NULL;
        this->sizeLL=0;
    }

    void push(T element){
        Node<T>*newNode=new Node<T>(element);
        if(head==NULL){
            head=newNode;
        sizeLL++;
        }
        else{
            newNode->next=head;
            head=newNode;
            sizeLL++;
        }
    }

    T size(){

        return this->sizeLL;
    }

    T isEmpty(){
        return this->sizeLL==0;
    }

    T pop(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
            return 0;
        }
        Node<T>* temp=head;
        head=head->next;
        T ans=temp->data;
        sizeLL--;
        delete temp;
        return ans;

    }

    T top(){
        if(isEmpty()){
            cout<<"Its empty"<<endl;
            return 0;
        }
        return head->data;
    }
};
