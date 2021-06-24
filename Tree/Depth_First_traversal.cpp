// Preorder,Postorder,Inorder traversal implementation of binary tree
#include<bits/stdc++.h>
using namespace std;

struct Node{
    char data;
    Node *left;
    Node *right;
}*root,*temp;
void Preorder(Node *root)
{
    if(root==NULL) return;
    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}
void Inorder(Node *root)
{
    if(root==NULL) return;
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}
/*void Inorder(Node *root) //without recursion
{
  Node *current = root;
  stack<Node*>s;
  bool done = 0;
  while(!done)
  {
      if(current!=NULL)
      {
          s.push(current);
          current = current->left;
      }
      else
      {
         if(!s.empty())
         {
             cout<<s.top()->data<<" ";
             current = s.top()->right;
             s.pop();
         }
        else
           done = 1;
        
      }
      
  }
  
     
}*/
void Postorder(Node *root)
{
    if(root==NULL) return;
    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data<<" ";
}
Node *insert_node(char c)
{
  temp = new Node;
  temp->data=c;
  temp->left=NULL;
  temp->right=NULL;
  return temp;
}
int main()
{
    cout<<"Level order traversal implementation\n";
    // Construct binary tree
    root = insert_node('F');
    root->left = insert_node('D');
    root->right = insert_node('J');
    root->left->left = insert_node('B');
    root->left->right = insert_node('E');
    root->left->left->left = insert_node('A');
    root->left->left->right = insert_node('C');
    root->right->left = insert_node('G');
    root->right->right = insert_node('K');
    root->right->left->right = insert_node('I');
    root->right->left->right->left = insert_node('H');
    cout<<"Preorder traversal:";
    Preorder(root);
    cout<<endl;
    cout<<"Inorder traversal:";
    Inorder(root);
    cout<<endl;
    cout<<"Postorder traversal:";
    Postorder(root);
    return 0;
}
