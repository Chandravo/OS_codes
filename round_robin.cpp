//This code is made by Chandravo Bhattacharya
#include<bits/stdc++.h>
using namespace std;

// class process{
//     public:
//     int a_time;

// };  

int main(){
    cout<<"enter the number of processes    "<<endl;
    int p;cin>>p;
    cout<<"Enter the time quantum"<<endl;
    int t;cin>>t;
    vector<int> arr(p);
    vector<pair<int,int>> m;
    cout<<"enter the arrival time"<<endl;
    for (int i=0;i<p;i++){
        cin>>arr[i];
        m.push_back({arr[i],i});
    }
    sort(m.begin(),m.end());
    vector<int> cpu(p);
    cout<<"enter the CPU time"<<endl;
    for (int i=0;i<p;i++){
        cin>>cpu[i];
    }
    vector<int> wait(p,0);
    // ind,cpu,i
    queue<pair<int,int>> ready;
    auto tmp=m[0];
    ready.push({tmp.second,cpu[tmp.second]});
    int ind=1;
    int time=0;
    auto tmp1=ready.front();
    pair<int,int> tmp2={0,0};
    int flag=1;
    while (!ready.empty() || ind<p || tmp2.second!=0){
        
        
        while (ind<p && m[ind].first<=time){
            
            ready.push({m[ind].second,cpu[m[ind].second]});
            // m.erase(m.begin()+ind);
            ind++;
            
        }
        
        if (tmp2.second!=0){
            ready.push(tmp2);
        }
        tmp1 = ready.front();
        ready.pop();
        
        // cout<<"m size "<<m.size()<<endl;
        // for (auto i:m) cout<<i.first<<" "<<i.second<<endl;
        // cout<<"lol"<<endl;
        cout<<"Time = "<<time<<", Process = P"<<tmp1.first+1<<", Time left = "<<tmp1.second<<" units"<<endl;

        if (tmp1.second>=t){
            
            // cout<<"l"<<endl;
            tmp1.second-=t;
            time+=t;
            // flag=1;
            // ready.push(tmp1);
            // tmp2=tmp1;
        }
        else{
            time+=tmp1.second;
            tmp1.second=0;
            // cout<<tmp1.first<<endl;
            // flag=0;
            wait[tmp1.first]=time-arr[tmp1.first]-cpu[tmp1.first];
        }
        tmp2=tmp1;
    }
    cout<<endl<<endl;
    cout<<"Process    "<<"Arrival-Time "<<"   CPU-Time "<<"   Waiting-time"<<endl;
    for (int i=0;i<p;i++){
        cout<<"   P"<<i+1<<"            "<<arr[i]<<"            "<<cpu[i]<<"            "<<wait[i]<<endl;
    }

}