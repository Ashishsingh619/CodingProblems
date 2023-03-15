
#include<iostream>
template <typename T>
class Node{
public:
    T data;
    Node<T>*next;

    Node(T element){
        data=element;
        next=NULL;
    }
};

template<typename T>
class queue{

    Node<T>* head;
    Node<T>* tail;
    int size;
public:
    queue(){
        head=NULL;
        tail=NULL;
        size=0;
    }

    void enqueue(T element){
        Node<T>* newNode=new Node<T>(element);
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
        size++;
    }

    int getSize(){
        return size;
    }

    bool isEmpty(){
        return size==0;
    }

    T dequeue(){
        if(isEmpty()){
            return 0;
        }
        Node<T>* temp=head;
        T ans=temp->data;
        head=head->next;
        delete temp;
        size--;
        return ans;
    }

    T front(){
        if(isEmpty()){
            return 0;
        }
        return head->data;
    }

};
