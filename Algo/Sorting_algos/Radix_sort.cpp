#include<bits/stdc++.h>
using namespace std;
#define size 10
//#define for(int i=0;i<n;i++) fr(i,n)
void Count_sort(int arr[],int n,int pos)
{
    int count_arr[size];int sort[n];
    memset(count_arr,0,sizeof(count_arr));
    // counting the bits
    for(int i=0;i<n;i++)
     ++count_arr[(arr[i]/pos)%10];
    // modified count array
    for(int i=1;i<size;i++)
     count_arr[i] += count_arr[i-1];
    // sorting arrays
    for(int i=n-1;i>=0;i--) //traverse frome right to left to maintain stability
      sort[--count_arr[(arr[i]/pos)%10]] = arr[i];
    // copy the element in array
    for(int i=0;i<n;i++)
      arr[i] = sort[i];
     
}
void Radix_sort(int arr[],int n)
{
  int max = *max_element(arr,arr+n);
  // Call the count sort
  for(int pos=1;max/pos;pos*=10)
   Count_sort(arr,n,pos);
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
    Radix_sort(arr,n);
    print_array(arr,n);
    return 0;
}