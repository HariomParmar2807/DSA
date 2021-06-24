// Implementation of Quick sort algo 
#include<bits/stdc++.h>
using namespace std;
#define infinity 99999
int Partition(int arr[],int l,int h)
{
    int pivot = arr[l],i=l,j=h;
    while(i<j){
    do
    {
        i++;
    } while (arr[i]<=pivot);
    do
    {
        j--;
    } while (arr[j]>pivot);
    if(i<j)
     swap(arr[i],arr[j]);
    } 
    swap(arr[l],arr[j]);
  return j;
}
void Quick_sort(int arr[],int l,int h)
{
    if(l<h){
    int pi = Partition(arr,l,h);
    Quick_sort(arr,l,pi);
    Quick_sort(arr,pi+1,h);}
    
}
void print_array(int arr[],int n)
{
    for(int i=0;i<n;i++)
     cout<<arr[i]<<" ";
}
int main()
{
    int n;cin>>n;
    int arr[n+1];
    for(int i=0;i<n;i++)
      cin>>arr[i];
    arr[n+1]=infinity;
    int l=0,h=n+1;   
    Quick_sort(arr,l,h);
    print_array(arr,n);  
    return 0;
}