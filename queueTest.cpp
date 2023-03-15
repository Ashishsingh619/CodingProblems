#include"queueArray2.cpp"
#include<iostream>
using namespace std;

void reverseQueue(queue<int>&q){
    if(q.isEmpty()){
        return ;
    }

    int frontElement=q.front();
    q.dequeue();
    reverseQueue(q);
    q.enqueue(frontElement);
}

int main(){
    queue<int>q;
    for(int i=10;i<=50;i=i+10){
        q.enqueue(i);
    }
    cout<<endl;
    reverseQueue(q);
    while(!q.isEmpty()){
        cout<<q.front()<<endl;
        q.dequeue();
    }
}

