///Find min no. of machines required to schedule all jobs
#include<bits/stdc++.h>
using namespace std;

int main() {
    int starttime[] = {1,6,3,4};
    int endtime[] = {4,8,6,5};

    vector<pair <int, int> > time;
    for(int i = 0; i < sizeof(starttime)/sizeof(starttime[0]); i++) {
        time.push_back(make_pair(starttime[i], endtime[i]));
    }

    sort(time.begin(), time.end());

    vector<int> machine;

    //schedule first job
    int j;
    machine.push_back(time[0].second);
    //use linear search to find which machine is free
    for(int i = 1; i < time.size(); i++) {
        for(j = 0; j < machine.size(); j++) {
            if(time[i].first >= machine[j]) {
                machine[j] = time[i].second;
                break;
            }
        }
        if(j == machine.size())
            machine.push_back(time[i].second);
    }

    cout<<"Min no. of machines required: "<<machine.size()<<endl;


}

