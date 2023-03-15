#include<bits/stdc++.h>
#include"Node.cpp"
using namespace std;


Node* TakeInput(){

    int data;
    cin>>data;
    Node* head=NULL;
    while(data!=-1){
        Node* newNode=new Node(data);
        if(head==NULL){
            head=newNode;
        }
        else{
            Node*temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newNode;
        }
        cin>>data;
    }
    return head;
}

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

int length(Node *head){
    Node* temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}

void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<"|"<<temp->data<<"|"<<"->";
        temp=temp->next;
    }

}

int getIth(Node*head,int ind){
Node* temp=head;
int count=0;
while(temp!=NULL){
    if(count==ind){
        return temp->data;
    }
    count++;
    temp=temp->next;
}
return -1;

}
int  main(){

Node*head=TakeInputBetter();
print(head);
cout<<endl;
cout<<length(head);
cout<<endl;
cout<<getIth(head,3);
}
