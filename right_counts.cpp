#include<iostream>
#include<string>
using namespace std;
int main()
{
    for(int i=1;i<=5;i++){
        for(int j=1;j<i+1;j++){
            cout<<j; //if i=3 so j prints only 1 & 2
        }
        cout<<"\n"; //or cout<<""<<endl;
    }
    return 0;
}