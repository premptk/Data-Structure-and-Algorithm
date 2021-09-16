#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> arr)
{
    int n = arr.size();
    int low=0,mid=0,high=n-1;
    while(mid<=high)
    {
        switch(arr[mid]){
        case 0: swap(arr[low++],arr[mid++]);
                break;
        case 1: mid++;
                break;
        case 2: swap(arr[mid],arr[high--]);
                break;
        }
    }
    for(auto it : arr)
        cout<<it<<" ";
}

int main()
{
    vector<int> arr = {1,0,1,2,2,0,1};
    solve(arr);
    // 0 0 1 1 1 2 2 
    return 0;
}
