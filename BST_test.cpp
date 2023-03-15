#include "BST.cpp"
//#include "BinaryTreePrac2.cpp";
#include<iostream>
using namespace std;
void printTree(BinaryTreeNode<int>*root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<":";
    if(root->left!=NULL)
    {
        cout<<"L"<<root->left->data<<",";
    }
    if(root->right!=NULL)
    {
        cout<<"R"<<root->right->data<<",";
    }
    cout<<endl;
    printTree(root->left);
    printTree(root->right);

}

int main(){
    BST b;
    b.insert(3);
    b.insert(5);
    b.insert(4);
    b.insert(2);
    b.insert(9);
    b.insert(1);
    b.insert(11);
    b.insert(87);
    cout<<endl;
    printTree(b.root);
    b.deleteNode(3);
    cout<<endl;
    printTree(b.root);
}
