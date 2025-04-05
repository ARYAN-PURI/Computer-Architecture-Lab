#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int AND(int a,int b){
    if(a==0) {return 0;}
    else if(b==0) {return 0;}
    else {return 1;}
}
int OR(int a,int b){
    if(a==1) {return 1;}
    else if(b==1) {return 1;}
    else {return 0;}
}
int NOT(int a){
    if(a==1) {return 0;}
    else {return 1;}
}
int XOR(int a,int b){
    if(a==0){
        if(b==0) {return 0;}
        else {return 1;}
    }
    if(a==1){
        if(b==1) {return 0;}
        else {return 1;}
    }
}
int NAND(int a,int b){
    if(a==0) {return 1;}
    else if(b==0) {return 1;}
    else{return 0;}
}
int NOR(int a,int b){
    if(a==1) {return 0;}
    else if(b==1) {return 0;}
    else {return 1;}
}
pair<int,int> Half_adder(int a,int b){
    pair<int,int> p;
    p.first=XOR(a,b);
    p.second=AND(a,b);
    return p;
}
pair<int,int> Full_adder(int a,int b,int c){
    pair<int,int> p;
    p.first=XOR(XOR(a,b),c);
    p.second=OR(AND(XOR(a,b),c),AND(a,b));
    return p;
}
int main(){
    cout<<"FOR HALF ADDER"<<endl;
    int a;
    int b;
    cout<<"ENTER A,B:";cin>>a>>b;
    pair<int,int> halfAdder=Half_adder(a,b);
    cout<<"SUM="<<halfAdder.first<<endl;
    cout<<"CARRY="<<halfAdder.second<<endl<<endl;
    cout<<"FOR FULL ADDER"<<endl;
    int x;
    int y;
    int c;
    cout<<"ENTER A,B,C:";cin>>x>>y>>c;
    pair<int,int> fullAdder=Full_adder(x,y,c);
    cout<<"SUM="<<fullAdder.first<<endl;
    cout<<"CARRY="<<fullAdder.second<<endl<<endl;
    return 0;
}