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
void print(Node* head)
{
    Node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
}

Node* TakeInput()
{
    int data;
    cin>>data;
    Node*head=NULL;
    Node* last=NULL;
    while(data!=-1)
    {
        Node* newNode=new Node(data);

        if(head==NULL)
        {
            head=newNode;
            last=newNode;
        }
        else
        {
            last->next=newNode;
            last=newNode;
        }
        cin>>data;
    }
    return head;
}
Node* insertIth(Node*head,int index,int val)
{
    Node* newNode=new Node(val);
    if(index==0)
    {
        newNode->next=head;
        head=newNode;
        return head;
    }
    int count=0;
    Node*temp=head;
    while(temp!=NULL && count<index-1)
    {
        temp=temp->next;
        count++;
    }
    if(temp!=NULL)
    {
        newNode->next=temp->next;
        temp->next=newNode;

    }
    return head;

}
int len(Node* head)
{
    if(head==NULL)
    {
        return 0;
    }
    return len(head->next)+1;
}
Node* solve(Node* head,int val)
{
    int leng=len(head);
    int ind=leng-val;
    int count=0;
    Node* temp=head;
    while(count<ind-1)
    {
        temp=temp->next;
        count++;
    }
    Node* storeLast=temp;
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=head;
    head=storeLast->next;
    storeLast->next=NULL;

    return head;
}
Node* ReverseLL(Node* head)
{
    Node* temp=head;
    Node* prev=NULL;
    Node* nextNode=NULL;
    while(temp->next!=NULL)
    {
        nextNode=temp->next;
        temp->next=prev;
        prev=temp;
        temp=nextNode;

    }
    temp->next=prev;
    return temp;
}

Node* reverseRec(Node*head)
{

    if(head==NULL)
    {
        return head;
    }
    if(head->next==NULL){
        return head;
    }

    Node* smallHead=reverseRec(head->next);
    Node* nextStore=head->next;
    nextStore->next=head;
    head->next=NULL;



    return smallHead;
}
int findNode(Node* head,int val){
    if(head==NULL){
        return -1;
    }
    int check=findNode(head->next,val);
    if(check==-1){
        if(head->data==val){
            return 0;
        }
        else{
            return -1;
        }
    }
    else{
        if(head->data==val){
            return 0;
        }
        else{
            return 1+check;
        }
    }
}
int main()
{
    Node* head=TakeInput();
    cout<<endl;
    print(head);
    cout<<endl;
    cout<<"enter search"<<endl;
    int data;
    cin>>data;
    cout<<findNode(head,data);


}
