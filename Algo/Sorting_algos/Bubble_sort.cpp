// Implementation of bubble sort in optimized way
#include<bits/stdc++.h>
using namespace std;
void Bubble_sort(int arr[],int n)
{
    bool s;
    for(int i=0;i<n-1;i++)
    {
        s = false;
        for(int j=0;j<n-i-1;j++)
        {
           if(arr[j]>arr[j+1]){
            swap(arr[j],arr[j+1]);  
            s = true;}
        }
        if(s==false)
         break;
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
    Bubble_sort(arr,n);
    return 0;  
}