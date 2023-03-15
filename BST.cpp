#include "BinaryTreenode.cpp";
class BST{
    public:
    BinaryTreeNode<int>*root;
    private:
    bool isPresent(int element, BinaryTreeNode<int>*Node){
        if(Node==NULL){
            return false;
        }
        if(Node->data==element){
            return true;
        }
        if(element<Node->data){
            return isPresent(element,Node->left);
        }
        if(element>Node->data){
            return isPresent(element,Node->right);
        }
    }
    BinaryTreeNode<int>* insert(BinaryTreeNode<int>*root,int element){
        if(root==NULL){
            BinaryTreeNode<int>* newRoot=new BinaryTreeNode<int>(element);
            return newRoot;
        }
        if(element>root->data){
            root->right=insert(root->right,element);
        }
        if(element<root->data){
            root->left=insert(root->left,element);
        }
        return root;
    }

    BinaryTreeNode<int>* getMax(BinaryTreeNode<int>*root){
        int maxi=INT_MIN;
        BinaryTreeNode<int>*maxNode=NULL;
        if(root==NULL){
            return NULL;
        }
        if(root->data>maxi){
            maxi=root->data;
            maxNode=root;
        }
        BinaryTreeNode<int>*res1=getMax(root->left);
        BinaryTreeNode<int>*res2=getMax(root->right);
        if(res1->data>maxi){
            maxi=res1->data;
            maxNode=res1;
        }
        if(res2->data>maxi){
            maxi=res2->data;
            maxNode=res2;
        }
        return maxNode;

    }

BinaryTreeNode<int>* deleteNode(BinaryTreeNode<int>*root,int element){
        if(root==NULL){
            return NULL;
        }
        if(element<root->data){
            root->left=deleteNode(root->left,element);
            return root;
        }
        if(element>root->data){
            root->right=deleteNode(root->right,element);
            return root;
        }
        if(root->data==element){
            if(root->left==NULL && root->right==NULL){
                delete root;
                return NULL;
            }
            else if(root->left!=NULL && root->right==NULL){
                BinaryTreeNode<int>*temp=root->left;
                root->left=NULL;
                delete root;
                return temp;
            }
            else if(root->left==NULL && root->right!=NULL){
                BinaryTreeNode<int>*temp=root->right;
                root->right=NULL;
                delete root;
                return temp;
            }
            else{
                BinaryTreeNode<int>*minNode=root->right;
                while(minNode->left!=NULL){
                    minNode=minNode->left;
                }
                root->data=minNode->data;
                root->right=deleteNode(root->right,minNode->data);
                return root;
            }
        }
    }
public:
    BST(){
        root=NULL;
    }
    ~BST(){
        delete root;
    }
    bool isPresent(int element){
        return isPresent(element,root);
    }

    void insert(int element){
        this->root=insert(root,element);
    }

    void deleteNode(int element){
        this->root= deleteNode(root,element);
    }
};
