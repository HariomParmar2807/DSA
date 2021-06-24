// build max heap as well as heap sort
#include<bits/stdc++.h>
using namespace std;

void max_heapify(int *arr,int i,int n)
{
	
	int left = 2*i+1;
	int right = 2*i+2;
	int largest=i;
	if(left<n&&arr[left]>arr[i])
	  largest = left;
	if(right<n&&arr[right]>arr[largest])
	  largest = right;
	if(largest!=i)
	{
		swap(arr[i],arr[largest]);
		max_heapify(arr,largest,n);
	}    
	
  }
void max_heap(int arr[],int n)
{
	for(int i=n/2;i>=0;i--)
	 max_heapify(arr,i,n);
}
void heap_sort(int arr[],int n)
{
	int heap_Size=n-1;
	for(int i=n-1;i>=0;i--)
	{
		swap(arr[0],arr[i]);
		max_heapify(arr,0,i);		
	}
}
int main()
{
	int n;cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	  cin>>arr[i];
	max_heap(arr,n);
	heap_sort(arr,n); 
	for(int i=0;i<n;i++)
	 cout<<arr[i]<<" ";
	return 0;  
}