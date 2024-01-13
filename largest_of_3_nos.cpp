#include<iostream>
using namespace std;
int main()
{
    int a,b,c;
    cout<<"Enter the 3 nos."<<endl;
    cin>>a>>b>>c;
    cout<<"The largest of 3 nos. is: "<<endl;
    if(a>b){
        if(a>c)
        {
            cout<<a<<endl;
        }
        else{
            cout<<c<<endl;
        }
    }
    else if(b>c){
        if(b>a)
        {
            cout<<b<<endl;
        }
        else{
            cout<<a<<endl;
        }
    }
    else{
        cout<<c<<endl;
    }
    return 0;
}