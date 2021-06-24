#include<bits/stdc++.h>
using namespace std;
//int count=0;

void Merge(int arr[],int l,int mid,int h)
{
   // int count = 0;
    int n1 = mid-l+1;
    int n2 = h-mid;
    int t1[n1],t2[n2];// create temp arrays 
    for(int i=0;i<n1;i++)
      t1[i] = arr[l+i];
    for(int j=0;j<n2;j++)
      t2[j] = arr[mid+1+j];
    int i=0,j=0,k=l;
    while(i<n1 && j<n2)
    {
        if(t1[i]<=t2[j])
        {arr[k]=t1[i];i++;}
        else
        {
            arr[k]=t2[j];
            j++;//count++;
        }
      k++;  
    }    
  while(i<n1)
  {
      arr[k]=t1[i];
      i++;
      k++;
      //count++;
  }
  while(j<n2)
  {
      arr[k]=t2[j];
      j++;
      k++;
  }
 }
void Merge_sort(int arr[],int l,int h)
{
  if(l<h)
  {
      int mid = (l+h)/2;
      Merge_sort(arr,l,mid);
      Merge_sort(arr,mid+1,h);
      Merge(arr,l,mid,h);
  }
}
void print_array(int arr[],int n)
{
    cout<<"Sorted Array = ";
    for(int i=0;i<n;i++)
      cout<<arr[i]<<" ";

}
int main()
{
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
      cin>>arr[i];
    Merge_sort(arr,0,n-1);
    print_array(arr,n);
    return 0;  
}