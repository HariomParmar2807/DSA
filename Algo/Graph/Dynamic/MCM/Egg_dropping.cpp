// egg droping problem in which find minimum no of attempts to find critical floor in worst case from which egg will be brreak
// dynamic programming with optimisation
#include<bits/stdc++.h>
using namespace std;

int dp[100][100];
int Min_attempt(int e,int f)
{
    if(f==0||f==1||e==1)
      return f;
    if(e==0)
      return 0;
   
    if(dp[e][f]!=-1)
      return dp[e][f];
    int minimum=INT_MAX,low,high;
    for(int k=1;k<=f;k++)
    {
        minimum=min(minimum,1+max(Min_attempt(e-1,k-1),Min_attempt(e,f-k)));
       if(dp[e-1][k-1]!=-1)
           low=dp[e-1][k-1];
        else
        {
           low=Min_attempt(e-1,k-1);
           dp[e-1][k-1]=low;
        }
        if(dp[e][f-k]!=-1)
           high=dp[e][f-k];
        else
        {
           high=Min_attempt(e,f-k);
            dp[e][f-k]=high;
        }
         int temp=1+max(low,high); // maximum is for worst case
         minimum=min(minimum,temp);   
    }     
return dp[e][f]=minimum;
}
int main()
{
    memset(dp,-1,sizeof(dp));
    int e,f;cin>>e>>f;
    cout<<Min_attempt(e,f);
    return 0;
}