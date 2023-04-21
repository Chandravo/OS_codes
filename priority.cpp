//This code is made by Chandravo Bhattacharya
#include<bits/stdc++.h>
using namespace std;

class comp{
    public:
    bool operator()(vector<int> a, vector<int> b){
        return (a[0]==b[0])? a[1]>b[1] : a[0]<b[0];
    }
};



int main(){
    cout<<"Enter the number of processes ";
    int p;cin>>p;
    vector<int> arr(p),cpu(p), pr(p), wait(p);
    // arr, pri, ind
    vector<vector<int>> m(p);
    cout<<"Enter the arrival time "<<endl;
    for (int i=0;i<p;i++) {
        cin>>arr[i];
    }
    
    cout<<endl;
    cout<<"Enter the cpu time "<<endl;
    for (int i=0;i<p;i++) cin>>cpu[i];
    cout<<"Enter the priority"<<endl;
    for (int i=0;i<p;i++) cin>>pr[i];
    for (int i=0;i<p;i++){
        m[i]={arr[i],pr[i],i};
    }
    sort(m.begin(),m.end(),comp());
    for (int i=0;i<p;i++){
        cout<<m[i][2]<<" ";
    }
    cout<<endl;
    int ind=1;
    // priority, cpu left, index
    priority_queue<vector<int>,vector<vector<int>>, greater<vector<int>>> q;
    q.push({m[0][1],cpu[m[0][2]],m[0][2]});
    int time=0;
    while (ind<p || !q.empty()){
        vector<int> tmp=q.top();
        cout<<"current temp "<<tmp[0]<<" "<<tmp[1]<<" "<<tmp[2]<<endl;
        q.pop();
        tmp[1]-=1;
        time++;
        cout<<"Time = "<<time<<endl;
        if (tmp[1]==0){
            wait[tmp[2]]=time-arr[tmp[2]]-cpu[tmp[2]];
        }
        else q.push(tmp);
        while (ind<p && m[ind][0]<=time){
            q.push({m[ind][1],cpu[m[ind][2]],m[ind][2]});
            ind++;
        }

    }

    cout<<"Process    "<<"Arrival-Time "<<"   CPU-Time "<<"   Priority"<<"   Waiting-time"<<endl;
    for (int i=0;i<p;i++){
        cout<<"   P"<<i+1<<"            "<<arr[i]<<"            "<<cpu[i]<<"            "<<pr[i]<<"            "<<wait[i]<<endl;
    }


}