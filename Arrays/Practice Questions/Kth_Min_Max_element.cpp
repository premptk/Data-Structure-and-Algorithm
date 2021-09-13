#include<bits/stdc++.h>
using namespace std;

int lomuto(int arr[], int n)
{
    // Quicksort uses partition technique which sets value k to its original position respective of the state of rest array (sorted or not sorted)
    srand(time(NULL));
    int random = 0 + rand() % (n-1 - 0);
    // using random pivot values so that value of pivot changes for every call
    int pivot = arr[random];
    
    int i=-1,j=n; 
    while(true)
    {
        do
        {
            i++;
        } while (arr[i] < pivot);
        do
        {
            j--;
        } while (arr[j] > pivot);
        if(i>j) return i;
        swap(arr[i],arr[j]);
    }
}

int solve(int arr[], int n, int k)
{
    int ans = lomuto(arr,n);
    while(n-k != ans)
    {   
        ans = lomuto(arr,n);
    }
    return arr[ans]; 
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    int arr[] = {13,12,4,10,6,2};   
    n = sizeof(arr)/sizeof(arr[0]);
    int k=2;
    if(k < n)
        cout<<solve(arr,n,k);
    cout<<"\n";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}

// Output
// 12
// 2 4 6 10 12 13
