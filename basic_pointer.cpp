#include<iostream>
using namespace std;
int main()
{
    int a=10;
    int *aptr;
    aptr= &a;
    cout<<&a<<endl;//=2000
    cout<<aptr<<endl; //whatever value is in aptr- 2000
    cout<<*aptr<<endl;//dereferencing my pointer -10
return 0;
}