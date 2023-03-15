#include<vector>
#include<iostream>
#include<queue>
using namespace std;

template<typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<int>*>children;
    TreeNode(T data)
    {
        this->data=data;
    }
};

void printTree(TreeNode<int>* root)
{

    cout<<root->data<<":";
    for(int i=0; i<root->children.size(); i++)
    {
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i=0; i<root->children.size(); i++)
    {
        printTree(root->children[i]);
    }

}

TreeNode<int>* takeInput()
{
    //cout<<"Enter the data"<<endl;
    int rootData;
    cin>>rootData;
    TreeNode<int>*root=new TreeNode<int>(rootData);
    //
    cout<<"Enter the number of children for "<<root->data<<endl;
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        TreeNode<int>* child=takeInput();
        root->children.push_back(child);
    }
    return root;
}

TreeNode<int>* takeInputLevel()
{
    // cout<<"Enter the root data"<<endl;
    int rootData;
    cin>>rootData;
    TreeNode<int>* root=new TreeNode<int>(rootData);
    queue<TreeNode<int>*>pendingNode;
    pendingNode.push(root);
    while(!pendingNode.empty())
    {
        TreeNode<int>* front=pendingNode.front();
        pendingNode.pop();
        // cout<<"Enter the number of children for "<<front->data<<endl;
        int n;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            // cout<<"Enter the "<<(i+1)<<"st child of "<<front->data<<endl;
            int childData;
            cin>>childData;
            TreeNode<int>*childNode=new TreeNode<int>(childData);
            pendingNode.push(childNode);
            front->children.push_back(childNode);
        }
    }
    return root;


}
bool containsX(TreeNode<int>* root,int x)
{


    for(int i=0; i<root->children.size(); i++)
    {
        bool check=containsX(root->children[i],x);
        if(check)
        {
            return true;
        }
        return false;
    }
    if(root->data==x)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int greaterThanX(TreeNode<int>* root,int x)
{
    int count=0;
    for(int i=0; i<root->children.size(); i++)
    {
        count+=greaterThanX(root->children[i],x);
    }
    if(root->data>x)
    {
        return count+1;
    }
    return count;

}

TreeNode<int>* maximumSumChild(TreeNode<int>* root)
{
    int maxi=0;
    TreeNode<int>*maxiNode=root;
    for(int i=0; i<root->children.size(); i++)
    {
        TreeNode<int>*currentNode=maximumSumChild(root->children[i]);
        int currentSum=currentNode->data;
        for(int j=0; j<currentNode->children.size(); j++)
        {
            currentSum+=currentNode->children[j]->data;
        }
        if(currentSum>maxi)
        {
            maxi=currentSum;
            maxiNode=currentNode;
        }
    }
    int check=0;
    for(int i=0; i<root->children.size(); i++)
    {
        check+=root->children[i]->data;
    }
    check+=root->data;
    if(check>maxi)
    {
        maxiNode=root;
        return root;
    }
    return maxiNode;
}
bool structIdentical(TreeNode<int>*root1,TreeNode<int>*root2)
{
    for(int i=0; i<root1->children.size(); i++)
    {
        bool check=structIdentical(root1->children[i],root2->children[i]);
        if(!check)
        {
            return false;
        }
    }
    if(root1->children.size()!=root2->children.size())
    {
        return false;
    }
    if(root1->data!=root2->data)
    {
        return false;
    }
    // bool check2=true;
    for(int i=0; i<root1->children.size(); i++)
    {
        if(root1->children[i]->data!=root2->children[i]->data)
        {
            return false;
        }
    }
    return true;
}

TreeNode<int>* nextLarger(TreeNode<int>*root,int x)
{
    int mini=INT_MAX;

    TreeNode<int>*miniNode=NULL;
    // TreeNode<int>secondNode;
    for(int i=0; i<root->children.size(); i++)
    {
        TreeNode<int>*child=nextLarger(root->children[i],x);
        if(child!=NULL){
        if(child->data<mini)
        {
            mini=child->data;
            miniNode=child;
        }
        }
    }

    if(root->data>=x)
    {
        if(miniNode==NULL){
            miniNode=root;
        }
        else{
        if(root->data<=mini){
            mini=root->data;
            miniNode=root;

        }
        }
    }
    else{
        if(miniNode==NULL){
            return NULL;
        }
    }
    return miniNode;
}
void LevelKprint(TreeNode<int>* root,int k){
    for(int i=0;i<root->children.size();i++){
        LevelKprint(root->children[i],k-1);
    }
    if(k==0){
        cout<<root->data<<endl;
    }
}
void replaceDepthK(TreeNode<int>*root,int k){

    for(int i=0;i<root->children.size();i++){
        replaceDepthK(root->children[i],k+1);
    }
       root->data=k;
}
int main()
{
    TreeNode<int>* root=takeInputLevel();
    //TreeNode<int>* root2=takeInputLevel();
    cout<<endl;
    //LevelKprint(root,1);
    replaceDepthK(root,0);
    cout<<endl;
    printTree(root);
}


