// factorization into prime numbers
#include<bits/stdc++.h>
using namespace std;

/*void factorization(int n)
{
    vector<int>res;
	for(int i=2;i*i<=n;i++)
	{
		while(n%i==0)
		{
			res.push_back(i);
			n/=i;
		}
	}
	if(n!=1)
	  res.push_back(n);
	for(auto it:res)
	  cout<<it<<" ";  
}*/

// Factorization by minimum prime numbers
vector<int> minimum_prime(int n)
{
	vector<int>min_prime(n+1,0);
	for(int i=2;i*i<=n;i++)
	{
		if(min_prime[i]==0){
			for(int j=i*i;j<=n;j+=i)
			{
				if(min_prime[j]==0)
				  min_prime[j]=i;
			}
		}
	}
   for(int i=2;i<=n;i++)
   {
	   if(min_prime[i]==0)
	     min_prime[i]=i;
   }
   return min_prime;	
}
void factorization(int n)
{
	vector<int>res;
	vector<int>min_prime = minimum_prime(n);
	while(n!=1){
	  res.push_back(min_prime[n]);
	  n/=min_prime[n];}
	for(auto it:res)
	  cout<<it<<" "; 
}
int main()
{
	int n;cin>>n;
	factorization(n);
	return 0;
}