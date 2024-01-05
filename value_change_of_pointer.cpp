#include<iostream>
using namespace std;
int main()
{
    int a=10;
    int* aptr= &a;
    cout<<*aptr<<endl;
    *aptr= 20; // to change value of a without changing a
    cout<<a<<endl;
return 0;
}
// by using pointer we can access as well as modify variable
