#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cout<<"Enter a size of array\n";
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int mx = arr[0];
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i]>mx)
        {
            ans+=1;
            mx=max(mx, arr[i]);
        }
    }
    cout<<"Record Breaking days is: "<<ans<<endl;
    cout<<"Maximum visitor in a day is: "<<mx<<endl;
    return 0;
}