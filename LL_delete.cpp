#include<bits/stdc++.h>
#include"Node.cpp"
using namespace std;


Node* TakeInputBetter(){

    int data;
    cin>>data;
    Node* head=NULL;
    Node* tail=NULL;
    while(data!=-1){
        Node* newNode=new Node(data);
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }
        else{
                tail->next=newNode;
                tail=newNode;
            }
        cin>>data;
    }
    return head;
}

void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<"|"<<temp->data<<"|"<<"->";
        temp=temp->next;
    }

}

Node* deleteIth(Node* head,int index){

    if(index==0){
        Node* temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    int count=0;
    Node*temp=head;
    while(temp!=NULL && count<index-1){
        count++;
        temp=temp->next;
    }
    if(temp!=NULL){
    Node*store=temp->next;
    temp->next=temp->next->next;
    delete store;
    }
    return head;
}

int main(){
 Node*head=TakeInputBetter();
 int index;
 cout<<"Enter index to be deleted"<<endl;
 cin>>index;
 cout<<endl;
 head=deleteIth(head,index);
 print(head);

}
