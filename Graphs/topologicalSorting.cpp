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

//    cout<<"\nParent vertices: "<<endl;
//    for(int i = 0; i < size; i++) {
//        cout<<"pie of "<<v[i]<<" is: "<<pie[v[i]]<<endl;
//    }
//
//    cout<<"\nVisit Time: "<<endl;
//    for(int i = 0; i < size; i++) {
//        cout<<"Visit time of "<<v[i]<<" is: "<<d[v[i]]<<endl;
//    }
//
//    cout<<"\nFinish Time: "<<endl;
//    for(int i = 0; i < size; i++) {
//        cout<<"Finish Time of "<<v[i]<<" is: "<<f[v[i]]<<endl;
//    }

    cout<<"\nTopological Sort: "<<endl;
    list<pair<int,int> >::iterator lit;
    for(lit = l.begin(); lit != l.end(); lit++) {
        cout<<lit->first<<" "<<lit->second<<endl;
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

