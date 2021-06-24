// To find inorder successor(next higher value) in o(h)time
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
}*root,*temp;
Node *Find(Node *root,int n)
{
  if(n==root->data) return root;
  else if(n<root->data) Find(root->left,n);
  else 
    Find(root->right,n);
    
}
Node *Find_min(Node *root)
{
    if(root==NULL) return NULL;
    while(root->left!=NULL)
    {
        root = root->left;
    }
    return root;
}
Node *Get_successor(Node *root,int n)
{
  // search the node-o(h)
  Node *current = Find(root,n);
  if(current==NULL) return NULL;
  // node has  right subtree
  if(current->right!=NULL)
    return Find_min(current->right);
  // case 2: Node has no right subtree
  else
  {
    Node *successor = NULL;
    Node *ancestor = root;
    while(ancestor!=current)
    {
      if(current->data<ancestor->data){
       successor = ancestor;// so far this is the deepest ancestor in which current node is in left
       ancestor = ancestor->left;}
      else
          ancestor = ancestor->right;
    }
    return successor;
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
    cout<<"tree representation\n";
    root = insert_node(15);
    root->left = insert_node(10);
    root->right = insert_node(20);
    root->left->left = insert_node(8);
    root->left->right = insert_node(12);
    root->left->left->left = insert_node(6);
    root->left->right->left = insert_node(11);
    root->right->left = insert_node(17);
    root->right->right = insert_node(25);
    root->right->left->left = insert_node(16);
    root->right->right->right = insert_node(27);
    int n;cout<<"Ender data which find successor=";
    cin>>n;
    Node *Inorder_successor = Get_successor(root,n);
    cout<<Inorder_successor->data;
    //display();
    return 0;
}
