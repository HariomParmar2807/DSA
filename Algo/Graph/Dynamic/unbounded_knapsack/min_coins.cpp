#include<bits/stdc++.h>
using namespace std;

int dp[100][1000];
int Min_coin(int coin[],int n,int sum)
{
   if(n==0)
     return INT_MAX-1;
   if(sum==0)
     return 0;
   if(dp[n][sum]!=-1)
     return dp[n][sum];
   else if(coin[n-1]>sum)
     return dp[n][sum]=Min_coin(coin,n-1,sum);
   else
     return dp[n][sum]=min(Min_coin(coin,n-1,sum),1+Min_coin(coin,n,sum-coin[n-1]));     
}
int main()
{
  memset(dp,-1,sizeof(dp));
  int n,sum;cin>>n;
  int coin[n];
  for(int i=0;i<n;i++)
     cin>>coin[i];
  cin>>sum;
  cout<<Min_coin(coin,n,sum);
  return 0;   
}