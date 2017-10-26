///Given coins of denominations d1,d2,...,dk(infinite no. of each type).
///Find min no. of coins required to pay the sum 'n'.
///Time - O(nk)
///Space - O(n)
///v[i] = min no. of coins reqd to pay i using the first j coins


#include<bits/stdc++.h>
using namespace std;

int main() {
    int d[] = {1,7,10};
    int n = sizeof(d)/sizeof(d[0]);
    int s = 14;
    int v[s+1];

    for(int i = 0; i <= s; i++)
        v[i] = i;

    for(int i = 1; i <= s; i++) {
        for(int j = 1; j <= n; j++) {
            if(i >= d[j-1] && v[i] > 1+v[i-d[j-1]])
                v[i] = 1+v[i-d[j-1]];
        }
    }

    cout<<"Min no. coins reqd: "<<v[s]<<endl;
}
