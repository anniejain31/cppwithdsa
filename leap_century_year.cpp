#include<iostream>
using namespace std;
int main()
{
    int num;
    cout<<"Enter year:"<<endl;
    cin>>num;

    if(num%4==0 && num%100==0)
    {
        cout<<"leap and century year"<<endl;
    }
    else if(num%4==0)
    {
        cout<<"leap year"<<endl;
    }
    else{
        cout<<"not a leap year"<<endl;
    }
    return 0;
}