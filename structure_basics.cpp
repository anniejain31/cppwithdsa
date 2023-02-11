#include <stdio.h>
#include <iostream>
using namespace std;
struct Rectangle
{
    int length;
    int breadth;
    char x;
};
int main(){
    // struct Rectangle r1;
    struct Rectangle r1={10,5};
    //printf("%lu", sizeof(r1)); //or %d
    r1.length=2;
    r1.breadth=9;
    //printf("area of rectangle is: %d", r1.length * r1.breadth);
    cout<<r1.length<<endl;
    cout<<r1.breadth<<endl;
    return 0;
}