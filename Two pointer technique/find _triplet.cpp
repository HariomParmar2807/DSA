// find a triplet in which sum of two equals to third element 
#include<bits/stdc++.h>
using namespace std;

void find_triplet(int arr[],int n)
{
	sort(arr,arr+n,greater<int>());
	for(int i=0;i<n-2;i++)
	{
		int l=i+1,r=n-1;
		while(l<r){
		if(arr[l]+arr[r]==arr[i]){
		  cout<<arr[l]<<" "<<arr[r]<<" "<<arr[i]<<"\n";
		  return;}
        else if(arr[l]+arr[r]>arr[i])
		  l++;
		else
		  r--;
		}				  		
	}
	cout<<"No triplet found\n";
}
int main()
{
	int n;cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	  cin>>arr[i];
	find_triplet(arr,n);
	return 0;  
}