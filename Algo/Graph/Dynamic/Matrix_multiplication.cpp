// find order in which we multiply matrices so 
// minimum cost of multiplication is minimum in o(n^3)
#include<bits/stdc++.h>
using namespace std;
int main()
{
    
    int n;cin>>n;
    int dim[n];
    for(int i=0;i<n;i++)
      cin>>dim[i];
    int m[n][n]={0};
    int s[n][n]={0};
    for(int diff=0;diff<n-1;diff++)
    {
        for(int i=1;i<n-diff;i++)
        {
            int min=INT_MAX;;
            int j=i+diff;
            for(int k=i;k<j;k++){
              m[i][j]=m[i][k]+m[k+1][j]+dim[i-1]*dim[k]*dim[j];
            if(m[i][j]<min){
              min = m[i][j];
              s[i][j]=k;}
            m[i][j]=min;   }               
        }
    }
  cout<<s[1][n-1];
  return 0;
}