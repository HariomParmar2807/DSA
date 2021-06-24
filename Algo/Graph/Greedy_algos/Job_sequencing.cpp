// Implement job sequencing problem solution using greedy method
#include<bits/stdc++.h>
using namespace std;

class Job
{
    public:
    char id;
    int deadline,profit;
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
    sort(arr,arr+n,cmp);
    int max_deadline = Maximum_deadline(arr,n);
    int result[max_deadline+1];
    bool slot[max_deadline+1];

    for(int i=0;i<=max_deadline;i++)
      slot[i]=false;
    for(int i=0;i<n;i++)
    {
        for(int j=(arr[i].deadline);j>0;j--)
        {
            if(!slot[j])
            {
                result[j]=i;
                slot[j]=true;
                break;
            }
        }

    }

    for(int i=0;i<=max_deadline;i++)
    {
        if(slot[i])
          cout<<arr[result[i]].id<<" ";
    }
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
// time complexity using greedy method is o(n*n)