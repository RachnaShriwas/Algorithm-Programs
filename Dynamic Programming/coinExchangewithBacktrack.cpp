///Given coins of denominations d1,d2,...,dk(infinite no. of each type).
///Find min no. of coins required to pay the sum 'n'.
///Time - O(nk)
///Space - O(nk)
///v[i][j] = min no. of coins reqd to pay i using the first j coins

#include<bits/stdc++.h>
using namespace std;

int main() {
    int d[] = {1,7,10};
    int n = sizeof(d)/sizeof(d[0]);
    int s = 14;
    int v[s+1][n+1];

    for(int i = 0; i <=s; i++) {
        for(int j = 0; j <= n; j++) {
            if(i == 0 || j == 0)
                v[i][j] = 0;
            else if(j == 1)
                v[i][j] = i;
            else {
                v[i][j] = v[i][j-1];
                if(i >= d[j-1] && (v[i][j] > (1 + v[i-d[j-1]][j] ) ) )
                    v[i][j] = 1 + v[i-d[j-1]][j];
            }

        }
    }

    cout<<"Min no. of coins required to make the sum: "<<v[s][n]<<endl;

    cout<<"Following coins used to make the sum:\n";

    ///O(s+n)
    int i = s, j = n;
    while(i >= 1 && j >= 1) {
        if(v[i][j] == v[i][j-1])
            j = j-1;
        else {
            cout<<d[j-1]<<" ";
            i = i - d[j-1];
        }
    }

    cout<<endl;
    return 0;

}
