// o(n^2)
// Implementation of 0/1 knapsack problem
#include<bits/stdc++.h>
using namespace std;

void knapsack(int n,int profit[],int weight[],int w)
{
	int dp[n+1][w+1];
	for(int i=0;i<=n;i++)
	  for(int j=0;j<=w;j++)
	     dp[i][j]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=w;j++)
		{
			if(j>=weight[i-1])
			  dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight[i-1]]+profit[i-1]);
			else
			  dp[i][j]=dp[i-1][j];
		    
		}		
	}
    cout<<"Maximum profit="<<dp[n][w]<<"\n";
	cout<<"Elements that selected for max_profit:\n";
	//cout<<dp[1][2];
	int i=n,j=w;
	while(i>0 && j>=0)
	{
		//cout<<i<<" "<<j<<"\n";
		if(dp[i][j]==dp[i-1][j])
		  cout<<i<<"=0\n";
		  
		else
		{
		   cout<<i<<"=1\n";
		   j=j-weight[i-1];
		}
		 --i; 
		//cout<<i<<j<<endl; 
	}
}
int main()
{
	int n,max_capacity;cin>>n;
	int profit[n];
	int weight[n];
	for(int i=0;i<n;i++)
	  cin>>profit[i];
	for(int i=0;i<n;i++)
	  cin>>weight[i];
	cin>>max_capacity;
	knapsack(n,profit,weight,max_capacity); 
	return 0;   
}