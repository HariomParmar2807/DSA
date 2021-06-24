// Implementation of breadth first search using queue by adjacency list
// Implementation of bfs for chractres
#include<bits/stdc++.h>
using namespace std;

queue<char>que;
void bfs_search(list<char>adj_list[],int V,char src)
{
   
   bool visited[V+1]={false};
  // visited[src]=true;
   que.push(src);
   while(!que.empty())
   {
       char q1 = que.front();
       int q2 = q1-'A';
       if(!visited[q2])
       {
           cout<<char(q2+65)<<" ";
           visited[q2]=true;
       }
       for(auto it:adj_list[q2]){
         if(!visited[it-'A'])
           que.push(it);}
      que.pop();   
   }
}
void addEdge(list<char>adj_list[],char u,char v)
{
    u=toupper(u);v=toupper(v);
    int i=u-'A';int j=v-'A';
    adj_list[i].push_back(v);
    adj_list[j].push_back(u);
}
int main()
{
    int V;cin>>V;
    list<char>adj_list[V+1];
    int E;cin>>E;
    while(E--)
    {
        char u,v;cin>>u>>v;
        addEdge(adj_list,u,v);
    }
    char src;
    cout<<"Enter source=";cin>>src;
    src = toupper(src);
    bfs_search(adj_list,V,src);
    return 0;
}