#include<bits/stdc++.h>
using namespace std;

void bfs_visit(vector<int> adj[], char color[], int pie[], queue<int> q) {
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        color[u] = 'b';
        cout<<u<<" ";

        vector<int>::iterator it;
        for(it = adj[u].begin(); it != adj[u].end(); ++it) {
           // cout<<"\n"<<"i = "<<*it;
            if(color[*it] == 'r') {
                q.push(*it);
                //cout<<"\n q size"<<q.size()<<endl;
                color[*it] = 'y';
                pie[*it] = u;
            }
        }

       // cout<<"\n q size"<<q.size()<<endl;
    }
}

void graph_traversal(int size ,vector<int> adj[], int v[]) {
    //cout<<"size: "<<length<<endl;
    char color[size];
    int pie[size];

    for(int i = 0; i < size; i++) {
        color[v[i]] = 'r';
        //cout<<"color set: "<<v[i]<<endl;
        pie[v[i]] = 0;
    }

    int s = v[0];
    color[s] = 'y';
    pie[s] = s;
    queue<int> q;
    q.push(s);
    bfs_visit(adj, color, pie, q);

    for(int i = 0; i < size; i++) {
        if(color[v[i]] == 'r') {
            q.push(v[i]);
            bfs_visit(adj, color, pie, q);
        }
    }

    cout<<endl;
    for(int i = 0; i < size; i++) {
        cout<<"pie of "<<v[i]<<" is: "<<pie[v[i]]<<endl;
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
