// find minimum subset sum difference 
#include<bits/stdc++.h>
using namespace std;

int dp[100][1000];
bool subset_sum(int arr[],int n,int sum)
{
    if(n==0 && sum!=0)
      return false;
    if(sum==0)
      return true;
    if(dp[n][sum]!=-1)
      return dp[n][sum];  
    else if(arr[n-1]>sum)
      dp[n][sum]=subset_sum(arr,n-1,sum);
    else
      dp[n][sum]=(subset_sum(arr,n-1,sum) || subset_sum(arr,n-1,sum-arr[n-1]));     
}
int main()
{
    memset(dp,-1,sizeof(dp));
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
       cin>>arr[i];
    int range=0;
    for(int i=0;i<n;i++)
      range += arr[i];  
    int minimum=INT_MAX; 
    //cout<<range<<"\n"; 
    for(int i=0;i<=range/2;i++){
      if(subset_sum(arr,n,i))
        minimum=min(minimum,(range-2*i));}
      cout<<minimum;
      return 0;    
    }