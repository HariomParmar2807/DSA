// Implementation of disjoint set data structure by union and find function
// Improvement tree performance by apply union by rank and path compression
#include<bits/stdc++.h>
using namespace std;
class Disjset
{
    int data,*parent,*rank;
    public:
    Disjset(int n)
    {
        rank = new int[n];
        parent = new int[n];
        data=n;
        make_set();
    }
    void make_set()
    {
      for(int i=0;i<data;i++)
       parent[i]=i;
    }
    int find(int x) // path compression
    {
        if(parent[x]==x)
          return x;
        else
        {
          int result = find(parent[x]);
          parent[x]=result;
          return result;
        }
          
    }
    void Union(int x,int y)  // union by rank
    {
        int xset = find(x);
        int yset = find(y);

        if(xset==yset)
         return ;
        if(rank[xset]<rank[yset])
         parent[xset]=yset;
        else if(rank[xset]>rank[yset])
         parent[yset]=xset;
        else
        {
            parent[yset]=xset;
            rank[xset]++;
        } 
           
    }
};
int main()
{
  vector<int>universe={1,2,3,4,5};
  Disjset set(5);
  set.Union(0,2);
  set.Union(1,3);

  if(set.find(0)==set.find(3))
    cout<<"yes";
  else
    cout<<"NO";
    return 0;
}