// unbounded knapsack
#include<bits/stdc++.h>
using namespace std;

int unbounded_knapsack(int wt[],int val[],int n,int w)
{
    int dp[n+1][w+1];
    for(int i=0;i<=n;i++)
    {
      for(int j=0;j<=w;j++)
      {
        if(i==0 || j==0)
         dp[i][j]=0;
         else if(wt[i-1]>j)
           dp[i][j]=dp[i-1][j];
         else
           dp[i][j]=max(dp[i-1][j],dp[i][j-wt[i-1]]+val[i-1]);
           
      }
    }
    return dp[n][w];
}
int main()
{
  int n,w;cin>>n;
  int wt[n],val[n];
  for(int i=0;i<n;i++)
    cin>>wt[i];
  for(int i=0;i<n;i++)
    cin>>val[i];
  cout<<"Max_weight=";cin>>w;
  unbounded_knapsack(wt,val,n,w);
  return 0;  
}