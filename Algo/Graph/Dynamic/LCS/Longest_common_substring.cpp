// Longest common substring 
#include<bits/stdc++.h>
using namespace std;

int res,dp[100][1000];
int Longest_substring(string str1,string str2,int n,int m)
{
	//static int res=0;
	if(n==0 || m==0)
	  return 0;
	if(dp[n][m]!=-1)
	  return dp[n][m];  
	Longest_substring(str1,str2,n-1,m);
	Longest_substring(str1,str2,n,m-1);  
	if(str1[n-1]==str2[m-1]){
	  dp[n][m]=1+Longest_substring(str1,str2,n-1,m-1);
      res = max(res,dp[n][m]);
	  return dp[n][m];}
	else
	  return dp[n][m]=0;
	  
}
int main()
{
	memset(dp,-1,sizeof(dp));
	string str1,str2;
	cin>>str1>>str2;
	Longest_substring(str1,str2,str1.length(),str2.length());
	cout<<res;
	return 0;
}
// using tabulation
// Longest common substring 
/*#include<bits/stdc++.h>
using namespace std;

int Longest_substring(string str1,string str2,int n,int m)
{
    int res=0;
	int dp[n+1][m+1];
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			if(i==0||j==0)
			  dp[i][j]=0;
			else if(str1[i-1]==str2[j-1])
			{
                dp[i][j]=1+dp[i-1][j-1];
				res=max(res,dp[i][j]);
			}
			else 
			   dp[i][j]=0;  
		}
	}
return res;  
}
int main()
{
	string str1,str2;
	cin>>str1>>str2;
	cout<<Longest_substring(str1,str2,str1.length(),str2.length());
	return 0;
}*/ 