//This code is made by Chandravo Bhattacharya
#include<bits/stdc++.h>
using namespace std;

int findShortest(vector<int> &seek, vector<bool> &comp, int x){
    int res=-1;
    int minv=INT_MAX;
    for (int i =0;i<seek.size();i++){
        if (comp[i]==false && abs(x-seek[i])<minv){
            minv=abs(x-seek[i]);
            res=i;
        }
    }
    comp[res]=true;
    return res;
}

int main(){
    int x;cin>>x;
    int low=0,high=120;
    vector<int> seek{62,12,100,119,2};
    vector<bool> comp(seek.size(),false);
    int complete =0;
    cout<<"Hit List => "<<x;
    sort(seek.begin(),seek.end());
    while (complete!=seek.size()){
        cout<<" -> ";
        int ind = findShortest(seek,comp,x);
        if (ind==-1) break;
        else cout<<seek[ind],complete++;
        
    }
    cout<<endl;

}