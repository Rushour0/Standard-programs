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
    int i,j,c;
    for(i = 1;i<n;i++)
    {
        c = i;
        for(j = i-1;j>=0;j--)
        {
            if (arr[j]>arr[c])
            {
                swap(arr[j],arr[c]);
                c--;
            }
            else break;
        }
    }
    putarr(arr);
    return 0;
}
