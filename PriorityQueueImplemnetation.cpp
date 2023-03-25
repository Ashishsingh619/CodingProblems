#include<vector>
#include<iostream>
using namespace std;
class PriorityQueue{

    vector<int>pq;
public:
    PriorityQueue(){}

    bool isEmpty(){
     return pq.size()==0;
    }

    int getSize(){
        return pq.size();
    }

    int getMin(){
        if(isEmpty()){
            return 0;
        }
        return pq[0];
    }

    void insert(int element){
        pq.push_back(element);
        int childIndex=pq.size()-1;
        while(childIndex>0){
            int parentIndex=(childIndex-1)/2;
            if(pq[childIndex]<pq[parentIndex]){
                int temp=pq[childIndex];
                pq[childIndex]=pq[parentIndex];
                pq[parentIndex]=temp;
            }else{

            break;
            }
            childIndex=parentIndex;
        }
    }

    void printArr(){
        for(int i=0;i<pq.size();i++){
            cout<<pq[i]<<" ";
        }
        cout<<endl;
    }

    int removeMinOld(){
        if(isEmpty()){
            return -1;
        }

        int ans=pq[0];

        pq[0]=pq[pq.size()-1];
        pq.pop_back();
        int parentIndex=0;
        while(parentIndex<pq.size()){
            int childIndex1=2*parentIndex+1;
            int childIndex2=2*parentIndex+2;
            if(childIndex1< pq.size() && childIndex2<pq.size() && pq[parentIndex]>pq[2*parentIndex+1] && pq[parentIndex]>pq[2*parentIndex+2]){
                int minIndex=0;
                if(pq[childIndex1]<childIndex2){
                    minIndex=childIndex1;
                }
                else{
                    minIndex=childIndex2;
                }
                int temp=pq[parentIndex];
                pq[parentIndex]=pq[minIndex];
                pq[minIndex]=temp;
                parentIndex=minIndex;
                }
                else if(childIndex1<pq.size()&&pq[parentIndex]>pq[childIndex1]){
                     int temp=pq[parentIndex];
                    pq[parentIndex]=pq[childIndex1];
                    pq[childIndex1]=temp;
                    parentIndex=childIndex1;
                }
                else if(childIndex2<pq.size()&&pq[parentIndex]>pq[childIndex2]){
                     int temp=pq[parentIndex];
                    pq[parentIndex]=pq[childIndex2];
                    pq[childIndex2]=temp;
                    parentIndex=childIndex2;
                }
                else{
                    break;
                }

        }
        return ans;
    }


    int removeMin(){
        if(isEmpty()){
            return -1;
        }
        int ans=pq[0];
        pq[0]=pq[pq.size()-1];
        pq.pop_back();
        int parentIndex=0;
        int leftChildIndex=2*parentIndex+1;
        int rightChildIndex=2*parentIndex+2;
        while(leftChildIndex<pq.size()){
            int minIndex=parentIndex;
            if(pq[leftChildIndex]<pq[parentIndex]){
                minIndex=leftChildIndex;
            }
            if(rightChildIndex<pq.size()&&pq[rightChildIndex]<pq[minIndex]){
                minIndex=rightChildIndex;
            }
            if(minIndex==parentIndex){
                break;
            }
            int temp=pq[parentIndex];
            pq[parentIndex]=pq[minIndex];
            pq[minIndex]=temp;
            parentIndex=minIndex;
            leftChildIndex=2*parentIndex+1;
            rightChildIndex=2*parentIndex+2;
        }
        return ans;
    }
};
