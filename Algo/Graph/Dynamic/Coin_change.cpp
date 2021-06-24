// coin change problem in dynamic programming 
#include<bits/stdc++.h>
using namespace std;

int find_ways(int arr[],int m,int n)
{
	int dp[n+1];
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	for(int i=0;i<=m;i++)
	  for(int j=arr[i];j<=n;j++)
	     dp[j]+=dp[j-arr[i]];
    return dp[n];		 
}
int main()
{
	int m,n;cin>>m;
	int arr[m];
	for(int i=0;i<m;i++)
	  cin>>arr[i];
	cin>>n;  
	cout<<find_ways(arr,m,n);
	return 0;   
}