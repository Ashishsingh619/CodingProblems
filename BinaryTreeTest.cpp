#include<iostream>
#include<queue>
#include "BinaryTreenode.cpp"

BinaryTreeNode<int>* takeInput(){
    int rootData;
    cout<<"Enter the data"<<endl;
    cin>>rootData;
    if(rootData==-1){
        return NULL;
    }
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int>* leftchild=takeInput();
    BinaryTreeNode<int>* rightChild=takeInput();
    root->left=leftchild;
    root->right=rightChild;
    return root;
}

void printLevelWise(BinaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }
    queue<BinaryTreeNode<int>*>pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        BinaryTreeNode<int>* front=pendingNodes.front();
        pendingNodes.pop();
        cout<<front->data<<":";
        if(front->left!=NULL){
            cout<<"L "<<front->left->data<<",";
            pendingNodes.push(front->left);
        }
        if(front->right!=NULL){
            cout<<"R "<<front->right->data<<",";
            pendingNodes.push(front->right);
        }
        cout<<endl;
    }
}
int countNodes(BinaryTreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    int count=0;
    count+=countNodes(root->left);
    count+=countNodes(root->right);
    return count+1;
}
BinaryTreeNode<int>* takeInputLevelWise(){

    cout<<"Enter the root data"<<endl;
    int rootData;
    cin>>rootData;
    if(rootData==-1){
        return NULL;
    }
    BinaryTreeNode<int>*root=new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*>pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        BinaryTreeNode<int>*front=pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter the left data for "<<front->data<<endl;
        int leftChild;
        cin>>leftChild;
        if(leftChild!=-1){
            BinaryTreeNode<int>*child=new BinaryTreeNode<int>(leftChild);
            front->left=child;
            pendingNodes.push(child);
        }
        cout<<"Enter the right data for "<<front->data<<endl;
        int rightChild;
        cin>>rightChild;
        if(rightChild!=-1){
            BinaryTreeNode<int>*child=new BinaryTreeNode<int>(rightChild);
            front->right=child;
            pendingNodes.push(child);
        }
    }
    return root;

}
void printTree(BinaryTreeNode<int>* root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<":";
    if(root->left!=NULL){
        cout<<"L"<<root->left->data<<",";
    }
    if(root->right!=NULL){
        cout<<"R"<<root->right->data<<",";
    }
    cout<<endl;
    printTree(root->left);
    printTree(root->right);
}
int main(){
    BinaryTreeNode<int>*root=takeInputLevelWise();
    printLevelWise(root);
    cout<<endl;
    cout<<countNodes(root);
}

