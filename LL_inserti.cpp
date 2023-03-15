#include<bits/stdc++.h>
#include"Node.cpp"
using namespace std;



Node* insertIth(Node* head,int ind,int val){
    Node *newNode=new Node(val);
    if(ind==0){
        newNode->next=head;
        head=newNode;
        return head;
    }
    int count=0;
    Node*temp=head;
    while(temp!=NULL && count<ind-1){
        count++;
        temp=temp->next;
    }
    if(temp!=NULL){
    newNode->next=temp->next;
    temp->next=newNode;
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

void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<"|"<<temp->data<<"|"<<"->";
        temp=temp->next;
    }

}


int main(){
    Node*head=TakeInputBetter();
    cout<<"Enter index and data"<<endl;
    int index,val;
    cin>>index>>val;
    cout<<endl;
    head=insertIth(head,index,val);
    print(head);
}
