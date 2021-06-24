// Longest common substring 
/*#include<bits/stdc++.h>
using namespace std;

int SCS(string str1,string str2,int n,int m)
{
    if(n==0)
	  return m;
	if(m==0)
	  return n;
	else if(str1[n-1]==str2[m-1])
	  return 1+SCS(str1,str2,n-1,m-1);
	else
	  return min(1+SCS(str1,str2,n-1,m),1+SCS(str1,str2,n,m-1));	      
}
int main()
{
	string str1,str2;
	cin>>str1>>str2;
	cout<<SCS(str1,str2,str1.length(),str2.length());
	return 0;
}*/
//M-2
// remove the LCS
#include<bits/stdc++.h>
using namespace std;
int dp[100][1000];
int LCS(string str1,string str2,int n,int m)
{
    if(n==0||m==0)
	 return 0;
    if(dp[n][m]!=-1)
     return dp[n][m];
	else if(str1[n-1]==str2[m-1])
	  return dp[n][m]= 1+LCS(str1,str2,n-1,m-1);
	else
	  return dp[n][m]=max(LCS(str1,str2,n-1,m),LCS(str1,str2,n,m-1));	      
}
int main()
{
    memset(dp,-1,sizeof(dp));
	string str1,str2;
	cin>>str1>>str2;
	int n=str1.length();
	int m=str2.length();
	int len_lcs=LCS(str1,str2,n,m);
	cout<<((n+m)-len_lcs)<<"\n";
	// print the scs
	string str="";
	int i=n,j=m;
	while(i>0&&j>0)
	{
		if(str1[i-1]==str2[j-1]){
		  str+=str1[i-1];
          i--;j--;}
		else if(dp[i-1][j]>dp[i][j-1])
		{
			str+=str1[i-1];
			i--;
		}  
		else
		{
			str+=str2[j-1];
			j--;
		}
		
	}
	reverse(str.begin(),str.end());
	cout<<str;
	return 0;
}
// Print the shortest common supersequence
