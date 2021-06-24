// Implementatio of scheduling problem solution based on greedy algorithams
#include<bits/stdc++.h>
using namespace std;

int Optimal(int n,float p[],float t[])
{
     pair<float,int>s[n];
    for(int i=0;i<n;i++){
     float start = p[i]/t[i];
     //cout<<start<<endl;
     //float end = i;
     s[i] = make_pair(start,i);}
    sort(s,s+n);
    /*for( int i=0;i<n;i++)
     {
         cout<<s[i].first<<" ";
         cout<<s[i].second<<"\n";
     }*/
    int c=0,f=0;
    for(int i=n-1;i>=0;i--)
    {
        c += t[s[i].second];
        f += p[s[i].second]*c;
    }   
    return  f;
}
int main()
{
    int n;cin>>n;
    float p[n],t[n];
    for(int i=0;i<n;i++)
      cin>>p[i]>>t[i];
    cout<<Optimal(n,p,t);
    return 0;
}