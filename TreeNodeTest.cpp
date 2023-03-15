#include "TreeNode.cpp"
#include<queue>
#include<iostream>
using namespace std;

TreeNode<int>* takeInput(){

int data;
cout<<"Enter the data"<<endl;
cin>>data;
TreeNode<int>*root=new TreeNode<int>(data);
int n;
cout<<"Enter the number of children for "<<data<<endl;
cin>>n;
for(int i=0;i<n;i++){
    TreeNode<int>*child=takeInput();
    root->children.push_back(child);
}
return root;

}
void printTree(TreeNode<int>* root){
    if(root==NULL)return;
    cout<<root->data<<":";
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++){
        printTree(root->children[i]);
    }
}

TreeNode<int>* TakeInputLevelWise(){
    cout<<"Enter the root data"<<endl;
    int rootData;
    cin>>rootData;
    TreeNode<int>* root=new TreeNode<int>(rootData);
    queue<TreeNode<int>*>remChildren;
    remChildren.push(root);
    while(!remChildren.empty()){
        TreeNode<int> *front=remChildren.front();
        remChildren.pop();
        cout<<"Enter no of children for "<<front->data<<endl;
        int childNum;
        cin>>childNum;
        for(int i=0;i<childNum;i++){
            cout<<"Enter the "<<(i+1)<<" th child of "<<front->data<<endl;
            int childData;
            cin>>childData;
            TreeNode<int>*childNode=new TreeNode<int>(childData);
            front->children.push_back(childNode);
            remChildren.push(childNode);
        }
    }
    return root;

}

void printTreeLevelWise(TreeNode<int>* root){
    queue<TreeNode<int>*>pendingNode;
    pendingNode.push(root);
    while(!pendingNode.empty()){
        TreeNode<int>*front=pendingNode.front();
        pendingNode.pop();
        cout<<front->data<<":";
        for(int i=0;i<front->children.size();i++){
            cout<<front->children[i]->data<<",";
            pendingNode.push(front->children[i]);

        }
        cout<<endl;
    }
}

int countNodes(TreeNode<int>*root){
    int count=0;
    for(int i=0;i<root->children.size();i++){
        count+=countNodes(root->children[i]);
    }
    return count+1;
}
int sumTree(TreeNode<int>*root){
    int sum=0;
    for(int i=0;i<root->children.size();i++){
        sum+=sumTree(root->children[i]);
    }
    return sum+root->data;
}
TreeNode<int>* largestNode(TreeNode<int>* root){
    int maxi=-1;
    TreeNode<int>* maxiNode=NULL;
    for(int i=0;i<root->children.size();i++){
        TreeNode<int>*currentLargest=largestNode(root->children[i]);
        if(currentLargest->data>maxi){
            maxi=currentLargest->data;
            maxiNode=currentLargest;
        }
    }
    if(maxi>root->data){
        return maxiNode;
    }
    return root;
}
int heightTree(TreeNode<int>*root){
    int maxHeight=0;
    for(int i=0;i<root->children.size();i++){
        int currentMaxi=heightTree(root->children[i]);
        if(currentMaxi>maxHeight){
            maxHeight=currentMaxi;
        }
    }
    return maxHeight+1;

}
int countLeaf(TreeNode<int>* root){
    int count=0;
    for(int i=0;i<root->children.size();i++){
        count+=countLeaf(root->children[i]);
    }
    if(root->children.size()==0){
        return count+1;
    }
    return count;
}
TreeNode<int>* deleteLeaf(TreeNode<int>*root){


    for(int i=0;i<root->children.size();i++){
        TreeNode<int>* check=deleteLeaf(root->children[i]);


            root->children[i]=check;

    }
    for(int i=root->children.size()-1;i>=0;i--){
        if(root->children[i]==NULL){
            if(i==root->children.size()-1){
                v.pop_back();
            }

        }
    }
     if(root->children.size()==0){
        delete root;
        return NULL;
    }
    return root;
}
int main(){

    TreeNode<int>* root=TakeInputLevelWise();
    printTreeLevelWise(root);
    cout<<endl;
    root=deleteLeaf(root);
    printTreeLevelWise(root);

}
