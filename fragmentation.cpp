//This code is made by Chandravo Bhattacharya
#include<bits/stdc++.h>
using namespace std;


vector<int> generateRandom(int siz, int net){
    srand(time(0));
    vector<int> arr(siz,0);
    for (int i=0;i<net;i++){
        arr[rand()%siz]++;
    }
    return arr;
}

int main(){
    cout<<"enter the total size of memory "<<endl;
    int total_mem;cin>>total_mem;
    cout<<"enter the number of chunks "<<endl;
    int n;cin>>n;

    vector<int> memory = generateRandom(n, total_mem);
    for (int i:memory) cout<<i<<" ";
    cout<<endl;
    cout<<"enter the total number of occupied segments ";
    int occ_no;cin>>occ_no;
    cout<<"enter the occupied segment numbers ";
    vector<int> occ(occ_no);
    for (int i=0;i<occ_no;i++){
        int tmp;cin>>tmp;
        occ[i]=tmp-1;
    }

    // EXTERNAL FRAGMENTATION
    cout<<endl<<endl<<"EXTERNAL FRAGMENTATION"<<endl;
    for (int i=0;i<n;i++){
        if (find(occ.begin(),occ.end(),i)==occ.end()){
            cout<<"segment number = "<<i+1<<"   size = "<<memory[i]<<endl;
        }
    }


    // INTERNAL FRAGMENTATION
    cout<<endl<<endl<<"INTERNAL FRAGMENTATION"<<endl;
    
    cout<<"enter the percentage of internal fragmentation in even occupied segments ";
    int even;cin>>even;
    cout<<"enter the percentage of internal fragmentation in odd occupied segments ";
    int odd;cin>>odd;
    cout<<endl;
    for (int i:occ){
        if ((i+1)&1){
            cout<<"internal fragmentaton in segment "<<i+1<<" is "<<((double)odd/100)*(double)memory[i]<<endl;
        }
        else{
            cout<<"internal fragmentaton in segment "<<i+1<<" is "<<((double)even/100)*(double)memory[i]<<endl;
        }
    }
}