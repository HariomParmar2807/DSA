//Implementation of dfs by adjacency matrix
#include<bits/stdc++.h>
using namespace std;
#define V 5

void dfs_search(int src,bool visited[],int adj[][V])
{
	cout<<src<<"->";
	visited[src]=true;
	for(int i=0;i<V;i++){
	  if(adj[src][i]==1 && (!visited[i]))
	    dfs_search(i,visited,adj);}
  
}
int main()
{
	int adj[V][V];
	for(int i=0;i<V;i++)
	  for(int j=0;j<V;j++)
	    cin>>adj[i][j];
	int src;
    cout<<"Enter Source=";
	cin>>src;	
	bool visited[V]={false};
	dfs_search(src,visited,adj);
	return 0;	
}