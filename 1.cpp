//This code is made by Chandravo Bhattacharya
#include<bits/stdc++.h>
using namespace std;
int main(){
    int p;cin>>p;
    vector<int> arrival(p);
    cout<<"enter the arrival time"<<endl;
    for (int i=0;i<p;i++){
        cin>>arrival[i];
    }
    cout<<"enter cpu time "<<endl;
    vector<int> cpu(p);
    for (int i=0;i<p;i++){
        cin>>cpu[i];
    }
    vector<int> cum_cpu;
    for (int i:cpu) cum_cpu.push_back(i);
    for (int i=1;i<p;i++){
        cum_cpu[i]+=cum_cpu[i-1];
    }
    vector<int> wait(p);
    wait[0]=arrival[0];
    for (int i=1;i<p;i++){
        wait[i]=cum_cpu[i-1]-arrival[i];
    }
    // for (int i:wait) cout<<i<<endl;

    
    cout<<"Process    "<<"Arrival-Time "<<"   CPU-Time "<<"   Waiting-time"<<endl;
    for (int i=0;i<p;i++){
        cout<<"   P"<<i+1<<"            "<<arrival[i]<<"            "<<cpu[i]<<"            "<<wait[i]<<endl;
    }    
}