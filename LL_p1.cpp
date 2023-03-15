#include<bits/stdc++.h>
using namespace std;

class Node
{

public:
    int data;
    Node*next;

    Node(int data)
    {
        this->data=data;
        next=NULL;
    }
};

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

int length(Node*head){
    if(head==NULL){
        return 0;
    }
    return length(head->next)+1;


}

Node* Insert(Node* head,int index,int data){
    if(head==NULL){
        return head;
    }
    Node*smallHead=Insert(head->next,index-1,data);
    if(index==0){
        Node*newNode=new Node(data);
        newNode->next=head;
        head=newNode;
        return head;
    }
    head->next=smallHead;
    return head;

}

Node* deleteNode(Node*head,int index){

    if(head==NULL){
        return head;
    }
    Node*smallHead=deleteNode(head->next,index-1);
    if(index==0){
        Node*temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    head->next=smallHead;
    return head;

}
Node* swapNodes(Node* head,int ind1,int ind2){
    Node* temp1=head;
    Node* temp2=head;
    int count1=0;
    int count2=0;

    while(temp1!=NULL){
        if(count1>=ind1-1){
            break;
        }
        count1++;
        temp1=temp1->next;
    }
     while(temp2!=NULL){
        if(count2>=ind2-1){
            break;
        }
        count2++;
        temp2=temp2->next;
    }
    if(ind1==0 || ind2==0){

       Node* firstNext=temp1->next;
        Node* second=temp2->next;
        Node* secondNext=temp2->next->next;
        second->next=firstNext;
        temp2->next=temp1;
        temp1->next=secondNext;
        return second;

    }

    Node* firstNext=temp1->next->next;
    Node* first=temp1->next;
    Node* secondNext=temp2->next->next;
    Node* second=temp2->next;
    temp1->next=second;
    second->next=firstNext;
    temp2->next=first;
    first->next=secondNext;
    if(ind1==0||ind2==0){
        return second;
    }
    return head;
}
Node* bubbleSort(Node* head){
    if(head==NULL){
        return NULL;
    }
    if(head->next==NULL){
        return head;
    }
    int n=length(head);// 1 2 3 4 -1
    Node* newHead=head;// 2 1 3 4 -1
    while(n--){
        Node* temp=newHead;
        Node* tempNext=NULL;
        Node* tempPrev=NULL;
        while(temp!=NULL && temp->next!=NULL){

            tempNext=temp->next;
            if(temp->data>tempNext->data){
            if(tempPrev!=NULL){
            tempPrev->next=tempNext;
            tempPrev=tempNext;
            }

            if(temp==newHead){
                newHead=tempNext;
                tempPrev=tempNext;
            }
            temp->next=tempNext->next;
            tempNext->next=temp;
            }
            else{
                if(temp==newHead){
                newHead=temp;

                }
                tempPrev=temp;
                temp=temp->next;

            }
            //temp=temp->next;
        }
        //print(newHead);
        //cout<<endl;

    }
    return newHead;


}
int main(){
    Node*head=TakeInputBetter();
    int i,j;
    head=bubbleSort(head);
    cout<<endl;
    print(head);


}
