#include<iostream>
#include<string>
using namespace std;
int main()
{
 for(int i=1;i<5;i++){
    for(int j=1;j<i+1;j++){
        cout<<"*";
    }
    cout<<""<<endl; // it add a line break after printing each row
 } 
 return 0;  
}