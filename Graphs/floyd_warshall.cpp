#include<bits/stdc++.h>
using namespace std;

void printSP(int i, int j, int pie[][4]) {
    if(i == j) {
        return;
    }
    if(pie[i][j] == i) {
        return;
    }
    int k = pie[i][j];
    cout<<k+1<<" ";
    printSP(i, k, pie);
    printSP(k, j, pie);
}

int main() {
    int V = 4;
    int a[V][V] = {{0,8,0,1},
                  {7,0,0,0},
                  {3,2,0,4},
                  {0,6,0,0}
                };

    int d[4][4], pie[4][4];

    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            if(i == j)
                d[i][j] = INT_MAX;
            else if(a[i][j] > 0)
                d[i][j] = a[i][j];
            else
                d[i][j] = INT_MAX;

            pie[i][j] = i;
        }
    }

    //cout<<"\n\n";
    for(int k = 0; k < V; k++) {
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                if(i == j)
                    d[i][j] = 0;

                else if( d[i][k] != INT_MAX && d[k][j] != INT_MAX && (d[i][k] + d[k][j]) < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                    //cout<<i<<" "<<j<<" "<<d[i][j]<<endl;
                    pie[i][j] = k;
                }
            }
        }
    }

    cout<<"All pair shortest path: \n";
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
                cout<<d[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"\nPrinting shortest path:\n";
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            cout<<"i:"<<i+1<<" j:"<<j+1<<"     ";
            if(d[i][j] != INT_MAX) {

                cout<<i+1<<" ";
                printSP(i, j, pie);
                cout<<j+1<<" ";
            }
            else
                cout<<"no path";
            cout<<endl;
        }
        cout<<"---------------\n";
    }

    return 0;
}
