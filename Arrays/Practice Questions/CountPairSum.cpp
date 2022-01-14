#include<bits/stdc++.h>
using namespace std;

int countPairs(int arr[],int n, int key)
{
    unordered_map<int,int> mp;
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i] > key)
            continue;
        int b = key - arr[i];
        if(mp[b])
        {
            count+=mp[b];
        }
        mp[arr[i]]++;
    }
    return count;
}

int main()
{
    int n;
    int arr[] = {2,6,9,3,4,5,2};
    n = sizeof(arr)/sizeof(arr[0]);
    cout<<countPairs(arr,n,8);
    return 0;
}
