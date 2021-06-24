// Implementation of Dijkstra's algoritham using min heap
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ipair;
void add_Vertex(vector<ipair>adj[],int u,int v,int w)
{
    adj[u].push_back(make_pair(w,v));
    adj[v].push_back(make_pair(w,u));
}
void Prims(vector<ipair>adj[],int V,int src)
{
   
    // min_heap by priority queue
    priority_queue<ipair,vector<ipair>,greater<ipair>> pq;
       // initialize all keys to INFINITY
    vector<int>dist(V,INT_MAX);
    // Initialize all vertex not included in mst
    vector<int>inMst(V,false);
    // Initialize All adjacent
    vector<int>adjacent(V,-1);
    pq.push(make_pair(0,src));
    dist[src]=0;
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

            if(dist[y] > dist[x] + weight)
            {
                dist[y]=dist[x]+weight;
                pq.push(make_pair(dist[y],y));
                
            }
        }
    }
    cout<<"Vertex distance from source "<<src<<":\n";
    for(int i=0;i<V;i++){
      cout<<i<<"\t\t"<<dist[i]<<"\n";}
      
   
}
int main()
{
    int V,E,u,v,w;cin;cin>>V>>E;
    vector<ipair> adj[V];
    while(E--){
        cin>>u>>v>>w;
        add_Vertex(adj,u,v,w);
    }
    cout<<"Enter source=";
    int src;cin>>src;
    Prims(adj,V,src);
    //cout<<"Minimum weight="<<min_wt;
    return 0;
}