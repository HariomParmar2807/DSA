// longest Increasing subsequence
#include<bits/stdc++.h>
using namespace std;

int LIS(int arr[],int n)
{
	int dp[n+1],max_count=0;
	dp[0]=0;
	int k=1;
	vector<int>v1,v2;
	while(k<=n)
	{
		int count=1;
		int i=k;
		int j=i+1;
		v1.push_back(arr[i-1]);
		while(j<=n)
		{
			if(arr[j-1]>arr[i-1]){
				v1.push_back(arr[j-1]);
			  count++;
			  i=j;
			 }
			j++;  
		}
		if(count>max_count)
		{
			v2.clear();
			max_count=count;
			for(auto it:v1)
			 v2.push_back(it);
			v1.clear(); 
		}
		  dp[k]=max_count; 
	  k++;	  
	}
	cout<<"Prit the longest increasing subsequenc-";
	for(auto it:v2)
	 cout<<it<<" ";
	cout<<"\n"; 
	return dp[n];
}
int main()
{
	int n;cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	  cin>>arr[i];
	cout<<LIS(arr,n);
	return 0;  
}