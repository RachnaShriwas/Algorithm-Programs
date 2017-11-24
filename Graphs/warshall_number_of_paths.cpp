//find number of simple paths from i to j in a graph

#include<bits/stdc++.h>
using namespace std;

int main() {
    int V = 4;

    int a[V][V] = { {0,1,0,1},
                  {1,0,0,0},
                  {1,1,0,1},
                  {0,1,0,0}
                };
    int n[V][V];

    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++)
            n[i][j] = a[i][j];
    }//love you :* so very much

    for(int k = 1; k < V; k++) {
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                    n[i][j] = n[i][j] + (n[i][k] * n[k][j]);
            }
        }
    }

    cout<<"No. of paths:\n";
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++)
            cout<<n[i][j]<<" ";
        cout<<endl;
    }


}
