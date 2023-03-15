#include<iostream>
#include<queue>
#include<utility>
using namespace std;
template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T>*left;
    BinaryTreeNode<T>*right;
    BinaryTreeNode(T data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
};

class Node
{
public:
    int data;
    Node*next;
    Node(int data)
    {
        this->data=data;
        next=NULL;
    }
};

BinaryTreeNode<int>* takeInput()
{
    int rootData;
    cout<<"Enter data"<<endl;
    cin>>rootData;
    if(rootData==-1)
    {
        return NULL;
    }
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootData);
    root->left=takeInput();
    root->right=takeInput();
    return root;
}

BinaryTreeNode<int>* takeInputLevelWise()
{
    int rootData;
    cout<<"Enter root Data"<<endl;
    cin>>rootData;
    if(rootData==-1)return NULL;
    BinaryTreeNode<int>*root=new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*>q;
    q.push(root);
    while(!q.empty())
    {

        BinaryTreeNode<int>*front=q.front();
        q.pop();
        cout<<"Enter the left for "<<front->data<<endl;
        int leftData;
        cin>>leftData;
        if(leftData!=-1)
        {
            BinaryTreeNode<int>*child=new BinaryTreeNode<int>(leftData);
            q.push(child);
            front->left=child;
        }
        cout<<"Enter the  right for "<<front->data<<endl;
        int rightData;
        cin>>rightData;
        if(rightData!=-1)
        {
            BinaryTreeNode<int>*child=new BinaryTreeNode<int>(rightData);
            q.push(child);
            front->right=child;
        }


    }
    return root;
}
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
BinaryTreeNode<int>* insertDuplicateNode(BinaryTreeNode<int>* root){
    if(root==NULL){
        return NULL;
    }
    BinaryTreeNode<int>*ans1=insertDuplicateNode(root->left);
    BinaryTreeNode<int>*ans2=insertDuplicateNode(root->right);
    BinaryTreeNode<int>*newNode=new BinaryTreeNode<int>(root->data);
    root->left=newNode;
    newNode->left=ans1;
    root->right=ans2;
    return root;
}
bool searchElement(BinaryTreeNode<int>*root,int element){
    if(root==NULL){
        return false;
    }
    if(root->data==element){
        return true;
    }
    return searchElement(root->left,element)||searchElement(root->right,element);

}
vector<pair<int,int>> PairSum(BinaryTreeNode<int>* root,int target,BinaryTreeNode<int>* mainroot){
    if(root==NULL){
        return {};
    }

    vector<pair<int,int>>res1=PairSum(root->left,target,mainroot);
    vector<pair<int,int>>res2=PairSum(root->right,target,mainroot);

    vector<pair<int,int>>ans;
    for(auto i:res1){
        ans.push_back(i);
    }
    for(auto i:res2){
        ans.push_back(i);
    }
     bool check=searchElement(mainroot,(target)-(root->data));
    //ans.push_back()
    if(check){
        pair<int,int>ansPair;
        ansPair.first=root->data;
        ansPair.second=(target)-(root->data);
        ans.push_back(ansPair);
        return ans;
    }
    return ans;
}

int sumNodes(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return root->data+sumNodes(root->left)+sumNodes(root->right);
}
int heightTree(BinaryTreeNode<int>*root)
{
    if(root==NULL)
    {
        return 0;
    }
    return max(heightTree(root->left),heightTree(root->right))+1;
}
bool isBalancedBinaryTree(BinaryTreeNode<int>*root)
{
    if(root==NULL)
    {
        return true;
    }
    bool check1=isBalancedBinaryTree(root->left);
    bool check2=isBalancedBinaryTree(root->right);
    if(!(check1&&check2))
    {
        return false;
    }
    int check3=abs(heightTree(root->left)-heightTree(root->right));
    if(check3<=1)
    {
        return true;
    }
    else
        return false;
}
BinaryTreeNode<int>* removeLeafNode(BinaryTreeNode<int>*root)
{

    if(root==NULL)
    {
        return NULL;
    }
    if(root->left==NULL && root->right==NULL)
    {
        delete root;
        return NULL;
    }
    root->left=removeLeafNode(root->left);
    root->right=removeLeafNode(root->right);
    return root;

}
pair<int,bool> isBalancedBinaryTreeBetter(BinaryTreeNode<int>*root)
{
    if(root==NULL)
    {
        pair<int,bool>ans;
        ans.first=0;
        ans.second=true;
        return ans;
    }
    pair<int,bool>ans1=isBalancedBinaryTreeBetter(root->left);
    pair<int,bool>ans2=isBalancedBinaryTreeBetter(root->right);
    if(!(ans1.second&&ans2.second))
    {
        pair<int,bool>ans;
        ans.first=max(ans1.first,ans2.first)+1;
        ans.second=false;
        return ans;
    }
    if(abs(ans1.first-ans2.first)<=1)
    {
        pair<int,bool>ans;
        ans.first=max(ans1.first,ans2.first)+1;
        ans.second=true;
        return ans;

    }
    pair<int,bool>ans;
    ans.first=max(ans1.first,ans2.first)+1;
    ans.second=false;
    return ans;
}
void printLL(Node* head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
    cout<<endl;
}

