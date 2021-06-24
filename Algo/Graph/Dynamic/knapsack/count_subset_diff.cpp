// count of subset sum with given difference = Target sum
#include<bits/stdc++.h>
using namespace std;

int dp[100][1000];
int count_subset(int arr[],int n,int sum)
{
    if(n==0&&sum!=0)
      return 0;
    if(sum==0)
      return 1;
    if(dp[n][sum]!=-1)
      return dp[n][sum];  
    else if(arr[n-1]>sum)
      return dp[n][sum]=count_subset(arr,n-1,sum);
    else
      return dp[n][sum]=(count_subset(arr,n-1,sum-arr[n-1])+count_subset(arr,n-1,sum));
      
}
int main()
{
    memset(dp,-1,sizeof(dp));
    int n,sum=0,diff;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
      cin>>arr[i];
     sum+=arr[i];}
    cin>>diff;
    int subset_sum = (diff+sum)/2;
    cout<<count_subset(arr,n,subset_sum);
    return 0;
}