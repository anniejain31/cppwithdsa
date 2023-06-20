#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int sum=0;
    int originaln=n;
    while(n>0){
        int lastdigit= n%10;
        sum+= pow(lastdigit, 3); //for cube 
        n=n/10;
    }
    if(sum==originaln){
        cout<<"Armstrong no."<<endl;
    }
    else{
        cout<<"Not armstrong no."<<endl;
    }
return 0;
}