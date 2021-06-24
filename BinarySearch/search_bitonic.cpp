// Search an element in bitonic array
#include<bits/stdc++.h>
using namespace std;

int max_ele(int arr[],int start,int end)
{
    int n=end+1;
    while(start<=end)
    {
        int mid=(start+(end-start)/2);
        if(mid>0&&mid<n-1)
        {
            if(arr[mid]>arr[mid-1]&&arr[mid]>arr[mid+1])
              return mid;
            else if(arr[mid-1]>arr[mid])
              end=mid-1;
            else
              start=mid+1;                
        }
        else if(mid==0)
        {
            if(arr[0]>arr[1])
              return 0;
            else
              return 1;              
        }
        else
        {
             if(arr[n-1]>arr[n-2])
               return n-1;
             else
               return n-2;               
        }
        
    }
}
int Binary_search_increasing(int arr[],int start,int end,int ele)
{
    while(start<=end)
    {
        int mid = (start+(end-start)/2);
        if(arr[mid]==ele)
          return mid;
        else if(arr[mid]>ele)
          end=mid-1;
        else
          start=mid+1;            
    }
    return -1;
}
int Binary_search_decreasing(int arr[],int start,int end,int ele)
{
    while(start<=end)
    {
        int mid=(start+(end-start)/2);
        if(arr[mid]==ele)
          return mid;
        else if(arr[mid]>ele)
          start=mid+1;
        else
          end=mid-1;        
    }
    return -1;
}
int main()
{
    int n,x;cin>>n;
    int arr[n];   // bitonic array
    for(int i=0;i<n;i++)
       cin>>arr[i];
    cin>>x;   
    int peak = max_ele(arr,0,n-1);
    int ans = Binary_search_increasing(arr,0,peak-1,x);
    if(ans==-1)
      cout<<Binary_search_decreasing(arr,peak,n-1,x);
    else
     cout<<ans;
    return 0;
}