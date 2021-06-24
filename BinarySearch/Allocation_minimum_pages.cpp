// Allocate minimimum number of pages amongst student
// find max_no of pages of all student and find minimum in this
#include<bits/stdc++.h>
using namespace std;

bool isValid(int arr[],int n,int k,int mid)
{
    int student=1;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum>mid)
        {
            student++;
            sum=arr[i];
        }

        if(student>k)
         return false;
    }
    return true;
}
int Min_pages(int arr[],int start,int end,int n,int k)
{
    if(n<k)
      return -1;
      int res=-1;
    while(start<=end)
    {
        
        int mid=(start+(end-start)/2);
        //cout<<mid;
        if(isValid(arr,n,k,mid))
        {
           res=mid;
           end=mid-1;
        }
        else
         start=mid+1;
        
    } 
    return res; 
}

int main()
{
    int n,k,sum=0;cin>>n;
    int arr[n]; // array of pages of books
    for(int i=0;i<n;i++)
       cin>>arr[i];
    cout<<"Number of students=";  
    cin>>k;
    int max_ele = *max_element(arr,arr+n);
    for(int i=0;i<n;i++)
     sum+=arr[i];
   cout<<Min_pages(arr,max_ele,sum,n,k);
    return 0; 
}