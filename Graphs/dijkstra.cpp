#include<bits/stdc++.h>
using namespace std;

class Compare
{
public:
    bool operator() (pair<int, int> p1, pair<int, int> p2)
    {
        return p1.second > p2.second;
    }
};

void dijkstra(int s, vector<pair<int, int> > adj[], int size, int v[]) {
    int p[size+1];
    int color[size+1];
    int pie[size+1];
    memset(p, INT_MAX, sizeof(p));
    memset(color, 'r', sizeof(color));
    memset(pie, 0, sizeof(pie));

    for(int i = 1; i <= size; i++)
        color[i] = 'r';

    priority_queue< pair<int,int> , vector<pair<int,int> >, Compare > q;
    p[s] = 0;
    q.push(make_pair(s, p[s]));

    while(!q.empty()) {
        int u = q.top().first;
        //cout<<"popping: "<<u<<" "<<p[u]<<endl;
        q.pop();

        vector<pair<int, int> >::iterator it;
        for(it = adj[u].begin(); it != adj[u].end(); it++) {
            int v = it->first;
            //cout<<"seeing v: "<<v<<endl;
            if(color[v] == 'r') {
                p[v] = p[u] + it->second;
                //cout<<"v was red, p now is: "<< p[v]<<endl;
                pie[v] = u;
                q.push(make_pair(v, p[v]));
                color[v] = 'y';
            }
            else if(color[v] == 'y') {
                if(p[v] > (p[u] + it->second) ) {
                    p[v] = p[u] + it->second;
                    pie[v] = u;
                    //cout<<"v was yellow, p now is: "<< p[v]<<endl;
                }
            }
        }
    }

    //print parent
    cout<<"Parent vertices: "<<endl;
    for(int i = 0; i < size; i++) {
        cout<<"pie of "<<v[i]<<" is: "<<pie[v[i]]<<endl;
    }

    //shortest path
    cout<<"\nShortest paths: "<<endl;
    for(int i = 0; i < size; i++) {
        cout<<"pie of "<<v[i]<<" is: "<<p[v[i]]<<endl;
    }

}

int main() {
    /* Graph edge list
        edge   weight
        1-->2   3
        1-->4   6
        2-->3   9
        2-->4   2
        4-->5   4
        5-->2   2
        5-->3   1
    */

    int V = 5;
    int v[] = {1,2,3,4,5};

    vector<pair<int, int> > adj[V+1];

    adj[1].push_back(make_pair(2,3));
    adj[1].push_back(make_pair(4,6));
    adj[2].push_back(make_pair(3,9));
    adj[2].push_back(make_pair(4,2));
    adj[4].push_back(make_pair(5,4));
    adj[5].push_back(make_pair(2,2));
    adj[5].push_back(make_pair(3,1));

    dijkstra(v[0], adj, V, v);

    return 0;
}
