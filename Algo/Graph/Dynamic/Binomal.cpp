// find binomial coefficient using dynamic programming
#include<bits/stdc++.h>
using namespace std;

/*int binomial_coff(int n,int k)
{
    int dp[n+1][k+1];

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=min(i,k);j++)
        {
            if(j==0||j==i)
              dp[i][j]=1;
            else
              dp[i][j]=dp[i-1][j-1]+dp[i-1][j];    
        }
    }
    return dp[n][k];
}*/
// to reduce the space complexity
//c(n,k)=c(n-1,k-1)+c(n-1,k)
int binomial_coff(int n,int k)
{
   int c[n+1];
   memset(c,0,sizeof(c));
   c[0]=1;
   for(int i=0;i<=n;i++)
    for(int j=min(i,k);j>0;j--)
      c[j]+=c[j-1];
    return c[k]; 
}     
int main()
{
    int n,k;cin>>n>>k;
    cout<<binomial_coff(n,k);
    return 0;
}