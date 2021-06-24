// longest common subsequence using dynamic programming(tabulation)
/*#include<bits/stdc++.h>
using namespace std;
// for space optimization
int longest_subsequence(string str1,string str2)
{
	int m = str1.length();
	int n = str2.length();
	int dp[m+1][n+1];
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(i==0 || j==0)
			  dp[i][j]=0;
			else if(str1[i-1]==str2[j-1])
			  dp[i][j]=1+dp[i-1][j-1];
			else
			  dp[i][j]=max(dp[i-1][j],dp[i][j-1]);			    
		}
	}
	string lcs="";
	cout<<"Longest subsequence = ";
	int i=m,j=n;
	while(i>0 && j>0){
	if(str1[i-1]==str2[j-1]){
	  lcs += (str1[i-1]);
	  i--;j--;}
	else if(dp[i-1][j]>dp[i][j-1])
	   i--;
	else     
	   j--;  
	}
	reverse(lcs.begin(),lcs.end());
	cout<<lcs<<"\n";
	return dp[m][n];
}

int main()
{
	string str1,str2;
	cin>>str1>>str2;
	cout<<"Longest length="<<longest_subsequence(str1,str2);
	return 0;
}*/

// lcs using memoization
#include<bits/stdc++.h>
using namespace std;

int dp[100][1000];
int LCS(string str1,string str2,int n,int m)
{
  if(n==0 || m==0)
    return 0;
  if(dp[n][m]!=-1)
    return dp[n][m];  
  if(str1[n-1]==str2[m-1])
    return dp[n][m]=1+LCS(str1,str2,n-1,m-1);
  else
    return dp[n][m]=max(LCS(str1,str2,n-1,m),LCS(str1,str2,n,m-1));
      
}
int main()
{
  memset(dp,-1,sizeof(dp));
  string str1,str2;
  cin>>str1>>str2;
  cout<<LCS(str1,str2,str1.length(),str2.length())<<"\n";
  string lcs="";
	cout<<"Longest subsequence = ";
	int i=str1.length(),j=str2.length();
	while(i>0 && j>0){
	if(str1[i-1]==str2[j-1]){
	  lcs += (str1[i-1]);
	  i--;j--;}
	else if(dp[i-1][j]>dp[i][j-1])
	   i--;
	else     
	   j--;  
	}
	reverse(lcs.begin(),lcs.end());
	cout<<lcs<<"\n";
  return 0;
}