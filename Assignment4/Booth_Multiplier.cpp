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
void shift(vector<int> &A,int Asize,vector<int>  &B,int Bsize,int startBit){
        int p1=A[0];
        A[0]=startBit;
        int p2=A[1];
        for(int i=0;i+2<Asize;i++){
            A[i+1]=p1;
            p1=p2;
            p2=A[i+2];
        }
        A[Asize-1]=p1;
        int a1=B[0];
        B[0]=p2;
        int a2=B[1];
        for(int i=0;i+2<Bsize;i++){
            B[i+1]=a1;
            a1=a2;
            a2=B[i+2];
        }
        B[Bsize-1]=a1;
}
void Operation(vector<int> &A,vector<int> B,int op,int bits){
    pair<int,int> p= Full_adder(A[bits-1],XOR(B[bits-1],op),op);
    A[bits-1]=p.first;
    for(int i=bits-2;i>=0;i--){
        int carry=p.second;
        p=Full_adder(A[i],XOR(B[i],op),carry);
        A[i]=p.first;
    }
    return ;
}
void booth_multiplier(vector<int> M,vector<int> &A,vector<int> &Q,int bits){
    int n=bits;
    while(n>0){
        if(Q[bits-1]==1 & Q[bits]==0){
            Operation(A,M,1,bits);
        }
        else if(Q[bits-1]==0 & Q[bits]==1){
            Operation(A,M,0,bits);
        }
        shift(A,bits,Q,bits+1,A[0]);
        n--;
    }
}
int main(){
    vector<int> M;
    vector<int> Q;
    int bits;
    cout<<"ENTER NO. OF BITS:";cin>>bits;
    cout<<"ENTER M:";
    for(int i=0;i<bits;i++){
        int a;
        cin>>a;
        M.push_back(a);
    }
    cout<<"ENTER Q:";
    for(int i=0;i<bits;i++){
        int a;
        cin>>a;
        Q.push_back(a);
    }
    Q.push_back(0);
    vector<int> A;
    for(int i=0;i<bits;i++){
        A.push_back(0);
    }
    booth_multiplier(M,A,Q,bits);
    cout<<"\nTHE MULTIPLICATION OF M AND Q IS :"<<endl;
    for(int i=0;i<bits;i++){
        cout<<A[i]<<" ";
    }
    for(int i=0;i<bits;i++){
        cout<<Q[i]<<" ";
    }
    cout<<endl;
    return 0;
}