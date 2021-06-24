// Implementation of segment tree and solutioin of query update problem
#include<bits/stdc++.h>
using namespace std;
int mid_value(int ss,int se){return ((ss+se)/2);}

int build_tree_allocation(int arr[],int ss,int se,int *st,int si)
{
    if(ss==se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
    int mid = mid_value(ss,se);
    st[si] = build_tree_allocation(arr,ss,mid,st,2*si+1) + build_tree_allocation(arr,mid+1,se,st,2*si+2);// sum stores in node value
    return st[si];
}
int *build_tree(int arr[],int n)
{
 int height = (int)(ceil(log2(n)));
 int max_size = 2*(int)pow(2,height)-1;
 // Allocation of memory
 int *st = new int[max_size];
 build_tree_allocation(arr,0,n-1,st,0);
 return st;
}
int query_util(int *st,int ss,int se,int l,int r,int si)
{
    if(l<=ss && r>=se)
     return st[si];
    if(r<ss ||se<l) 
     return 0;
    int mid = mid_value(ss,se);
     return query_util(st,ss,mid,l,r,2*si+1) + query_util(st,mid+1,se,l,r,2*si+2);
}  
int query(int arr[],int *st,int l,int r,int n)
{
 
  if (l < 0 || r> n-1 || l > r) 
    { 
        cout<<"Invalid Input";
        return -1; 
    } 
  
    return query_util(st, 0, n-1, l, r, 0); 
}
void update_value_util(int *st,int ss,int se,int i,int diff,int si)
{
    if(i>se ||i<ss)
     return;
    st[si] += diff;
    if(ss!=se)
    {
        int mid = mid_value(ss,se);
        update_value_util(st,ss,mid,i,diff,2*si+1);
        update_value_util(st,mid+1,se,i,diff,2*si+2);
    } 
}
void update_value(int arr[],int *st,int i,int new_value,int n)
{
   // int *st = build_tree(arr,n);
   if (i < 0 || i > n-1) 
	{ 
		cout<<"Invalid Input"; 
		return; 
	} 

    int diff = new_value - arr[i];
    arr[i]=new_value;
    update_value_util(st,0,n-1,i,diff,0);
}
int main()
{
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
      cin>>arr[i]; 
    int *st = build_tree(arr,n);
    /*for(int i=0;i<(2*n+5);i++)
    cout<<st[i]<<" ";
    cout<<endl;*/
    cout<<query(arr,st,1,3,n)<<endl;
    update_value(arr,st,1,10,n); 
    cout<<query(arr,st,1,3,n);
    return 0;
}