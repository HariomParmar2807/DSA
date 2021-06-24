// Implementation of insertion sort algoritham
#include<bits/stdc++.h>
using namespace std;
void Insertion_sort(int arr[],int n)
{
    int j,key;
    for(int i=1;i<n;i++)
    {
        key = arr[i];
        j = i-1;
        while(j>=0 && arr[j]>key)
        {
          arr[j+1] = arr[j];
          j--;
        }
        arr[j+1] = key;
    }
    for(int i=0;i<n;i++)
     cout<<arr[i]<<" ";
}
int main()
{
     int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
      cin>>arr[i];
    Insertion_sort(arr,n);
    return 0;  
}