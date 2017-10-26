///Subset sum problem
///array: a1,a2,...,an  | Sum: X
///T[i][j] = can we make the sum j using first i items
///Time: O(nX)
///Space: O(nX)

#include<bits/stdc++.h>
using namespace std;

int main() {
    int a[] = {3, 34, 4, 12, 7, 2};
    int n = sizeof(a)/sizeof(a[0]);
    int sum = 50;

    bool t[n+1][sum+1];

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= sum; j++) {
            if(i == 1) {
                    t[i][j] = ( (j == a[i-1]) ? true : false );
            }
            else {
                t[i][j] = t[i-1][j];
                if( j >= a[i-1])
                    t[i][j] = t[i][j] || t[i-1][j-a[i-1]];
            }
        }
    }

    cout<<"Can sum of "<<sum<<" be made? "<<bool(t[n][sum])<<endl;

    if(t[n][sum]) {
        cout<<"Elements used for making the sum:\n";
        int i = n, j = sum;
        while(i >= 1 && j >= 1) {
            if(t[i][j] == t[i-1][j])
                i = i-1;
            else {
                cout<<a[i-1]<<" ";
                j = j - a[i-1];
                i = i-1;
            }
        }
    }

    return 0;
}
