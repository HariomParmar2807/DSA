// Implementation of binary search tree with insertion,height and find min and max element in bst
#include<bits/stdc++.h>
using namespace std;

struct BstNode
{
    int data;
    BstNode *left;
    BstNode *right;
}*temp;
BstNode *createNode(int data)
{
    temp = new BstNode;
    temp->data = data;
    temp->left = NULL;
    temp->right= NULL;
    return temp;
}
void display(BstNode *root)
{
    if(root==NULL)
     cout<<"Nothing to display\n" 
    while(root!=NULL)
    {
        cout<<root->data<<"\n";
        root = root->right;
    } 
}
void Find_min(BstNode *root)
{
    if(root==NULL) return;
    while(root->left!=NULL)
    {
        root = root->left;
    }
    cout<<"Minimum Element=";
    cout<<root->data<<"\n";
}
int Height(BstNode *root)
{
    if(root==NULL)
     return -1;
    int left_height = Height(root->left);
    int right_height = Height(root->right);
    return max(left_height,right_height)+1;
   // cout<<"Height of tree ="<<h<<endl;
}
BstNode *insert(BstNode *root,int n)
{
    if(root==NULL)
      root = createNode(n);
    else if(n<=root->data)
      root->left = insert(root->left,n);
    else
      root->right = insert(root->right,n);   
    return root;      
}
int main()
{
    cout<<"binary tree implementation\n";
    BstNode *root=NULL; //Empty tree
    root = insert(root,5);
    root = insert(root,2);
    root = insert(root,4);
    root = insert(root,6);
    root = insert(root,9);
    root = insert(root,3);
    root = insert(root,11);
   // display(root);
    Find_min(root);// similarly maximum element find
    int h = Height(root);
    cout<<"Height of tree="<<h<<endl;
    return 0;
}
