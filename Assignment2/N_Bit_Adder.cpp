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
void Operation(vector<int> &A,vector<int> B,int op,int bits){
    pair<int,int> p= Full_adder(A[bits-1],XOR(B[bits-1],op),op);
    A[bits-1]=p.first;
    for(int i=bits-2;i>=0;i--){
        int carry=p.second;
        p=Full_adder(A[i],XOR(B[i],op),carry);
        A[i]=p.first;
    }
    A.insert(A.begin(),p.second);
    return ;
}
int main(){
    vector<int> A;
    vector<int> B;
    int bits;
    cout<<"ENTER NO. OF BITS:";cin>>bits;
    cout<<"ENTER A:";
    for(int i=0;i<bits;i++){
        int a;
        cin>>a;
        A.push_back(a);
    }
    cout<<"ENTER B:";
    for(int i=0;i<bits;i++){
        int a;
        cin>>a;
        B.push_back(a);
    }
    int op;
    cout<<"ENTER 0 FOR ADD AND 1 FOR SUB:";
    cin>>op;
    Operation(A,B,op,bits);
    cout<<"THE RESULT IS:"<<endl;
    for(int i=0;i<=bits;i++){
        cout<<A[i]<<" ";
    }
    return 0;
}