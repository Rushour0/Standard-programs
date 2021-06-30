#include <bits/stdc++.h>
#define ll long long int
#define line cout<<endl;
#define getarr(arr) for(auto &i:arr)cin>>i;
#define putarr(arr) for(auto &i:arr)cout<<i<<" ";
#define swap(x, y) do { typeof(x) SWAP = x; x = y; y = SWAP; } while (0);
using namespace std;

void selectionSort(int* arr,int n);

int main()
{
    int n;
    cin>>n;
    int arr[n];
    getarr(arr);
    selectionSort(arr,n);
    putarr(arr);
    return 0;
}

void selectionSort(int arr[], int n)
{
    int minimum;
    for(int start = 0;start<n;start++)
    {
        minimum = start;
        for(int iterate = start;iterate<n;iterate++)
        {
            if(arr[iterate]<arr[minimum])
            {
                minimum = iterate;
            }
        }
        swap(arr[minimum],arr[start]);
    }
}