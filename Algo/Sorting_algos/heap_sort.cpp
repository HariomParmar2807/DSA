// Sorting the numbers by heap sort algoritham
#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[],int n,int i)
{
    int root = i;
    int l = 2*i+1;
    int r = 2*i+2;

    if(l<n && arr[l]>arr[root])
      root=l;
    if(r<n && arr[r]>arr[root])
      root=r;
    if(root!=i) 
    {
        swap(arr[i],arr[root]);
        heapify(arr,n,root);
    }    
}
void heap_sort(int arr[],int n)
{
    for(int i=n/2-1;i>=0;i--) // heapify in reverse to maintain the stability
      heapify(arr,n,i);
    for(int i=n-1;i>=0;i--)
    {
      swap(arr[0],arr[i]);
      heapify(arr,i,0); // reduced heap size
    }  
}
void print_array(int arr[],int n)
{
    for(int i=0;i<n;i++)
      cout<<arr[i]<<" ";
}
int main()
{
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
      cin>>arr[i];
    heap_sort(arr,n);
    print_array(arr,n);
    return 0;
}