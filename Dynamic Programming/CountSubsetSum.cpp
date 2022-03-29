#include<bits/stdc++.h>
using namespace std;

// Recursive Approach
int Pick1(int n, vector<int> &arr, int k)
{
    if(n==0)
    {
        if(k==0)
            return 1;
        else
            return (arr[0]==k);
    }

    int notpick = Pick1(n-1,arr,k);
    int pick = 0;
    if(arr[n]<=k)
        pick = Pick1(n-1,arr,k-arr[n]);

    return notpick + pick;
}


// Memoization Approach
int Pick2(int n, vector<int> &arr, int k, vector<vector<int>> &dp)
{
    if(n==0)
    {
        if(k==0)
            return 1;
        else 
            return (arr[n]==k);
    }

    if(dp[n][k]!=-1)
        return dp[n][k];

    int notpick = Pick2(n-1,arr,k,dp);
    int pick = 0;
    if(arr[n]<=k)
        pick = Pick2(n-1,arr,k-arr[n],dp);

    return dp[n][k] = (pick + notpick);
}


// Tabulation Approach
int Pick3(int n, vector<int> &arr,int k)
{
    vector<vector<int>> dp (n, vector<int> (k+1, 0));
    // base case
    for(int i=0;i<n;i++)
        dp[i][0] = 1;
    
    if(arr[0]<=k)
        dp[0][arr[0]] = 1;

    for(int ind=1;ind<n;ind++)
    {
        for(int sum=0;sum<=k;sum++)
        {
            int notpick = dp[ind-1][sum];
            int pick = 0;
            if(arr[ind]<=sum)
                pick = dp[ind-1][sum-arr[ind]];

            dp[ind][sum] = pick + notpick;
        }
    }
    return dp[n-1][k];
}


// Tabulation - Space Optimization
int Pick4(int n, vector<int> &arr, int k)
{
    vector<int> cur(k+1, 0), prev(k+1,0);
    // base case
    for(int i=0;i<n;i++)
        prev[0] = 1;
    
    if(arr[0]<=k)
        prev[arr[0]] = 1;

    for(int ind=1;ind<n;ind++)
    {
        prev[0] = cur[0] = 1;
        for(int sum=0;sum<=k;sum++)
        {
            int notpick = prev[sum];
            int pick = 0;
            if(arr[ind]<=sum)
                pick = prev[sum-arr[ind]];

            cur[sum] = pick + notpick;
        }
        prev = cur;
    }
    return prev[k];
}


int main()
{
    vector<int> arr = {1,2,2,3};
    int n = arr.size();
    int k = 3;
    cout<<Pick1(n-1,arr,k)<<endl;
    vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
    cout<<Pick2(n-1,arr,k,dp)<<endl;
    cout<<Pick3(n,arr,k)<<endl;
    cout<<Pick4(n,arr,k)<<endl;
    return 0;
}
