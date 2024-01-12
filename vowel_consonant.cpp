#include<iostream>
using namespace std;
int main()
{
    char word;
    cout<<"Enter Alphabet:"<<endl;
    cin>>word;
    if(word=='a' or word=='e' or word=='i' or word=='o' or word=='u' or word=='A' or word=='E' or word=='I' or word=='O' or word=='U' )
    {
        cout<<"VOWEL"<<endl;
    }
    else{
        cout<<"CONSONANT"<<endl;
    }
    return 0;
}