#include<bits/stdc++.h>
#define ll long long int
#define getarr(arr) for(auto &i:arr)cin>>i;
#define putarr(arr) for(auto &i:arr)cout<<i<<" ";
using namespace std;

void merge(int* arr, int l, int m, int r)
{
    int nL = m - l + 1;
    int nR = r - m;
    int L[nL],R[nR];
    for(int i = 0;i<nR+2;i++)
    {
        if (i<nL)L[i] = arr[l+i];
        if (i<nR)R[i] = arr[m+i+1];
    }
    int i = 0,j = 0,k=l;
    while (k-l<r-l+1)
    {
        if (i<nL and j<nR)
        {
            if (L[i]<=R[j])
            {
                arr[k] = L[i];
                i++;
            }
            else
            {
                arr[k] = R[j];
                j++;
            }
        }
        else
        {
            if (i<nL)
            {
                arr[k] = L[i];
                i++;
            }
            if (j<nR)
            {
                arr[k] = R[j];
                j++;
            }
        }
        k++;
    }
}
void mergeSort(int* arr, int l, int r)
{
    int half = (l+r)/2;
    if (l>=r)return;
    mergeSort(arr,l,half);
    mergeSort(arr,half+1,r);
    merge(arr,l,half,r);
}
int main()
{
    ll n;
    cin>>n;
    int arr[n];  
    getarr(arr);
    mergeSort(arr,0,n-1);
    putarr(arr);
    return 0;
}