// Implement of binary indexed tree to calcuate sum of first i elements
// update the value both in o(logn)time
#include<bits/stdc++.h>
using namespace std;

void updateBIT(int *BIT,int n,int index,int val)
{
    index++;
    while(index<=n)
    {
       BIT[index] += val;
       index += index & (-index); 
    }
}
int *construct_BIT(int arr[],int n)
{
    int *BIT = new int[n+1];
    for(int i=1;i<=n;i++)
      BIT[i]=0;
    for(int i=0;i<n;i++)
       updateBIT(BIT,n,i,arr[i]);
    
   return BIT;   
}
int get_sum(int *BIT,int index)
{
  int sum =0;
  index++;
  while(index>0)
  {
    sum += BIT[index];
    index -= index & (-index);
  }
  return sum;
}
int main()
{
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
      cin>>arr[i];
    int *BIT = construct_BIT(arr,n);
    //for(int i=1;i<=n;i++)
    // cout<<BIT[i]<<" ";
    cout<<get_sum(BIT,5)<<endl;
    arr[3] += 6; // arr[3]=9 so difference = 9-3=6
    updateBIT(BIT,n,3,6);
    cout<<get_sum(BIT,5);
    return 0;  
}