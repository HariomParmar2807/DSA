// Rod cutting problem
#include<bits/stdc++.h>
using namespace std;

int Rod_cutting(int wt[],int val[],int n,int w)
{
    int dp[n+1][w+1];
    for(int i=0;i<=n;i++)
    {
      for(int j=0;j<=n;j++)
      {
        if(i==0 || j==0)
         dp[i][j]=0;
         else if(wt[i-1]>j)
           dp[i][j]=dp[i-1][j];
         else
           dp[i][j]=max(dp[i-1][j],dp[i][j-wt[i-1]]+val[i-1]);
           
      }
    }
    return dp[n][n];
}
int main()
{
  int n,w;cin>>n;
  int length[n],price[n];
  for(int i=0;i<n;i++)
    cin>>length[i];
  for(int i=0;i<n;i++)
    cin>>price[i];
  cout<<Rod_cutting(length,price,n,n);
  return 0;  
}