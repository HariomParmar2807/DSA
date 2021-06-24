// Find minimum element of given range by segment tree
#include<bits/stdc++.h>
using namespace std;
int mid_value(int s,int e){return (s+e)/2;}
int build_tree_util(int arr[],int *st,int ss,int se,int si)
{
    if(ss==se)
    {
        st[si]=arr[ss];
        return arr[ss];
    }
    int mid = mid_value(ss,se);
    st[si] = min(build_tree_util(arr,st,ss,mid,2*si+1) ,build_tree_util(arr,st,mid+1,se,2*si+2));
    return st[si];
}
int *build_tree(int arr[],int n)
{
    int h = (int)(ceil(log2(n)));
    int max_size = 2*(int)pow(2,h)-1;
    int *st = new int[max_size];
    build_tree_util(arr,st,0,n-1,0);
    return st;
}
int min_query_util(int *st,int ss,int se,int l,int r,int si)
{
    if(l<=ss && r>=se)
      return st[si];
    if(r<ss || l>se) 
      return INT_MAX;
    int mid = mid_value(ss,se);
      return  min(min_query_util(st,ss,mid,l,r,2*si+1),min_query_util(st,mid+1,se,l,r,2*si+2));   
}
int min_query(int arr[],int *st,int l,int r,int n)
{
   if (l < 0 || r> n-1 || l > r) 
    { 
        cout<<"Invalid Input";
        return -1; 
    } 
    return min_query_util(st,0,n-1,l,r,0);
}
int main()
{
    int n,q;cin>>n>>q;
    int arr[n];
    for(int i=0;i<n;i++)
      cin>>arr[i];
    int *st = build_tree(arr,n); 
    /*for(int i=0;i<(2*n+5);i++)
    cout<<st[i]<<" ";
    cout<<endl; */
    while(q--){
        int l,r;
        cout<<"Enter Range=";
        cin>>l>>r;
        cout<<min_query(arr,st,l,r,n)<<endl;
    }
    return 0;
}