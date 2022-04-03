#include<bits/stdc++.h>
using namespace std;
// Returns Max Weight
// Recursion Approach
int Knapsack(int ind, vector<int> &arr, vector<int> &val, int wt)
{
    if(ind==0)
    {
        if(arr[0]<=wt)
        {
            return (wt/arr[0])*val[0];
        }
        else return -1e9;
    }

    int nottake = 0 + Knapsack(ind-1,arr,val,wt);
    int take = -1e9;
    if(arr[ind]<=wt)
        take = arr[ind] + Knapsack(ind,arr,val,wt-arr[ind]);
    return max(take, nottake);
}


// Memoization Approach
int Knapsack2(int ind, vector<int> &arr, vector<int> &val, int wt, vector<vector<int>> &dp)
{
    if(ind==0)
    {
        if(arr[ind]<=wt)
        {
            return (wt/arr[0])*val[0];
        }
        else return -1e9;
    }

    if(dp[ind][wt]!=-1)
        return dp[ind][wt];

    int nottake = Knapsack2(ind-1,arr,val,wt,dp);
    int take = -1e9;
    if(arr[ind]<=wt)
        take = arr[ind] + Knapsack2(ind, arr, val, wt - arr[ind], dp);
    return dp[ind][wt] = max(nottake, take);
}

// Tabulation Approach
int Knapsack3(int n,vector<int> &arr, vector<int> &val, int wt)
{
    vector<vector<int>> dp (n, vector<int> (wt+1, 0));
    // base case
    for(int i=0;i<=wt;i++)
    {
        if(arr[0] <= wt)
            dp[0][i] = (wt/arr[0])*val[0];
    }

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=wt;j++)
        {
            int nottake = dp[i-1][j];
            int take = -1e9;
            if(arr[i]<=j)
                take = dp[i][j-arr[i]];
            dp[i][j] = max(take, nottake);
        }
    }
    return dp[n-1][wt];
}

// Tabulation - Space Optimization
int Knapsack4(vector<int> &arr, vector<int> &val, int wt)
{
    int n = arr.size();
    vector<int> cur(wt+1,0), prev(wt+1,0);
    // base case
    for(int i=0;i<=wt;i++)
    {
        if(arr[0] <= wt)
            prev[i] = (wt/arr[0])*val[0];
    }

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=wt;j++)
        {
            int nottake = prev[j];
            int take = -1e9;
            if(arr[i]<=j)
                take = cur[j-arr[i]];
            cur[j] = max(take, nottake);
        }
        prev = cur;
    }
    return prev[wt];
}

// Tabulation - Single Array Optimization
int Knapsack5(vector<int> &arr, vector<int> &val, int wt)
{
    int n = arr.size();
    vector<int> prev(wt+1,0);
    // base case
    for(int i=0;i<=wt;i++)
    {
        if(arr[0] <= wt)
            prev[i] = (wt/arr[0])*val[0];
    }

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=wt;j++)
        {
            int nottake = prev[j];
            int take = -1e9;
            if(arr[i]<=j)
                take = prev[j-arr[i]];
            prev[j] = max(take, nottake);
        }
    }
    return prev[wt];
}

int main()
{
    vector<int> arr = {1,2,3};
    vector<int> val = {2,5,5};
    int n = arr.size();
    int wt = 18;
    cout<<Knapsack(n-1,arr,val, wt)<<endl;

    vector<vector<int>> dp (n, vector<int> (wt+1, -1));
    cout<<Knapsack2(n-1,arr,val,wt,dp)<<endl;

    cout<<Knapsack3(n, arr, val, wt)<<endl;
    cout<<Knapsack4(arr,val,wt)<<endl;
    cout<<Knapsack5(arr,val,wt)<<endl;
    return 0;
}
