//This code is made by Chandravo Bhattacharya
#include<bits/stdc++.h>
using namespace std;

int findInd(vector<int> &v, int &x){
    for (int i=0;i<v.size();i++){
        if (v[i]==x) return i;
    }
    return -1;
}
int main(){
    vector<int> faults;
    // cout<<"Enter the number of process ";
    // int n;cin>>n;
    vector<int> inp{1,1,1,0,0,0,3,3,3};
    // for (int i=0;i<n;i++){
    //     cin>>inp[i];
    // }
    vector<int> page(3,-1);
    for (int i=0;i<inp.size();i++){
        if (findInd(page,inp[i])==-1){
            page.erase(page.begin());
            page.push_back(inp[i]);
            cout<<"Fault at "<<inp[i]<<endl;
        }
        else{
            // cout<<"index returned "<<findInd(page,inp[i])<<endl;
            page.erase(page.begin()+findInd(page,inp[i]));
            page.push_back(inp[i]);
            cout<<"Hit at "<<inp[i]<<endl;
        }
        cout<<"Page : ";
        for (int j:page) {
            if (j!=-1) cout<<j<<" ";
        }
        cout<<endl;
    }


}