// subset sum problem
#include<bits/stdc++.h>
using namespace std;

int dp[100][1000];
/*bool subset_sum(int arr[],int n,int sum)
{
    if(n==0&&sum!=0)
      return false;
    if(sum==0)
      return true;    // empty subset possible
    if(dp[n][sum]!=-1)
      return dp[n][sum];
    else if(arr[n-1]>sum)
      return dp[n][sum]=subset_sum(arr,n-1,sum);
    else
      return dp[n][sum]=(subset_sum(arr,n-1,sum) || subset_sum(arr,n-1,sum-arr[n-1]));    

}*/
// count of subset sum with given sum
int subset_sum(int arr[],int n,int sum)
{
    if(n==0&&sum!=0)
      return 0;
    if(sum==0)
      return 1;
    if(dp[n][sum]!=-1)
      return dp[n][sum];
    else if(arr[n-1]>sum)
      return dp[n][sum]=subset_sum(arr,n-1,sum);
    else 
      return dp[n][sum]=(subset_sum(arr,n-1,sum)+subset_sum(arr,n-1,sum-arr[n-1]));        
}
int main()
{
    memset(dp,-1,sizeof(dp));
    int n,sum;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
       cin>>arr[i];
    cin>>sum;
    cout<<subset_sum(arr,n,sum);
    return 0;  
}

// Equal sum partitioning problem
/*int main()
{
   memset(dp,-1,sizeof(dp));
   int n;cin>>n;
   int arr[n];
   for(int i=0;i<n;i++)
     cin>>arr[i];
   int sum=0;
   for(int i=0;i<n;i++)
     sum += arr[i];
   if(sum%2==0)  
     cout<<subset_sum(arr,n,(sum/2));
   else
     cout<<"0";
   return 0;     
}*/