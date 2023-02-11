#include<iostream>
using namespace std;
int main()
{
    int row, col;
    cin>>row>>col;
    for(int i=1;i<=row;i++){
        for(int j=1;j<=col;j++){
            if(i==1 || i==row || j==1 || j==col){
                cout<<"* "; //so 2 space here
            }
            else{
                cout<<"  "; //if 1 space after star so see line 10
            }
        }
        cout<<endl; // cout<<"\n";
    }
return 0;
}