// Implementation of adjacency list of graph representation using vector
/*#include<bits/stdc++.h>
using namespace std;
#define V 5
void addEdge(vector<int>adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void print_list(vector<int>adj[])
{
    for(int i=0;i<V;i++)
    {
        cout<<i;
      for(auto it : adj[i]) //range based for loop statement
        cout<<"->"<<it;
      cout<<"\n";  
    }
}
int main()
{
  vector<int> adj[V];
    addEdge(adj, 0, 1); 
    addEdge(adj, 0, 4); 
    addEdge(adj, 1, 2); 
    addEdge(adj, 1, 3); 
    addEdge(adj, 1, 4); 
    addEdge(adj, 2, 3); 
    addEdge(adj, 3, 4); 
  print_list(adj);
  return 0;
}*/

// Implementation of Adjacency list using linked list
#include<bits/stdc++.h>
using namespace std;

void addEdge(list<int>adj_list[],int u,int v)
{
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
}
void print_list(list<int>adj_list[],int V)
{
    for(int i=0;i<V;i++)
    {
       cout<<i<<"->";
       for(auto it:adj_list[i])
        cout<<it<<" ";
        cout<<"\n";
    }
    
}
int main()
{
    int V=5;
    list<int> adj_list[V];
    addEdge(adj_list,0,1);
    addEdge(adj_list,0,4);
    addEdge(adj_list,1,4);
    addEdge(adj_list,1,2);
    addEdge(adj_list,1,3);
    addEdge(adj_list,2,3);
    addEdge(adj_list,3,4);
    print_list(adj_list,V);
    return 0;
} 