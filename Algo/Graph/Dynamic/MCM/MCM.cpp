// Matrix chain multiplication(min cost multiplication)
#include<bits/stdc++.h>
using namespace std;

int dp[100][100],s[100][100];
int MCM(int d[],int i,int j)
{
	if(i>=j)
	  return 0;
	if(dp[i][j]!=-1)  
	  return dp[i][j];
    static int min=INT_MAX;  
    for(int k=i;k<j;k++){
		 int temp =(MCM(d,i,k)+MCM(d,k+1,j)+d[i-1]*d[k]*d[j]);
         if(temp<min)
		 {
			 min=temp;
			 s[i][j]=k;
		 }
	}		 
    return dp[i][j]=min;		 
}
int main()
{
	memset(dp,-1,sizeof(dp));
	memset(s,-1,sizeof(s));
	int n;cin>>n;
	int d[n];
	for(int i=0;i<n;i++)
	  cin>>d[i];
	cout<<MCM(d,1,n-1)<<"\n";
	// Association order of array
	for(int i=0;i<n;i++){
	  for(int j=0;j<n;j++)
        cout<<s[i][j]<<" ";
	  cout<<"\n";
	}	
	return 0;
}