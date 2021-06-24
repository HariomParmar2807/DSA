// Implementation of Breadth first traversal of binary tree
#include<bits/stdc++.h>
using namespace std;

struct Node{
    char data;
    Node *left;
    Node *right;
}*root=NULL,*temp;
void bfs(Node *root)
{
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {     
        Node *current = q.front();
        cout<<current->data<<" ";
        if(current->left!=NULL) q.push(current->left);
        if(current->right!=NULL) q.push(current->right);
        q.pop();
    }
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
    cout<<"Level order traversal implementation:\n";
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
    bfs(root);
    return 0;
}
