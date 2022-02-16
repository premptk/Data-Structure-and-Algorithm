#include<bits/stdc++.h>
using namespace std;

int solveDiff(vector<int> &arr, int low, int high, int diff)
{
    int mid;
    while(low<=high)
    {
        mid = (low+high)/2;
        if((arr[mid]-arr[0])/diff==mid)
            low=mid+1;
        else
            high=mid-1;
    }
    return arr[high]+diff;
}

int solve(vector<int> &arr)
{
    int n=arr.size();
    int diff = (arr[n-1]-arr[0])/n;
    return solveDiff(arr,0,n-1,diff);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> arr = {2, 4, 8, 10, 12, 14};
    cout<<solve(arr);
    return 0;
}
