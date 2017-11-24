#include<bits/stdc++.h>
using namespace std;

static int t = 0;

void dfs_visit(vector<int> adj[], char color[], int pie[], int u, int d[], int f[], list<pair<int, int> > &l) {
        color[u] = 'y';
        d[u] = ++t;
        cout<<u<<" ";
        vector<int>::iterator it;
        for(it = adj[u].begin(); it != adj[u].end(); ++it) {
           // cout<<"\n"<<"i = "<<*it;
            if(color[*it] == 'r') {
                pie[*it] = u;
                dfs_visit(adj, color, pie, *it, d, f, l);
            }
        }

        color[u] = 'b';
        f[u] = ++t;
        l.push_front(make_pair(u, f[u]));
}

void dfs_visit1(vector<int> adj[], int u, bool vis[]) {
    vis[u] = true;
    cout<<u<<" ";
    vector<int>::iterator it;
    for(it = adj[u].begin(); it != adj[u].end(); ++it) {
        int v = *it;
        if(!vis[v]) {
            dfs_visit1(adj, v, vis);
        }
    }
}

void graph_traversal(int size ,vector<int> adj[], int v[]) {
    //cout<<"size: "<<length<<endl;
    char color[size];
    int pie[size];
    int d[size];
    int f[size];
    list<pair<int, int> > l;
    memset(d, 0, sizeof(d));
    memset(f, 0, sizeof(f));

    for(int i = 0; i < size; i++) {
        color[v[i]] = 'r';
        //cout<<"color set: "<<v[i]<<endl;
        pie[v[i]] = v[i];
    }

    int s = v[0];
    pie[s] = s;

    dfs_visit(adj, color, pie, s, d, f, l);

    for(int i = 0; i < size; i++) {
        if(color[v[i]] == 'r') {
            if(adj[v[i]].size() == 0) {
                pie[v[i]] = v[i];
                continue;
            }
            dfs_visit(adj, color, pie, v[i], d, f, l);
        }
    }

    //loop for single nodes
    for(int i = 0; i < size; i++) {
        if(color[v[i]] == 'r') {
            color[v[i]] = 'b';
            d[v[i]] = ++t;
            f[v[i]] = ++t;
        }
    }

    //transpose of graph
    vector<int> adjt[size+1];
    for(int i = 0; i < size; i++) {
        for(vector<int>::iterator it = adj[v[i]].begin(); it != adj[v[i]].end(); ++it) {
                adjt[*it].push_back(v[i]);
        }
    }


    cout<<"Connected components are: \n";
    bool visited[size];
    memset(visited, false, sizeof(visited));
    //traverse list of finish times in descending order
    for(lit = l.begin(); lit != l.end(); lit++) {
        int u = lit->first;
        if(!visited[u]) {
            dfs_visit1(adjt, u, visited);
            cout<<endl;
        }
    }
}


int main() {
    /* Graph edge list
        1-->2
        1-->4
        2-->3
        2-->4
        4-->5
        5-->2
        5-->3
    */

    int V = 5;
    int vert[] = {1,2,3,4,5};
    vector<int> adj[V+1];

    adj[1].push_back(2);
    adj[1].push_back(4);
    adj[2].push_back(3);
    adj[2].push_back(4);
    adj[4].push_back(5);
    adj[5].push_back(2);
    adj[5].push_back(3);

    graph_traversal(V, adj, vert);

}

