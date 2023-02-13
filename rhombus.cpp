#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i;j++){
            cout<<"  ";// so 2 space here
        }
        for(int j=1;j<=n;j++){
            cout<<"* "; //1 space here so line 9
        }
        cout<<endl;
    }
return 0;
}