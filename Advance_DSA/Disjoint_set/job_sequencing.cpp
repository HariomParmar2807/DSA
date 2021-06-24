// Job Sequencing problem solve using Disjoint set data structure
#include<bits/stdc++.h>
using namespace std;

class Job
{
  public:
  char id;
  int deadline;
  int profit;
};
class Disjset
{
  public:
     int *parent,data;
  Disjset(int m)
  {
     parent = new int[m+1];
     data=m;
     make_set();
  }
  void make_set()
  {
      for(int i=0;i<=data;i++)
       parent[i]=i;
  }
  int find(int x)
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
  void Union(int u,int v)
  {
      parent[v]=u; // update the greatest available free slot to u
  }
};
bool cmp(Job a,Job b)
{
    return (a.profit>b.profit);
}
int Maximum_deadline(Job arr[],int n)
{
    int ans = INT_MIN;
    for(int i=0;i<n;i++)
      ans = max(ans,arr[i].deadline);
    return ans;  
}
void print_scheduling(Job arr[],int n)
{
    int max_profit = 0;
    // sorts profit in decresing order
    sort(arr,arr+n,cmp);
    int max_deadline = Maximum_deadline(arr,n);
    Disjset set(max_deadline);
    for(int i=0;i<n;i++)
    {
        int available_slot = set.find(arr[i].deadline);
        if(available_slot>0)
        {  set.Union(available_slot-1,available_slot);
        cout<<arr[i].id<<" ";
        max_profit += arr[i].profit;
        }  
    }
    cout<<"\n";
    cout<<"Maximum profit = "<<max_profit;
}
int main()
{
    int n;cin>>n;
    Job arr[n];
    for(int i=0;i<n;i++)
      cin>>arr[i].id>>arr[i].deadline>>arr[i].profit;
    print_scheduling(arr,n);
    return 0;
}
// worst case time complexity is 0(n)