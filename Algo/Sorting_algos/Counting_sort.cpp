// Sort the array using counting sort
#include<bits/stdc++.h>
using namespace std;

void print_array(int arr[],int n)
{
    for(int i=0;i<n;i++)
      cout<<arr[i]<<" ";
}
void Counting_sort(int arr[],int n)
{
    int sort[n];
    int h = *max_element(arr,arr+n);
    int size = h+1;
    int count_arr[size]; // temp arrays
    memset(count_arr,0,sizeof(count_arr));
    for(int i=0;i<n;i++)
      ++count_arr[arr[i]];
    // Modified count array
    for(int i=1;i<size;i++)
      count_arr[i] += count_arr[i-1];
    // sorted array
     for(int i=n-1;i>=0;i--) // traverse from right to left for maintain stability
       sort[--count_arr[arr[i]]] = arr[i];
     
    // copy the element in array
    for(int i=0;i<n;i++)
     arr[i] = sort[i];
     print_array(arr,n);
}

int main()
{
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
      cin>>arr[i];
    Counting_sort(arr,n);
    //print_array(arr,n);
    return 0;  
}