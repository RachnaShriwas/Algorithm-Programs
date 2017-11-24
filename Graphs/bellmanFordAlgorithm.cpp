//SSSP
#include<bits/stdc++.h>
using namespace std;
struct edge
{
    int u,v,w;
};
void bellmanFord(vector<struct edge> &graph,int n,int src)
{
    int e = graph.size();
    vector<int> dist(n,INT_MAX);
    dist[src] = 0;
    int pie[n];
    pie[src] = src;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<e;j++)
        {
            int u = graph[j].u;
            int v = graph[j].v;
            int w = graph[j].w;
            //checking dist[u]!=INT_MAX in case of overflow
            if(dist[u]!=INT_MAX && dist[u] + w < dist[v])
            {
                dist[v] = w + dist[u];
                pie[v] = u;
            }
        }
    }
    for(int j=0;j<e;j++)
    {
        int u = graph[j].u;
        int v = graph[j].v;
        int w = graph[j].w;
        //checking dist[u]!=INT_MAX in case of overflow
        if(dist[u]!=INT_MAX && dist[u] + w < dist[v])
        {
            cout<<"Contains negative weight cycle\n";
        }
    }

    cout<<"Shortest path from "<<src+1<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"to "<<i+1<<": "<<dist[i]<<"\n";
    }
    cout<<endl;

    cout<<"Parent: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<i+1<<": "<<pie[i]+1<<"\n";
    }
    cout<<endl;

    cout<<"Shortest Paths(in reverse order):\n";
    for(int i=0;i<n;i++)
    {
        cout<<"Path to "<<i+1<<" : ";
        int j=i;
        while(j!=src)
        {
            cout<<j+1<<" ";
            j = pie[j];
        }
        cout<<src+1;
        cout<<endl;
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    vector<edge> graph;
    for(int i=0;i<e;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        struct edge ed;
        ed.u = u;
        ed.v = v;
        ed.w = w;
        graph.push_back(ed);
    }
    int src = 0;
    bellmanFord(graph,n,src);
    return 0;
}
/*
test case:
5 8
0 1 -1
0 2 4
1 2 3
1 3 2
1 4 2
3 1 1
3 2 5
4 3 -3
*/
