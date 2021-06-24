// find minimum number of partition such that every string in partition is pallindrome
/*#include<bits/stdc++.h>
using namespace std;
int dp[100][100];
bool isPallindrome(string str,int i,int j)
{
	if(i>=j)
	 return true;
	while(i<j)
	{
		if(str[i]!=str[j])
		  return false;
		i++;
		j--;  
	} 
	return true;
}
int Pallindrome_partitioning(string str,int i,int j)
{
	if(i>=j) // empty string or single chracter string no need to partitioning
	   return 0;
	if(isPallindrome(str,i,j))  // if string is pallindrome
	  return 0; 
	if(dp[i][j]!=-1)
	  return dp[i][j];
	int temp=INT_MAX;  
	for(int k=i;k<j;k++)
    {
		temp=min(temp,(1+Pallindrome_partitioning(str,i,k)+Pallindrome_partitioning(str,k+1,j)));
	}
	return temp;
}
int main()
{
	memset(dp,-1,sizeof(dp));
	string str;cin>>str;
	cout<<Pallindrome_partitioning(str,0,str.length()-1);
	return 0;
}*/
// More optimization if each subtree check indivisually
#include<bits/stdc++.h>
using namespace std;
int dp[100][100];
bool isPallindrome(string str,int i,int j)
{
	if(i>=j)
	 return true;
	while(i<j)
	{
		if(str[i]!=str[j])
		  return false;
		i++;
		j--;  
	} 
	return true;
}
int Pallindrome_partitioning(string str,int i,int j)
{
	if(i>=j) // empty string or single chracter string no need to partitioning
	   return 0;
	if(isPallindrome(str,i,j))  // if string is pallindrome
	  return 0; 
	if(dp[i][j]!=-1)
	  return dp[i][j];
	int min=INT_MAX,left,right;  
	for(int k=i;k<j;k++)
    {
		if(dp[i][k]!=-1)
		  left = dp[i][k];
		else{ 
		  left = Pallindrome_partitioning(str,i,k);
          dp[i][k]=left;}
		if(dp[k+1][j]!=-1)
		  right = dp[k+1][j];
		else{ 
		  right = Pallindrome_partitioning(str,k+1,j);
          dp[k+1][j]=right;}
		int temp=1+left+right;
		if(temp<min)
		   min=temp;  
	}
	return min;
}
int main()
{
	memset(dp,-1,sizeof(dp));
	string str;cin>>str;
	cout<<Pallindrome_partitioning(str,0,str.length()-1);
	return 0;
}