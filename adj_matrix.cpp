//This code is made by Chandravo Bhattacharya
#include<bits/stdc++.h>
using namespace std;
int main(){
    cout<<"enter the number of processes ";
    int n;cin>>n; // total number of processes
    cout<<"enter the adjacency matrix "<<endl;
    vector<vector<int>> adj(n, vector<int> (n,0));
    int res=0; // total number of resources
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin>>adj[i][j];
            if (adj[i][j]==1) res++; // counting the number of resources
        }  
    }

    

    int ind=0; // keeping track of the number of resources used in th following loop
    vector<vector<int>> RAG(n+res  ,vector<int> (n+res,0));

    
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++){
            if (adj[i][j]== 1){ 
                RAG[i ][n+ind]=1; // making an edge from the process to the resource
                RAG[n+ind][j]=1; // making an edge from the resource to the process
                ind++;
            }
        }
    }

    // making an array/vector of the names of processes and rsources to help print the first row and column
    vector<string> printhelp;

    // inserting the names of processes
    for (int i=0;i<n;i++){
        string tmp="P";
        tmp.push_back(i+'1');
        printhelp.push_back(tmp);
    }

    
    // inserting the name of resources
    for (int i=0;i<res;i++){
        string tmp="R";
        tmp.push_back(i+'1');
        printhelp.push_back(tmp);
    }
    // printhelp = {p1,p2,p3,r1,r2,r3}

    cout<<endl<<endl;

    // printing the original adjacency matrix entered
    for (int i=0;i<=n;i++){
        if (i==0){ // for the first row we need to print the name of the processes
            cout<<"    ";
            for (int i=0;i<n;i++){
                cout<<printhelp[i]<<"  ";
            } 
            cout<<endl;
            continue;
        }
        for (int j=0;j<=n;j++){
            if (j==0) {
                // for the first column we need to print the name of the processes
                cout<<printhelp[i-1]<<"   ";
                continue;
            }
            cout<<adj[i-1][j-1]<<"   ";
        }
        cout<<endl;
    }

    cout<<endl<<endl;
    cout<<"RAG ADJACENCY MATRIX"<<endl<<endl;


    // printing the final Resource Allocation Graph adjacency matrix
    for (int i=0;i<=res+n;i++){
        if (i==0){ // for the first row we need to print the name of the processes and resources
            cout<<"    ";
            for (string i:printhelp) cout<<i<<"  ";
            cout<<endl;
            continue;
        }
        for (int j=0;j<=res+n;j++){
            if (j==0) { // for the first column we need to print the name of the processes and resources
                cout<<printhelp[i-1]<<"   ";
                continue;
            }
            cout<<RAG[i-1][j-1]<<"   ";
        }
        cout<<endl;
    }
    
}