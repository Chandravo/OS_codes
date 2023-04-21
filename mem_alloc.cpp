//This code is made by Chandravo Bhattacharya
#include<bits/stdc++.h>
using namespace std;
#include <iomanip>

class mem{
    public:
    int ind;
    int val;
    bool avail;
    mem *next;

    mem(int in, int x,bool y){
        ind=in;
        val=x;
        avail=y;
        next=nullptr;
    }

};

pair<int,int> FF(mem *head, int x){
    head=head->next;
    while (head!=nullptr){
        if (head->val>=x && head->avail) return {head->ind+1,head->val};
        head=head->next;
    }
    return {-1,0};
}

pair<int,int> BF(mem *head, int x){
    int diff=INT_MAX;
    int res=-2;
    int cap=-1;
    head=head->next;
    while (head){
        if (head->val>=x && head->avail && head->val-x<diff){
            diff=head->val-x;
            res=head->ind;
            cap=head->val;
        }
        head=head->next;
    }
    return {res+1,cap};
}

pair<int,int> WF(mem *head, int x){
    int diff=0;
    int res=-2;
    int cap=-1;
    head=head->next;
    while (head){
        if (head->val>=x && head->avail && head->val-x>diff){
            diff=head->val-x;
            res=head->ind;
            cap=head->val;
        }
        head=head->next;
    }
    return {res+1,cap};
}

int main(){
    mem *head = new mem(-1,0,0);
    auto ptr=head;
    cout<<"Enter the total segments "<<endl;
    int n;cin>>n;
    cout<<"enter the segments"<<endl<<endl;
    for (int i=0;i<n;i++){
        cout<<"enter the capacity ";
        int tmp;cin>>tmp;
        cout<<"Empty ? ";
        bool t;cin>>t;
        ptr->next=new mem(i,tmp,t);
        ptr=ptr->next;
    }
    cout<<endl;
    // ptr=head->next;
    // while (ptr){
    //     cout<<ptr->val<<endl;
    //     ptr=ptr->next;
    // }
    cout<<"enter the amount of space required "<<endl;
    int x;cin>>x;
    auto ff=FF(head,x);
    auto bf=BF(head,x);
    auto wf=WF(head,x);
    cout<<"Algo       "<<"Index       "<<"Capacity"<<endl;
    cout<<"FF           "<<ff.first<<"           "<<ff.second<<endl;
    cout<<"BF           "<<bf.first<<"           "<<bf.second<<endl;
    cout<<"WF           "<<wf.first<<"           "<<wf.second<<endl;        

}