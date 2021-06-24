// find minimum cost path in 2d matrix
#include<bits/stdc++.h>
using namespace std;

int min_cost_path(int **grid,int n,int m)
{
    // find first column 
    for(int i=1;i<n;i++)
      grid[i][0] += grid[i-1][0];
    for(int i=1;i<m;i++)
       grid[0][i] += grid[0][i-1];
    for(int i=1;i<n;i++)
      for(int j=1;j<m;j++)
        grid[i][j] += min(grid[i-1][j-1],min(grid[i-1][j],grid[i][j-1]));
    return grid[n-1][m-1];
}
int main()
{ 
   int n,m;cin>>n>>m;
   int *grid[m];
   for(int i=0;i<n;i++)
    grid[i]=new int[m];
   for(int i=0;i<n;i++)
     for(int j=0;j<m;j++)
        cin>>grid[i][j]; 
   cout<<min_cost_path(grid,n,m);
   return 0; 
}