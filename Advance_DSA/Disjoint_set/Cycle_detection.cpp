//Detection of cycle in undirected graph
//Apply union by rank and path compression which worst time complexity is o(logn)
#include<bits/stdc++.h>
using namespace std;
class Edge
{
public:
int src,dest;
};
class Graph
{
  public:
  int V,E;
  Edge *edge;
};
Graph *Create_graph(int V,int E)
{
  Graph *graph = new Graph;
  graph->V=V;
  graph->E=E;
  graph->edge = new Edge[E];// array of edges uses in graph
  return graph;
}
int find(int *parent,int x)// path compression
{
  if(parent[x]==-1)
   return x;
  else
   {
     int result = find(parent,parent[x]);
     parent[x]=result;
     return result;
   }
   
}
void Union(int *rank,int *parent,int x,int y) // Union by rank
{
  
  int xset = find(parent,x);
  int yset = find(parent,y);
  if(xset==yset)
   return;
  if(rank[xset]<rank[yset])
    parent[xset]=yset;
  else if(rank[xset]>rank[yset])
    parent[yset]=xset;
  else
  {
    parent[xset]=yset;
    rank[yset]++;
  }
 
}
bool iscycle(Graph *graph)
{
  int *parent = new int[graph->V];
  memset(parent,-1,graph->V*sizeof(int));
  int *rank = new int[graph->V];
  memset(rank,0,graph->V*sizeof(int));

  for(int i=0;i<graph->E;i++)
  {
    int x = find(parent,graph->edge[i].src);
    int y = find(parent,graph->edge[i].dest);
    /*for(int i=0;i<graph->V;i++)
     cout<<parent[i];
    cout<<"\n"; */
    if(x==y)
     return true;
    
    Union(rank,parent,x,y); 
  }
 return false;
}
void add_Edge(Graph *graph,int u,int v)
{
  graph->edge[u].src = u;
  graph->edge[u].dest = v;
}
int main()
{
  int V,E;cin>>V>>E;
  Graph *graph = Create_graph(V,E);

// add Edge one by one

  while(E--)
  {
    int u,v;cin>>u>>v;
    add_Edge(graph,u,v);
  }  
  //cout<<graph->edge[0].dest;
  if(iscycle(graph))
    cout<<"Graph contain cycle\n";
  else
    cout<<"Graph doesn't contain cycle\n";
   
      return 0;
}