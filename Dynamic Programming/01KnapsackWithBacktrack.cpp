///0/1 Knapsack Problem
///weights w1,w2,....,wn | values v1,v2,...,vn  |  capacity W
///Time O(nW)
///Space O(nW)
///v[i][j] = optimal value of profit considering i items and capacity j

#include<bits/stdc++.h>
using namespace std;

int main() {
    int w[] = {10,20,30};
    int n = sizeof(w)/sizeof(w[0]);
    int p[] = {60,100,120};
    int W = 50;

    int v[n+1][W+1];
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= W; j++) {
            if(i == 0 || j == 0)
                v[i][j] = 0;
            else if(i == 1) {
                if(j >= w[i-1])
                    v[i][j] = p[i-1];
                else
                    v[i][j] = 0;
            }
            else {
                v[i][j] = v[i-1][j];
                if(j >= w[i-1] && v[i][j] < p[i-1] + v[i-1][j-w[i-1]])
                    v[i][j] = p[i-1] + v[i-1][j-w[i-1]];
            }

        }
    }

    cout<<"Max profit: "<<v[n][W]<<endl;

    cout<<"Items used are:\n";
    int i = n, j = W;
    while(i >= 1 && j >= 1) {
        if(v[i][j] == v[i-1][j])
            i = i-1;
        else {
            cout<<w[i-1]<<" ";
            j = j - w[i-1];
            i = i-1;
        }
    }
}

