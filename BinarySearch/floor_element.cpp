// find floor of element in sorted array 
// floor defined in array is this if element is present than floor(ele)=ele
// if element is not present in array than floor(ele)=greatest element in array which is less than ele
#include<bits/stdc++.h>
using namespace std;

int ceil_element(int arr[],int start, int end,int ele)
{
    int res=-1;
    while(start<=end)
    {
        int mid = (start+(end-start)/2);
        if(arr[mid]==ele)
          return ele;
        else if(arr[mid]<ele)
          start=mid+1;
        else{
          res = arr[mid];
          end=mid-1;}
    }
    return res;
}
int floor_element(int arr[],int start, int end,int ele)
{
    int res=-1;
    while(start<=end)
    {
        int mid = (start+(end-start)/2);
        if(arr[mid]==ele)
          return ele;
        else if(arr[mid]<ele){
          res=arr[mid];
          start=mid+1;}
        else
          end=mid-1;
    }
    return res;
}

int main()
{
    int n,ele;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
       cin>>arr[i];
    cout<<"Element=";cin>>ele;
    cout<<"Floor of an element="<<floor_element(arr,0,n-1,ele)<<"\n";  
    cout<<"Ceil of an element="<<ceil_element(arr,0,n-1,ele);
    return 0;
}