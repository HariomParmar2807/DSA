// Implementation of dfs by adjacency list using stack
#include<bits/stdc++.h>
using namespace std;

stack<int>stk;
void dfs_search(list<int>adj_list[],int V,int src,bool visited[])
{
    //bool visited[V]={false};
    stk.push(src);
    while(!stk.empty())
    {
      int s = stk.top();
    
      if(!visited[s]){
        cout<<s<<" ";
        visited[s]=true;}
      // adjacent node added to stack
      for(auto it:adj_list[s])
      {
        if(!visited[it]){
          stk.push(it);
          dfs_search(adj_list,V,it,visited);}
      }
      stk.pop();
      return;
    }
}
void addEdge(list<int>adj_list[],int u,int v)
{
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
}
int main()
{
    int V;cin>>V;
    list<int> adj_list[V+1];
    int E;cin>>E;
    while(E--)
    {
        int u,v;
        cin>>u>>v;
        addEdge(adj_list,u,v);
    }
    int src;
    cout<<"Enter source=";cin>>src;
    bool visited[V+1] = {false};
    dfs_search(adj_list,V,src,visited);
    return 0;
}