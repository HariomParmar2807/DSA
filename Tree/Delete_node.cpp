#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
}*root=NULL,*temp;
Node *Find_min(Node *root)
{
    while(root->left!=NULL)
    {
        root = root->left;
    }
    return root;
}
Node *delete_node(Node *root,int value)
{
  if(root==NULL) return root;
  else if(value<root->data) root->left = delete_node(root->left,value);
  else if(value>root->data)  root->right = delete_node(root->right,value);
  else 
  {
    if(root->left==NULL && root->right==NULL) // if node is leaf node or have no child
    {
        free(root);
        root = NULL;
     }
    else if(root->left==NULL) // If node contain only right child
    {
        temp = root;
        root = root->right;
        free(temp);
    }
    else if(root->right==NULL) // if node contain only left child
    {
        temp = root;
        root = root->left;
        free(temp);
    }
    else
    {
      temp  = Find_min(root->right);
      root->data = temp->data;
      root->right = delete_node(root->right,temp->data);
    }
  }
  return root;
}
void display(Node *root)
{
    while(root!=NULL)
    {
        cout<<root->data<<"\n";
        root = root->right;
    }
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
    root = insert_node(6);
    root->left = insert_node(4);
    root->right = insert_node(9);
    root->left->left = insert_node(3);
    root->left->right = insert_node(5);
    root->left->left->left = insert_node(2);
    root->left->left->left->left = insert_node(1);
    root->left->left->right = insert_node(4);
    root->right->left = insert_node(8);
    root->right->right = insert_node(10);
    root->right->left->left = insert_node(7);
    delete_node(root,9);
    display(root);
    return 0;
}