// Implement fractional knapsack problem using greedy approach
#include<bits/stdc++.h>
using namespace std;

typedef struct Container
{
    float profit;
    float weight;
    float profit_per_weight;
}C;
bool sortbyprofit(C a,C b)
{
    return (a.profit_per_weight>b.profit_per_weight);
}
int main()
{
    int n,max_capacity;cin>>n;
    float max_profit=0,fraction;
    C obj[n];
    for(int i=0;i<n;i++){
     cin>>obj[i].profit>>obj[i].weight;
     obj[i].profit_per_weight = obj[i].profit/obj[i].weight;}
    sort(obj,obj+n,sortbyprofit); 
    // Apply fractionl knapsack 
    cout<<"Enter maximum capacity of container=";
    cin>>max_capacity;
    int i=0;
    while(max_capacity>0 && i<n)
    {
        if(obj[i].weight<=max_capacity)
        {
            max_capacity -= obj[i].weight;
            max_profit += obj[i].profit;
            //cout<<max_capacity<<"\n";
        }
        else
        {
            fraction = max_capacity/obj[i].weight;
            max_capacity = 0;
            max_profit += fraction * obj[i].profit;
        }
      i++;  
    }
    cout<<max_profit;
    return 0; 
}