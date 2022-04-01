#include<bits/stdc++.h>
using namespace std;

// Recursive Approach
int MinCoin(int ind, vector<int> &arr, int target)
{
    // base case
    if(ind==0)
    {
        if(target==0)
            return 0;
        else if(target%arr[ind]==0)
            return target/arr[ind];
        else return 1e9;
    }

    int nottake = 0 + MinCoin(ind-1,arr,target);
    int take = 1e9;
    if(arr[ind]<=target)
        take = 1 + MinCoin(ind,arr, target-arr[ind]);
    return min(take, nottake);
}


// Memoization Approach
int MinCoin2(int ind, vector<int> &arr, int target, vector<vector<int>> &dp)
{
    // base case
    if(ind==0)
    {
        if(target==0)
            return 0;
        if(target%arr[ind]==0)
            return target/arr[ind];
        else
            return 1e9;
    }

    if(dp[ind][target]!=-1)
        return dp[ind][target];

    int nottake = 0 + MinCoin2(ind-1, arr, target, dp);
    int take = 1e9;
    if(arr[ind]<=target)
        take = 1 + MinCoin2(ind, arr, target - arr[ind], dp);

    return dp[ind][target] = min(take, nottake);
}


// Tabulation Approach
int MinCoins3(int n, vector<int> &arr, int T)
{
    vector<vector<int>> dp (n, vector<int> (T+1, 0));
    
    // base case
    for(int i=0;i<=T;i++)
    {
        if(i%arr[0] == 0)
            dp[0][i] = i/arr[0];
        else   
            dp[0][i] = 1e9;
    }

    for(int ind = 1; ind<n; ind++){
        for(int target = 0; target<=T; target++){
            
            int notTake = 0 + dp[ind-1][target];
            int take = 1e9;
            if(arr[ind]<=target)
                take = 1 + dp[ind][target - arr[ind]];
                
             dp[ind][target] = min(notTake, take);
        }
    }

    return dp[n-1][T];
}


// Tabulation - Space Optimization
int MinCoins4(int n, vector<int> &arr, int T)
{
    vector<int> prev(T+1,0), cur(T+1, 0);
    // base case
    for(int i=0;i<=T;i++)
    {
        if(i%arr[0] == 0)
            prev[i] = i/arr[0];
        else   
            prev[i] = 1e9;
    }

    for(int ind = 1; ind<n; ind++){
        for(int target = 0; target<=T; target++){
            
            int notTake = 0 + prev[target];
            int take = 1e9;
            if(arr[ind]<=target)
                take = 1 + cur[target - arr[ind]];
                
            cur[target] = min(notTake, take);
        }
        prev = cur;
    }

    return prev[T];
}


int main()
{
    vector<int> arr = {1,2,3};
    int target = 10;
    int n = arr.size();
    cout<<MinCoin(n-1, arr,target)<<endl;

    vector<vector<int>> dp(n, vector<int> (target+1, -1));
    cout<<MinCoin2(n-1,arr,target, dp)<<endl;

    cout<<MinCoins3(n,arr,target)<<endl;
    cout<<MinCoins4(n,arr,target)<<endl;
    return 0;
}
