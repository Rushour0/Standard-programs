#include <bits/stdc++.h>
#define ll long long int
#define line cout<<endl;
#define getarr(arr) for(auto &i:arr)cin>>i;
#define putarr(arr) for(auto &i:arr)cout<<i<<" ";
#define swap(x, y) do { typeof(x) SWAP = x; x = y; y = SWAP; } while (0);
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    getarr(arr);
    for( int i = 0;i<n;i++)
    {
        for(int j = 0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            swap(arr[j],arr[j+1]);
        }
    }
    putarr(arr);
    return 0;
}