#include<bits/stdc++.h>
#include"Node.cpp"
using namespace std;


void print(Node* head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    //statically
    // 1,2,3,4;
    Node n1(1);
    Node *head=&n1;
    Node n2(2);
    n1.next=&n2;
    Node n3(3);
    n2.next=&n3;
    Node n4(4);
    n3.next=&n4;

    print(head);




}
