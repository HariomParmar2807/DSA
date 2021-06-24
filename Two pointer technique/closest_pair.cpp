// find closest pair within two sorted array that's sum is closest to given number
#include<bits/stdc++.h>
using namespace std;

void closest_pair(int s1[],int s2[],int n,int m,int x)
{
    int diff = INT_MAX;
    int left_res=0,right_res=0;
    int l=0,r=m-1;
    while(l<n && r>=0)
    {
       if(abs(s1[l]+s2[r]-x)<diff)
       {
         left_res = s1[l];
         right_res = s2[r];
         diff = abs(s1[l]+s2[r]-x);
       }
       if(s1[l]+s2[r]>x)
         r--;
       else
         l++;
    }
    cout<<left_res<<" "<<right_res;
}
int main()
{
    int n,m;cin>>n>>m;
    int s1[n],s2[n];
    for(int i=0;i<n;i++)
      cin>>s1[i];
    for(int i=0;i<m;i++)
      cin>>s2[i];  
    int x;cin>>x;  
    closest_pair(s1,s2,n,m,x);
    return 0;  
}