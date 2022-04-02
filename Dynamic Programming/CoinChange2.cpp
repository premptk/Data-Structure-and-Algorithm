#include<bits/stdc++.h>
using namespace std;
// How many ways to form target if repetition is allowed?

// Recursive Approach
int CoinChange(int ind, vector<int> &arr, int target)
{
    // base case
    if(ind==0)
    {
        return (target%arr[ind]==0);
    }

    int nottake = CoinChange(ind-1, arr, target);
    int take = 0;
    if(arr[ind]<=target)
        take = CoinChange(ind, arr, target-arr[ind]);
    return (take + nottake);
}


// Memoization Approach
int CoinChange2(int ind, vector<int> &arr, int target, vector<vector<int>> &dp)
{
    if(ind==0)
    {
        return (target%arr[0]==0);
    }

    if(dp[ind][target]!=-1)
        return dp[ind][target];
    
    int nottake = CoinChange2(ind-1,arr,target,dp);
    int take = 0;
    if(arr[ind]<=target)
        take = CoinChange2(ind,arr,target-arr[ind],dp);
    return dp[ind][target] = (take + nottake);
}

// Tabulation Approach
int CoinChange3(int n, vector<int> &arr, int target)
{
    vector<vector<int>> dp (n, vector<int> (target+1, 0));
    // base case
    for(int T=0;T<=target;T++)
    {
        dp[0][T] = (T%arr[0]==0);
    }

    for(int ind=1;ind<n;ind++)
    {
        for(int j=0;j<=target;j++)
        {
            int nottake = dp[ind-1][j];
            int take = 0;
            if(arr[ind]<=j)
                take = dp[ind][j-arr[ind]];
            dp[ind][j] = (take + nottake);
        }
    }

    return dp[n-1][target];
}

// Tabulation - Space Optimization
int CoinChange4(int n, vector<int> &arr, int target)
{
    vector<int> prev(target+1,0), cur(target+1,0);

    // base case
    for(int T=0;T<=target;T++)
    {
        prev[T] = (T%arr[0]==0);
    }

    for(int ind=1;ind<n;ind++)
    {
        for(int j=0;j<=target;j++)
        {
            int nottake = prev[j];
            int take = 0;
            if(arr[ind]<=j)
                take = cur[j-arr[ind]];
            cur[j] = (take + nottake);
        }
        prev = cur;
    }

    return prev[target];
}


int main()
{
    vector<int> arr = {1,2,3};
    int n = arr.size();
    int target = 4;
    cout<<CoinChange(n-1,arr,target)<<endl;

    vector<vector<int>> dp (n, vector<int> (target+1,-1));
    cout<<CoinChange2(n-1, arr, target, dp)<<endl;

    cout<<CoinChange3(n,arr,target)<<endl;
    cout<<CoinChange4(n,arr,target)<<endl;
    return 0;
}
