//This code is made by Chandravo Bhattacharya
#include<bits/stdc++.h>
using namespace std;
bool f1(){
    cout<<"f1"<<endl;
    return 0;
}
bool f2(){
    cout<<"f2"<<endl;
    return 0;
}
bool f3(){
    cout<<"f3"<<endl;
    return 1;
}
int main(){
    if (f1() || (f2() && f3())) cout<<"True"<<endl;
}