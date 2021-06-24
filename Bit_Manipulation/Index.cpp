#include<bits/stdc++.h>
using namespace std;

vector<long long > solve(int n,int q,vector<int>x,vector<int>query)
{
	vector<long long>ans;
	map<int,int>mp;
	for(int i=0;i<n;++i)
	{
		mp[x[i]]++;
	}
	for(int i=0;i<q;i++)
	{
		auto it = mp.lower_bound(query[i]);
		int val1 = (*it).second;
		it = mp.upper_bound(query[i]);
		int val2 = (*it).second;
		ans.push_back(max(val1,val2));
	}
	return ans;
}
int main()
{
	int n,q,val;
	cin>>n>>q;
	vector<int>x;
	vector<int>queries;
	for(int i=0;i<n;i++)
    {
		cin>>val;
		x.push_back(val);
	}
	for(int i=0;i<q;i++)
	{
		cin>>val;
        queries.push_back(val);
	}
	vector<long long >ans = solve(n,q,x,queries);
	for(auto it : ans)
	  cout<<it;
	return 0;
}