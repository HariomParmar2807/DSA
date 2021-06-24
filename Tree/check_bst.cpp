// check a binary tree binary search tree or not
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
}*root=NULL,*temp;
// 1st approach = recursion time expensive time complexity = o(n^2)
/*bool Issubtreelesser(Node *root,int num)
{
    if(root==NULL)  return true;
    if(root->data<=num && Issubtreelesser(root->left,num) && Issubtreelesser(root->right,num))
      return true;
    else 
      return false;  
}
bool Issubtreegreater(Node *root,int num)
{
    if(root==NULL)  return true;
    if(root->data > num && Issubtreegreater(root->left,num) && Issubtreegreater(root->right,num))
      return true;
    else 
      return false;  
}
bool Isbst(Node *root)
{
    if(root==NULL) return true;
    if(Issubtreelesser(root->left,root->data)&&Issubtreegreater(root->right,root->data)&&Isbst(root->left)&&Isbst(root->right))
      return true;
    else 
      return false;  
}
void display(Node *root)
{
 while(root!=NULL)
 {
   cout<<root->data<<" ";
   root = root->left;
 }
}*/
// 2nd approch efficient solution in 0(n) define range
bool Isbstutil(Node *root,int min_value,int max_value)
{
  if(root==NULL) return true;
  if(root->data>min_value && root->data<=max_value && Isbstutil(root->left,min_value,root->data)&&Isbstutil(root->right,root->data,max_value))
    return true;
  else 
   return false;  
}
bool Isbst(Node *root)
{
  return Isbstutil(root,INT_MIN,INT_MAX);
} 
Node *insert_node(int n)
{
  temp = new Node;
  temp->data=n;
  temp->left=NULL;
  temp->right=NULL;
  return temp;
}
int main()
{
    cout<<"Check binary search tree:\n";
    // Construct binary tree
    root = insert_node(6);
    root->left = insert_node(4);
    root->right = insert_node(9);
    root->left->left = insert_node(3);
    root->left->right = insert_node(5);
    root->left->left->left = insert_node(2);
    root->left->left->right = insert_node(4);
    root->right->left = insert_node(8);
    root->right->right = insert_node(10);
    root->right->left->left = insert_node(7);
    cout<<Isbst(root);
    //display(root);
    return 0;
}

