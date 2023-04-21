//This code is made by Chandravo Bhattacharya
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> avail{3,0,2};
    vector<vector<int>> alloc{{1,1,1},{0,1,1},{1,0,0}};
    vector<vector<int>> maxx{{2,1,2},{0,1,1},{2,1,0}};
    vector<vector<int>> req(alloc.size(),vector<int> (alloc[0].size(),0));
    vector<int> res;
    for (int i=0;i<alloc.size();i++){
        for (int j=0;j<alloc[i].size();j++){
            req[i][j]=maxx[i][j]-alloc[i][j];
        }
    }
    for (int i=0;i<alloc.size();i++){
        for (int j=0;j<alloc[i].size();j++){
            cout<<req[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"\t";
    cout<<"alloc"<<"\tavail"<<"\tmax"<<"\tneed"<<endl;
    for(int i=0;i<req.size();i++){
        cout<<"P"<<i+1<<"\t";
        
        for(int j=0;j<alloc[i].size();j++)
            cout<< alloc[i][j] << " ";
            
            cout<<"\t";
        if (i==0){ 
            for(int j=0;j<avail.size();j++)
                cout<< avail[j] << " ";
        }
            cout<<"\t";
        for(int j=0;j<maxx[i].size();j++)
            cout<< maxx[i][j] << " ";
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
                cout<<"completed process "<<i+1<<endl;
                res.push_back(i+1);
                cout<<"current avail :- ";
                for (int g:avail) cout<<g<<" ";
                cout<<endl;
                changed=1;
                break;
            }
            
        } 
        cout<<endl;  
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

    cout<<endl<<"Safe Sequence : ";
    for (int i:res) cout<<"P"<<i<<" ";
    cout<<endl;

}