//find transitive closure of a graph
#include<bits/stdc++.h>
using namespace std;

int main() {
    int V = 4;

    int a[V][V] = { {0,1,0,1},
                  {1,0,0,0},
                  {1,1,0,1},
                  {0,1,0,0}
                };

    int t[V][V];

    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++)
            t[i][j] = a[i][j];
    }

    for(int k = 0; k < V; k++) {
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                if(t[i][k] == 1 && t[k][j] == 1)
                    t[i][j] = 1;
            }
        }
    }

    cout<<"Transitive closure is:\n";
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++)
            cout<<t[i][j]<<" ";
        cout<<endl;
    }
}
