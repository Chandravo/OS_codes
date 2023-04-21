//This code is made by Chandravo Bhattacharya
#include<bits/stdc++.h>
using namespace std;
int main(){
    cout<<"enter the number of process"<<endl;
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
        m.push_back({arrival[i],i});
    }
    sort(m.begin(),m.end());
    vector<int> order;
    order.push_back(m[0][1]);       
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    int time=cpu[m[0][1]];
    int ind=1;
    vector<int> wait(p);
    while (ind<p){
        while (ind<p && m[ind][0]<=time) {
            pq.push({cpu[m[ind][1]],ind});
            ind++;
        }
        order.push_back(m[pq.top().second][1]);
        wait[m[pq.top().second][1]]=time-arrival[m[pq.top().second][1]];
        time+=pq.top().first;
        pq.pop();
    }
    while (!pq.empty()){
        order.push_back(m[pq.top().second][1]);
        wait[m[pq.top().second][1]]=time-arrival[m[pq.top().second][1]];
        time+=pq.top().first;
        pq.pop();
    }
    cout<<endl<<endl;
    cout<<"ORDER OF EXECEUTION  =>  ";
    for (int i:order) cout<<"P"<<i+1<<" ";
    cout<<endl<<endl;
    cout<<"Process    "<<"Arrival-Time "<<"   CPU-Time "<<"   Waiting-time"<<endl;
    for (int i:order){
        cout<<"   P"<<i+1<<"            "<<arrival[i]<<"            "<<cpu[i]<<"            "<<wait[i]<<endl;
    }
}