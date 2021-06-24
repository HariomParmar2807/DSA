// Implement Memory Efficient Doubly Link List
// insertion at begning
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *npx;
}*head=NULL,*temp;
Node *xor_op(Node *a,Node *b)
{
     return ( Node*) ((uintptr_t) (a) ^ (uintptr_t) (b)); 
}
Node *create_node(int n)
{
  temp = new Node;
  temp->data = n;
  temp->npx = NULL;
  return temp;
}
void insert_beg(int n)
{
    temp = create_node(n);
    if(head==NULL) {head = temp;head->npx = NULL;}//cout<<head->data<<endl;}
    else
    {
       temp->npx = head;
       head->npx = xor_op(temp,head->npx);
       head = temp;
      // cout<<head->data<<endl;
    }
    
}
void display()
{
    Node *current = head;
    Node *prev = NULL;
    Node *next;
    while(current!=NULL)
    {cout<<current->data<<" ";
     next = xor_op(prev,current->npx);
     prev = current;
     current = next;
    }
}

int main()
{
  cout<<"Doubly link list representation\n";
  insert_beg(5);
  insert_beg(6);
  insert_beg(7);
  display();
  return 0;
}