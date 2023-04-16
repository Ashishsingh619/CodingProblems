#include<iostream>
class TrieNode{
    public:
    char data;
    TrieNode**childrens;
    bool isTerminal;
    TrieNode(char data){
        this->data=data;
        childrens=new TrieNode*[26];
        for(int i=0;i<26;i++){
            childrens[i]=NULL;
        }
        isTerminal=false;

    }
};