vector<Node*> levelWiseLL(BinaryTreeNode<int>* root)
{
    queue<BinaryTreeNode<int>*>q;
    vector<Node*>ans;
    Node* head=NULL;
    Node* tail=head;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        BinaryTreeNode<int>*front=q.front();
        q.pop();
        if(front==NULL)
        {
            //tail->next=NULL;
            ans.push_back(head);
            //tail->next=NULL;
           // printLL(head);
            head=NULL;
            if(!q.empty())
            q.push(NULL);
            tail=NULL;

        }
        if(front!=NULL){

            Node* temp=new Node(front->data);
            if(head==NULL){
                head=temp;
                tail=temp;
            }
            else{
            tail->next=temp;
            tail=tail->next;
            }
        }
        if(front!=NULL && front->left!=NULL)
        {
            //Node* temp=new Node(front->left->data);
            //tail->next=temp;
            //tail=tail->next;
            q.push(front->left);
        }
        if(front!=NULL && front->right!=NULL)
        {
            //Node* temp=new Node(front->right->data);
            //tail->next=temp;
            //tail=tail->next;
            q.push(front->right);
        }
    }
    //cout<<"working:"<<endl;
    return ans;
}
void elementsBetweenk1andk2(BinaryTreeNode<int>*root,int k1,int k2){
    if(root==NULL){
        return;
    }
    if(root->data>=k1 && root->data<=k2){
        cout<<root->data<<endl;
    }
    if(k1<root->data){
        elementsBetweenk1andk2(root->left,k1,k2);
    }
    if(k2>root->data){
        elementsBetweenk1andk2(root->right,k1,k2);
    }
}
class BSTLL{
public:
    Node* head;
    Node* tail;
};
BSTLL BstToLL(BinaryTreeNode<int>*root){
    if(root==NULL){
        BSTLL obj;
        obj.head=NULL;
        obj.tail=NULL;
        return obj;
    }
    BSTLL res1=BstToLL(root->left);
    BSTLL res2=BstToLL(root->right);
    Node* temp=new Node(root->data);
   //cout<<temp->data<<endl;
   BSTLL ans;

   if(res1.head==NULL && res2.head==NULL){
    ans.head=temp;
    ans.tail=temp;
   }
   else if(res1.head==NULL && res2.head!=NULL){
    temp->next=res2.head;
    ans.head=temp;
    ans.tail=res2.tail;
   }
   else if(res1.head!=NULL && res2.head==NULL){
    res1.tail->next=temp;
    ans.head=res1.head;
    ans.tail=temp;
   }
   else{
    res1.tail->next=temp;
   temp->next=res2.head;
   ans.head=res1.head;
   ans.tail=res2.tail;
   }
   return ans;

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

void pathSumRootToLeaf(BinaryTreeNode<int>*root,int k,int sum,vector<int> str,vector<vector<int>>ans){
    if(root==NULL){
        return ;
    }
    if(root->left==NULL && root->right==NULL){
        sum=root->data;
        str.push_back(root->data);
        if(sum==k){

            ans.push_back(str);
            return;
        }

    }
    pathSumRootToLeaf(root->left,k,sum+root->data,str,ans);
    pathSumRootToLeaf(root->right,k,sum+root->data,str,ans);

}

vector<int> longestRootToLeafPath(BinaryTreeNode<int>*root){
    if(root==NULL){
        return {};
    }
    if(root->left==NULL && root->right==NULL){
            vector<int>v;
        v.push_back(root->data);
        return v;
    }
    vector<int>ans1=longestRootToLeafPath(root->left);
   vector<int>ans2= longestRootToLeafPath(root->right);
   if(ans1.size()>ans2.size()){
    ans1.push_back(root->data);
    return ans1;
   }
   ans2.push_back(root->data);
   return ans2;


}

BinaryTreeNode<int>* removeLeafNodeTree(BinaryTreeNode<int>*root){

    if(root==NULL){
        return NULL;
    }
    if(root->left==NULL && root->right==NULL){
        delete root;
        return NULL;
    }

    root->left=removeLeafNodeTree(root->left);
    root->right=removeLeafNodeTree(root->right);
    return root;


}
int main()
{
    BinaryTreeNode<int>*root=takeInputLevelWise();
    printLevelWise(root);
    cout<<endl;
   // Node* head=BstToLL(root).head;
    //printLL(head);
    //cout<<heightTree(root)<<endl;
    //BinaryTreeNode<int>*root2=removeLeafNode(root);
    //printTree(root2);
    //cout<<sumNodes(root);
    //elementsBetweenk1andk2(root,6,10);
    root=removeLeafNodeTree(root);
    printLevelWise(root);

}
