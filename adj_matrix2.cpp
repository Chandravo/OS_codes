//This code is made by Chandravo Bhattacharya
#include<bits/stdc++.h>
using namespace std;
int main(){
    cout<<"enter the number of processes ";
    int n;cin>>n;
    cout<<"enter the adjacency matrix "<<endl;
    int adj[n][n];
    int res=0;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin>>adj[i][j];
            if (adj[i][j]==1) res++;
        }
    }
    int index=0;
    int waitfor[n+res][n+res]={0};

    for (int i=0;i<res+n;i++){
        for (int j=0;j<res+n;j++){
            waitfor[i][j]=0;
        }
    }
    
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (adj[i][j]==1){
                waitfor[i][n+index]=1;
                waitfor[n+index][j]=1;
                index++;
            }
        }
    }

    cout<<endl<<endl;
    cout<<"RAG ADJACENCY MATRIX"<<endl<<endl;
    vector<string> printhelp;
    for (int i=0;i<n;i++){
        string tmp="P";
        tmp.push_back(i+'1');
        printhelp.push_back(tmp);
    }
    for (int i=0;i<res;i++){
        string tmp="R";
        tmp.push_back(i+'1');
        printhelp.push_back(tmp);
    }

    // for (string i:printhelp)cout<<i<<" ";

    for (int i=0;i<=res+n;i++){
        if (i==0){
            cout<<"    ";
            for (int i=0;i<printhelp.size();i++){
                if (i%2==0) cout<<printhelp[i];
                else{
                    cout<<printhelp[i];
                }
            }
            cout<<endl;
            continue;
        }
        for (int j=0;j<=res+n;j++){
            if (j==0) {
                cout<<printhelp[i-1]<<"   ";
                continue;
            }
            cout<<waitfor[i-1][j-1]<<"   ";
        }
        cout<<endl;
    }
    
}