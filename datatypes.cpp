#include<iostream>
using namespace std;
int main(){
    int a;
    a= 10;
    cout<<"size of int "<<sizeof(a)<<endl;
    float b;
    cout<<"size of float "<<sizeof(b)<<endl;
    char c;
    cout<<"size of char "<<sizeof(c)<<endl;
    bool d;
    cout<<"size of bool "<<sizeof(d)<<endl;
    short int si;
    cout<<"size of shortint "<<sizeof(si)<<endl;
    long int li; //print 4 bcoz of mingw of 32 bits and print 8 if 64 bit mingw
    cout<<"size of longint "<<sizeof(li)<<endl;
    return 0;
}