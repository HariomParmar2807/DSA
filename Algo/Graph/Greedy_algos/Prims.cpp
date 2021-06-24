// Implementation of prims algoritham using adjacency list
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ipair;
void add_Vertex(vector<ipair>adj[],int u,int v,int w)
{
    adj[u].push_back(make_pair(w,v));
    adj[v].push_back(make_pair(w,u));
}
int Prims(vector<ipair>adj[],int V)
{
    int min_wt=0;
    // min_heap by priority queue
    priority_queue<ipair,vector<ipair>,greater<ipair>> pq;
    int src=0;
    // initialize all keys to INFINITY
    vector<int>key(V,INT_MAX);
    // Initialize all vertex not included in mst
    vector<int>inMst(V,false);
    // Initialize All adjacent
    vector<int>adjacent(V,-1);
    pq.push(make_pair(0,src));
    key[src]=0;
    while(!pq.empty())
    {
        int x=pq.top().second;
        pq.pop();

        inMst[x]=true;
        // check adjacent vertex
        for(auto it:adj[x])
        {
            int y = it.second;
            int weight = it.first;

            if(inMst[y]==false && key[y]>weight)
            {
                key[y]=weight;
                pq.push(make_pair(key[y],y));
                adjacent[y]=x;
            }
        }
    }
    cout<<"Path is:\n";
    for(int i=1;i<V;i++){
      min_wt += key[i];
      cout<<adjacent[i]<<"-"<<i<<"\n";}
      
   return min_wt;   
}
int main()
{
    int V,E,u,v,w;cin;cin>>V>>E;
    vector<ipair> adj[V];
    while(E--){
        cin>>u>>v>>w;
        add_Vertex(adj,u,v,w);
    }
    int min_wt=Prims(adj,V);
    cout<<"Minimum weight="<<min_wt;
    return 0;
}