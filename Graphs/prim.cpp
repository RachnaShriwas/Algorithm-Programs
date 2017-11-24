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

void prim(int s, vector<pair<int, int> > adj[], int size, int v[]) {
    int p[size+1];
    int color[size+1];
    int pie[size+1];
    memset(p, INT_MAX, sizeof(p));
    memset(pie, 0, sizeof(pie));

    for(int i = 1; i <= size; i++)
        color[i] = 'r';

    priority_queue< pair<int,int> , vector<pair<int,int> >, Compare > q;
    p[s] = 0;
    pie[s] = s;
    q.push(make_pair(s, p[s]));

    while(!q.empty()) {
        int u = q.top().first;
        q.pop();
        color[u] = 'b';
        //cout<<"popped: "<<u<<" "<<p[u]<<endl;

        vector<pair<int, int> >::iterator it;
        for(it = adj[u].begin(); it != adj[u].end(); it++) {
            int v = it->first;
            //cout<<"seeing v: "<<v<<endl;
            if(color[v] == 'r') {
                p[v] = it->second;
                //cout<<"v was red, p now is: "<< p[v]<<endl;
                pie[v] = u;
                q.push(make_pair(v, p[v]));
                color[v] = 'y';
            }
            else if(color[v] == 'y') {
                if(p[v] > it->second) {
                    p[v] = it->second;
                    q.push(make_pair(v, p[v]));
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

    cout<<"\nEdges of MST: "<<endl;
    for(int i = 0; i < size; i++) {
        cout<<pie[v[i]]<<" "<<v[i]<<endl;
    }

}

int main() {
    /* Graph edge list
        edge   weight
        1--5    4
        1--3    6
        2--3    7
        2--6    9
        3--4    2
        4--5    4
        6--3    3
    */

    int V = 6;
    int v[] = {1,2,3,4,5,6};

    vector<pair<int, int> > adj[V+1];

    adj[1].push_back(make_pair(5,4));
    adj[5].push_back(make_pair(1,4));

    adj[1].push_back(make_pair(3,6));
    adj[3].push_back(make_pair(1,6));

    adj[2].push_back(make_pair(3,7));
    adj[3].push_back(make_pair(2,7));

    adj[2].push_back(make_pair(6,9));
    adj[6].push_back(make_pair(2,9));

    adj[3].push_back(make_pair(4,2));
    adj[4].push_back(make_pair(3,2));

    adj[4].push_back(make_pair(5,4));
    adj[5].push_back(make_pair(4,4));

    adj[6].push_back(make_pair(3,3));
    adj[3].push_back(make_pair(6,3));

    prim(v[0], adj, V, v);

    return 0;
}

