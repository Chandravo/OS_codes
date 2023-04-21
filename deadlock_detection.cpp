//This code is made by Chandravo Bhattacharya
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> avail{1,1,1};
    vector<vector<int>> alloc{{0,1,0},{2,0,0},{3,0,3},{2,1,1},{0,0,2}};
    vector<vector<int>> req{{0,0,0},{2,0,2},{0,0,1},{1,0,0},{0,0,2}};
    cout<<"\t";
    cout<<"alloc"<<"\tavail"<<"\treq"<<endl;
    for(int i=0;i<req.size();i++){
        cout<<"P"<<i<<"\t";
        
        for(int j=0;j<alloc[i].size();j++)
            cout<< alloc[i][j] << " ";
            
            cout<<"\t";
        if (i==0){
            for(int j=0;j<avail.size();j++)
                cout<< avail[j] << " ";
        }
            cout<<"\t";
        for(int j=0;j<req[i].size();j++)
            cout<< req[i][j] << " ";
        
        cout<<endl;
    }
    cout<<endl<<endl;
    int changed=1;
    while(changed) {
        // cout<<"loop starts"<<endl;
        changed=0;
        for (int i=0;i<alloc.size();i++){
            // cout<<"lmao"<<endl;
            if (alloc[i][0]==-1) continue;
            bool is_good=true;
            // cout<<"size = "<<alloc[i].size()<<endl;
            for (int j=0;j<alloc[i].size();j++){
                // cout<<"lol"<<endl;
                if (req[i][j]<=avail[j]) continue;
                else{
                    // cout<<i<<endl;
                    is_good=false;
                    break;
                }    
            }
            if (is_good){
                for (int j=0;j<alloc[i].size();j++){
                    avail[j]+=alloc[i][j];
                    alloc[i][j]=-1;
                }
                cout<<"completed process "<<i<<endl;
                cout<<"current avail :- ";
                for (int g:avail) cout<<g<<" ";
                cout<<endl;
                changed=1;
                break;
            }
            
        } 
        cout<<endl<<endl;  
        if (!changed){
            bool deadlock=false;
            for (int i=0;i<alloc.size();i++){
                bool is_finished=true;
                for (int j=0;j<alloc[i].size();j++){
                    if (alloc[i][j]!=-1){
                        bool is_finished=false;
                        cout<<"Could not allocate resources to process "<<i<<endl;
                        deadlock=true;
                        break;
                    }
                }
                if (deadlock) break;
            }
            if (!deadlock) cout<<"There is no deadlock "<<endl;
            break;

        }
    }
}