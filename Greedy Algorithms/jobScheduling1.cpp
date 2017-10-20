///Find max no. of jobs that can be scheduled on a single machine

#include<bits/stdc++.h>
using namespace std;

int main() {
    int starttime[] = {1,6,3,4};
    int endtime[] = {4,8,6,5};

    vector<pair <int, int> > time;
    for(int i = 0; i < sizeof(starttime)/sizeof(starttime[0]); i++) {
        time.push_back(make_pair(endtime[i], starttime[i]));
    }

    sort(time.begin(), time.end());

    int count = 1;
    vector<pair<int, int> >::iterator it = time.begin();
    int en = it->first;
    it++;

    for( ;it != time.end(); it++) {
        if(it->second >= en) {
            count++;
            en = it->first;
        }
    }

    cout<<"No. of jobs that can be scheduled are: "<<count;

}
