// Implementation of range sum query by segment tree(tree with array implementation)
#include<bits/stdc++.h>
using namespace std;
const int N = 10000;
int tree[2*N];
/*struct Node
{
    int data;
    Node *left;
    Node *right;
}*head=NULL,*temp;
Node *build_tree()// Implementation of segment tree
{
 
}
void get_sum(int arr[],int l,int r)
{
   
}*/
void build_tree(int arr[],int n)
{
 for(int i=0;i<n;i++)
 tree[n+i] = arr[i];

 // build tree in o(n) time
 for(int i=n-1;i>0;i--)
 tree[i] = tree[2*i] + tree[2*i+1];
}
void update_value(int p,int value,int n)
{
  tree[p+n] = value;
  p = p+n;

  // update the value of parents
  for(int i=p;i>1;i>>=1)
  tree[i>>1] = tree[i] + tree[i^1];
}
int get_sum(int l,int r,int n)
{
  int res = 0;
  for(l+=n,r+=n;l<r;l>>=1,r>>=1)
  {
    if(l&1)
      res += tree[l++];
    if(r&1)
      res += tree[--r];  
  }
  return res;
}
int main()
{
  int n,q;cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
   cin>>arr[i];
  /*while(q--)
  {
      int c,l,r,x;cin>>c;
      if(c==0){
       cin>>l>>r;
       get_sum(arr,l,r);}
      else{
       cin>>x;
       update_value(arr,x,c); 
  }*/
  build_tree(arr,n);
  cout<<get_sum(1,3,n)<<endl;
  update_value(2,1,n);
   cout<<get_sum(1,3,n);
  return 0;
}