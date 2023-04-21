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
    vector<vector<int>> m; 
    cout<<"enter cpu time "<<endl;
    vector<int> cpu(p);
    for (int i=0;i<p;i++){
        cin>>cpu[i];
        m.push_back({arrival[i],cpu[i],0,i});
    }
    vector<int> wait(p);
    sort(m.begin(),m.end());
    cout<<"ORDER OF EXECUTION "<<endl;
    for (auto i:m) {
        cout<<"P"<<i[3]+1<<endl;
    }
    int time=0;
    int i=0;
    while (i<p){
        if (time>=m[i][0]){
            // cout<<"i is "<<i<<endl;
            m[i][2]=(time-m[i][0]);
            time+=m[i][1];
            i++;
        }
        else time++;
    }
    for (int i=0;i<p;i++){
        wait[m[i][3]]=m[i][2];
    }
    cout<<"Process    "<<"Arrival-Time "<<"   CPU-Time "<<"   Waiting-time"<<endl;
    for (int i=0;i<p;i++){
        cout<<"   P"<<i+1<<"            "<<arrival[i]<<"            "<<cpu[i]<<"            "<<wait[i]<<endl;
    }
}