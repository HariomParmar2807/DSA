// what is the min cost to convert string 1 to string 2
// operation :insert,remove and replace 
// All have equal cost;
#include<bits/stdc++.h>
using namespace std;

int Edit_distance(string str1,string str2,int m,int n)
{
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0)// if first string is empty insert all chracters of second string
             dp[i][j]=j;
            else if(j==0) // if second string is empty remove all chracter of first string 
             dp[i][j]=i;
            else if(str1[i-1]==str2[j-1]) // last chracter is match than ignore
              dp[i][j]=dp[i-1][j-1];
            else
             dp[i][j]=1+min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));              
        }
    }
    return dp[m][n];
}
int main()
{
    string str1,str2;
    cin>>str1>>str2;
    cout<<Edit_distance(str1,str2,str1.length(),str2.length());
    return 0;
}
// time complexity = o(m*n)
// space complexity = o(m*n)
// but if string length is more than space complexity is high
// so we use dp[2][str1.length()+1] bcz in row we only need of upper row and solve according to this (apply dp[i%2])