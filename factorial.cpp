#include <iostream>
using namespace std;

int main() {
    unsigned long long int i,n,factorial=1;
    cout<<"enter a positive number: ";
    cin>>n;
    if(n<0){
        cout<<"Error! Factorial of a negative number doesn't exist.";
    }
    else if(n==0 or n==1){
        cout<<"1"<<endl;
    }
        else{
        for(i=1; i<=n; +i++){
            factorial = factorial * i;
        }
        cout<<"Factorial of "<< n << "= "<< factorial;
    }
    return 0;
}

