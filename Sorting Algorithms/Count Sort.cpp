#include <bits/stdc++.h>
#define ll long long int
    #define getarr(arr) for(auto &i:arr)cin>>i;
    #define putarr(arr) for(auto &i:arr)cout<<i<<" ";
#define set0(arr) memset(arr,0,sizeof(arr));
using namespace std;

void countSort(int* arr,int n); 

int main()
{
    int n;
    cin>>n;
    int arr[n];
    getarr(arr);
    countSort(arr,n);
    putarr(arr);    
    return 0;
}

void countSort(int* arr, int n)
{
    int* t = max_element(arr,arr+n-1);
    int max_size = int(*t)+1;
    int total[max_size];
    int place = 0;
    set0(total);
    for(int i = 0;i<n;i++)total[arr[i]]++;
    for(int i = 0;i<max_size;i++)
    {
        while(total[i]--)
        {
            arr[place++] = i;
        }
    }
}