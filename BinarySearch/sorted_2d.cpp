// search an element in row and column wise sorted array
#include<bits/stdc++.h>
using namespace std;

pair<int,int> Sorted_2d(int **arr,int n,int m,int key)
{
    pair<int,int>p;
    int i=0,j=m-1;
    while(i>=0&&i<n&&j>=0&&j<m)
    {
        if(arr[i][j]==key)
        {
            p.first=i;
            p.second=j;
            return p;
        }
        else if(arr[i][j]>key)
         j--;
        else 
         i++;  
    }
    p.first=p.second=-1;
    return p;
}
int main()
{
    int n,m,key;cin>>n>>m;
    int *arr[n];
    for(int i=0;i<n;i++)
     arr[i]=new int[m];
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
        cin>>arr[i][j];
    cin>>key;    
    pair<int,int>ans=Sorted_2d(arr,n,m,key);
    cout<<ans.first<<" "<<ans.second;
    return 0;      
}