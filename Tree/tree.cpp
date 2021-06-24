#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
}*root,*temp;
void display()
{
    while(root!=NULL)
    {
        cout<<root->data<<"\n";
        root = root->left;
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
    root = insert_node(1);
    root->left = insert_node(2);
    root->right = insert_node(3);
    root->left->left = insert_node(4);
    display();
    return 0;
}
