
#include<iostream>
#include<string>
using namespace std;

template<typename V>
class MapNode{
    public:
    string key;
    V value;
    MapNode<V>* next;

    MapNode(string key,V value){
        this->key=key;
        this->value=value;
        next=NULL;

    }

    ~MapNode(){
        delete next;
    }
};

template <typename V>
class Map{

    MapNode<V>** buckets;
    int count;
    int bucketSize;

    public:
    Map(){
        bucketSize=20;
        buckets=new MapNode<V>*[bucketSize];
        count=0;
        for(int i=0;i<bucketSize;i++){
            buckets[i]=NULL;
        }
    }

    ~Map(){
        for(int i=0;i<bucketSize;i++){
            delete buckets[i];
        }
        delete []buckets;
    }

    private:
        int getBucketIndex(string key){
            long long ans=0;
            long long p=1;
            for(int i=key.size()-1;i>=0;i--){
                ans+=key[i]*p;
                p=p*37;
            }
            return ans%bucketSize;
        }
    public:
    void insert(string key, V value){
        int bucketIndex=getBucketIndex(key);
        MapNode<V>* head=buckets[bucketIndex];
        while(head!=NULL){
            if(head->key==key){
                head->value=value;
                return ;
            }
            head=head->next;
        }
        head=buckets[bucketIndex];
        MapNode<V>* newNode=new MapNode<V>(key,value);
        newNode->next=head;
        buckets[bucketIndex]=newNode;
        count++;
    }

    V remove(string key){
        int bucketIndex=getBucketIndex(key);
        MapNode<V>* head=buckets[bucketIndex];
        MapNode<V>*prev=NULL;
        while(head!=NULL){
            if(head->key==key){
                V ans=head->value;
                if(prev==NULL){

                    buckets[bucketIndex]=head->next;
                    //return ans;

                }
                else{
                prev->next=head->next;
                }
                head->next=NULL;
                delete head;
                count--;
                return ans;

            }
            prev=head;
            head=head->next;
        }
        return 0;

    }
    int size(){
        return count;
    }
    V getValue(string key){
          int bucketIndex=getBucketIndex(key);
        MapNode<V>* head=buckets[bucketIndex];
        while(head!=NULL){
            if(head->key==key){
                return head->value;
            }
        }
        return 0;

    }



};
