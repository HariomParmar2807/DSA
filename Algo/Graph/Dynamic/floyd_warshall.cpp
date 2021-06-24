// Implement floyd warshall algo to find shortest path b/w All pairs using adjacency matrix
#include<bits/stdc++.h>
using namespace std;
// #define INF 99999
void floyd_warshall(int *adj[],int n)
{
  for(int k=0;k<n;k++)
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
          adj[i][j] = min(adj[i][j],adj[i][k]+adj[k][j]);
 //cout<<adj[4][2];
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++){
        if(adj[i][j] == 99999)
          cout<<"INF"<<" "; 
        else
           cout<<adj[i][j]<<" "; 
    }      
   cout<<endl;
  }          
      
}
int main()
{
    int n;cin>>n;
    int *adj[n];
    for(int i=0;i<n;i++)
      adj[i] = new int[n];
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
         cin>>adj[i][j];
    floyd_warshall(adj,n);
    return 0;     
}