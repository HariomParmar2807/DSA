#include<bits/stdc++.h>
using namespace std;
  
 struct Node
 {
     int data;
     Node *left;
     Node *right;
 }*root=NULL,*temp,*root_1;
 queue<Node*>q;
 Node *create_node()
 {
   int num;
   cout<<"Enter key_value=";cin>>num;
   temp = new Node;
   temp->data = num;
   temp->left = NULL;
   temp->right = NULL;
   return temp;
 }
 void display()
 {
     if(root == NULL) return;
     cout<<root->data<<"\n";
 }
 void insert_key()
 {
    
    if(root==NULL) {root = create_node();q.push(root);}//cout<<q.front()->data<<endl;}
    else
    {
        //cout<<q.front()->data<<endl;
        //root_1 = root;
        temp = create_node();

            Node *current = q.front();
            //cout<<current->data;
            if(current->left==NULL){
               current->left = temp;q.push(current->left);
               if(temp->data > current->data)
                  swap(temp->data,current->data);
                /*while(root!=current){
                   if(current->data > root->data){
                     swap(current->data,root->data);
                     root = root->left;}
                     }*/
                  cout<<current->data<<endl;}//cout<<temp->data;}
               
            else if(current->right==NULL){//cout<<"harry";
            current->right = temp;q.push(current->right);
            if(temp->data > current->data)
                swap(temp->data,current->data);cout<<current->data<<endl;
                q.pop();}//cout<<current->data;}
                              
    }
    
 }
 
 int main()
 {
   cout<<"Binary heap representation::"<<endl;
   while(1){
   cout<<"1.Insert key\n";
   cout<<"2.Delete the key\n";
   cout<<"3.display the maximum element\n";
   cout<<"4.Exit\n";
   int ch;
   cout<<"Enter your choice=";cin>>ch;
   switch(ch)
   {
       case 1:insert_key();
              break;
       //case 2:delete_key();
           //  break;
       case 3:display();
             break;
       case 4:exit(0);
             break;
       default:
          cout<<"wrong choice";                    
   }
   }
   return 0;
 }