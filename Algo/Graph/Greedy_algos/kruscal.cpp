// Implementation of Minimum spanning tree using kruscal's algoritham
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pairs;
class Graph
{
    public:
    int V,E;vector<pair<int,pairs>> edges;
    Graph(int V,int E)
    {
        this->V = V;
        this->E = E;
    }
    void add_Edge(int u,int v,int w)
    {
       edges.push_back({w,{u,v}});
    }
   int Kruscal();
};
class Disjset
{
    public:
    int *parent,*rank,n;
    Disjset(int n)
    {
        parent = new int[n+1];
        rank = new int[n+1];
        this->n = n;
        make_set();
    }
    void make_set()
    {
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
            rank[i]=0;
        }
    }
    int find(int x)
    {
       
       if(parent[x]!=x)
         parent[x] = find(parent[x]);
       return parent[x];  
    }
    void Union(int x,int y)
    {
        if(rank[x]>rank[y])   // x and y is already parent
         parent[y] = x;
        else if(rank[x]<rank[y])
         parent[x] = y;
        else
        {
            parent[y] = x;
            rank[x]++;
        }
          
    }
};
// member fn of graph class
int Graph::Kruscal()
{
    int min_wt = 0;
    sort(edges.begin(),edges.end()); // default sort with first element of sort
    /*for(auto itr = edges.begin();itr!=edges.end();itr++)
       cout<<itr->first<<" ";*/
    //cout<<endl;   
    Disjset set(V);
    cout<<"path is:"<<endl;
    for(vector<pair<int,pairs>>:: iterator it=edges.begin();it!=edges.end();it++)
    {
        int x = it->second.first;
        int y = it->second.second;
       
        int set_x = set.find(x);
        int set_y = set.find(y);
       
        if(set_x!=set_y)
        {
            cout<<x<<" - "<<y<<" "<<"Weight="<<it->first<<"\n";
            min_wt += it->first;
            set.Union(set_x,set_y);
        }
        //cout<<min_wt<<" ";
    }
   return min_wt;
}
int main()
{
    int V,E,u,v,w;cin>>V>>E;
    Graph graph(V,E);

    while(E--)
    {
       cin>>u>>v>>w;
       graph.add_Edge(u,v,w);
    }
    int min_wt = graph.Kruscal();
    cout<<endl;
    cout<<"Minimum weight of graph="<<min_wt;
   return 0; 
}