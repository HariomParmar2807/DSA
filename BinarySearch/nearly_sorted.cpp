// find an element in nearly sorted array
#include<bits/stdc++.h>
using namespace std;

int find_element(int arr[],int start,int end,int ele)
{
    while(start<=end)
    {
       int mid=(start+(end-start)/2);
       if(arr[mid]==ele)
         return mid;
       else if(mid-1>=start&&arr[mid-1]==ele)  
         return (mid-1);
       else if(mid+1<=end&&arr[mid+1]==ele)
         return (mid+1);
       else
       {
           if(ele<arr[mid])
             end=mid-2;
           else 
             start=mid+2;  
       }     
    }
    return -1;
}
int main()
{
    int n,ele;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
       cin>>arr[i];
    cout<<"element=";cin>>ele;    
    cout<<find_element(arr,0,n-1,ele);
    return 0;   
}