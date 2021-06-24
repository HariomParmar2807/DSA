// Longest pallindrome substring(LPS)
#include<bits/stdc++.h>
using namespace std;

int LPS(string str1,string str2,int n)
{
	int dp[n+1][n+1];
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(i==0||j==0)
			  dp[i][j]=0;
			else if(str1[i-1]==str2[j-1])
			  dp[i][j]=1+dp[i-1][j-1];
			else 
			 dp[i][j]=max(dp[i-1][j],dp[i][j-1]);    
		}
	}
  string lcs="";
	cout<<"Longest Pallindrome subsequence = ";
	int i=n,j=n;
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
    return dp[n][n];
}
int main()
{
	string str2;getline(cin,str2);
	string str1=str2;
	reverse(str2.begin(),str2.end());
	int len=LPS(str1,str2,str1.length());
	cout<<"Minimum Deletion="<<str1.length()-len<<"\n";
	cout<<"Minimum Insertion=Deletion="<<str1.length()-len;
    return 0;
}