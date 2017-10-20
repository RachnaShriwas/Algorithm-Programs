#include<bits/stdc++.h>
using namespace std;

int main() {
    int p[] = {2,3,1,5};
    int w[] = {1,2,2,4};
    int W = 4;

    int n = sizeof(p)/sizeof(p[0]);
    vector<pair<float, int> > density;

    for(int i = 0; i < n; i++) {
        density.push_back(make_pair(p[i]*1.0 / w[i], i));
    }

    sort(density.begin(),density.end());
    reverse(density.begin(),density.end());

//    for(int i = 0; i < n; i++) {
//        cout<<density[i].first<<" "<<w[density[i].second]<<endl;
//    }
//    cout<<endl;

    float profit = 0;
    for(int i = 0; i <n; i++ ) {
        if(w[density[i].second] <= W) {
            profit += p[density[i].second];
            W -= w[density[i].second];
        }
        else {
            profit += density[i].first * W;
            break;
        }
        //cout<<"profit:"<<profit<<endl;
    }

    cout<<"Profit: "<<profit;

}
