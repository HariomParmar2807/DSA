// Implement bellman-ford using dynamic approach
#include<bits/stdc++.h>
using namespace std;

struct Edge
{
   
   int src,dest,weight;
};
class Graph
{
    public:
    int V,E;
    struct Edge *edge;
};
Graph *create_graph(int V,int E)
{
    Graph *graph = new Graph;
    graph->V = V;
    graph->E=E;

    graph->edge = new Edge[E];
    return graph;
}
void add_Edge(Graph *graph,int i,int u,int v,int w)
{
    graph->edge[i].src = u;
    graph->edge[i].dest = v;
    graph->edge[i].weight = w;
}
void bellman_ford(Graph *graph,vector<int>dist,int src)
{
    int V = graph->V;
    dist[src]=0;
   for(int i=0;i<=V-1;i++)
   {
     for(int j=0;j<graph->E;j++)
     {
         int u = graph->edge[j].src;
         int v = graph->edge[j].dest;
         int w = graph->edge[j].weight;
         
         if(dist[u]+w < dist[v] && dist[u]!=INT_MAX)
           dist[v] = dist[u]+w;
         //cout<<dist[v]<<"\n";
     }
    if(i==V-1){  
    for(int j=0;j<graph->E;j++)
     {
        int u = graph->edge[j].src;
        int v = graph->edge[j].dest;
        int w = graph->edge[j].weight;
        if(dist[u]+w < dist[v] && dist[u]!=INT_MAX)
        {cout<<"Negative weight cycle";
            return;}    
     }
    }
   } 
   cout<<"Shortest distance of all vertices:\n";
   for(int i=0;i<V;i++)
   cout<<i<<"\t\t"<<dist[i]<<"\n";
}
int main()
{
    int V,E,u,v,w;cin>>V>>E;
    Graph *graph = create_graph(V,E);
    for(int i=0;i<E;i++)
    {
        cin>>u>>v>>w;
        add_Edge(graph,i,u,v,w);
    }
    int src;
    cout<<"Enter source=";cin>>src;
    vector<int>dist(V,INT_MAX);
    bellman_ford(graph,dist,src);
     
    return 0;
}