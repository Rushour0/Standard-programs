#include <bits/stdc++.h>
#define ll long long int
#define line cout<<endl;
#define getarr(arr) for(auto &i:arr)cin>>i;
#define putarr(arr) for(auto &i:arr)cout<<i<<" ";
#define getvec(vec) for(auto &i:vec)cin>>i;
#define swap(x, y) do { typeof(x) SWAP = x; x = y; y = SWAP; } while (0);
using namespace std;

void quickSort(int arr[],int left,int right);

int main()
{
    int n,temp;
    cin>>n;
    int arr[n];
    getarr(arr);
    quickSort(arr,0,n-1);
    putarr(arr);
    return 0;
}

int partition(int arr[],int left,int right)
{

    int temp;
    int pivot = arr[left];
    int iterate = left+1;
    for(int curr = left+1;curr<=right;curr++)
    {
        if (arr[curr]<pivot)
        {
            swap(arr[iterate],arr[curr]);
            iterate++;
        }
    }
    swap(arr[left],arr[iterate-1]);
    return iterate-1;

}
void quickSort(int arr[],int left,int right)
{

    if (left>=right)return;
    
    int mid = partition(arr,left,right);
    quickSort(arr,left,mid-1);
    quickSort(arr,mid+1,right);
}