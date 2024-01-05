#include<iostream>
using namespace std;
int main()
{
    int a= 10;
    int *aptr= &a;
    cout<<aptr<<endl; //if 2000
    aptr++;
    cout<<aptr<<endl;// so 2004
return 0;
}