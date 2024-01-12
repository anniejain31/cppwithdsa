#include<iostream>
using namespace std;
int main()
{
    int num, sum=0;
    float avg;
    cout<<"Enter the 10 numbers\n";
    for(int i=1;i<=10;i++)
    {
        cout<<"number"<<i<<"= ";
        cin>>num;
        sum= sum + num;
    }
    avg= sum/10.0;
    cout<<"sum is: "<<sum<<endl;
    cout<<"avg is: "<<avg<<endl;
}
