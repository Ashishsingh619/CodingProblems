#include"TrieNope.cpp"
#include<string>
using namespace std;
class Trie
{
    TrieNode*root;
public:
    Trie()
    {
        root=new TrieNode('\0');

    }

    void insertHelper(TrieNode*root,string str){
        if(str.size()==0)
        {
            root->isTerminal=true;
            return;
        }
        int index=str[0]-97;
        TrieNode* children=NULL;
        if(root->childrens[index]!=NULL){
            children=root->childrens[index];
        }
        else{
            children=new TrieNode(str[0]);
            root->childrens[index]=children;

        }
        insertHelper(children,str.substr(1));
    }
    void insert(string str)
    {
        insertHelper(root,str);
    }
    bool searchHelper(TrieNode*root,string str){
        if(str.size()==0){
            if(root->isTerminal){
                return true;
            }
            return false;
        }
        int index=str[0]-97;
        if(root->childrens[index]==NULL){
            return false;
        }
        return searchHelper(root->childrens[index],str.substr(1));
    }
    bool search(string str){
        return searchHelper(root,str);
    }
    void removeWordHelper(TrieNode* root, string word){
        if(word.size()==0){
            root->isTerminal=false;
            return ;
        }
        int index=word[0]-97;
        if(root->childrens[index]==NULL){
            return ;
        }
        removeWordHelper(root->childrens[index],word.substr(1));

        if(root->isTerminal==false){
            for(int i=0;i<26;i++){
                if(root->childrens[i]!=NULL){
                    return ;
                }
            }
            delete root;
        }
    }
    void removeWord(string word){
        removeWordHelper(root,word);
    }

    void removeHelper2(TrieNode*root,string word){
        if(word.size()==0){
            root->isTerminal=false;
            return;
        }
        int index=word[0]-97;
        if(root->childrens[index]==NULL){
            return;
        }

        removeHelper2(root->childrens[index],word.substr(1));
        if(root->childrens[index]->isTerminal!=true){
            for(int i=0;i<26;i++){
                if(root->childrens[index]->childrens[i]!=NULL){
                    return;
                }
            }
            delete root->childrens[index];
            root->childrens[index]=NULL;
        }
    }

    void removeWord2(string word){
        removeHelper2(root,word);
    }
};
