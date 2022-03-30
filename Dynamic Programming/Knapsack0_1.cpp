#include<bits/stdc++.h>
using namespace std;

// Recursive Approach
int Knapsack1(int ind, int wt,vector<int> &arr, vector<int> &val)
{
    if(ind==0)
    {
        if(arr[0]<=wt)
            return val[0];
        else 
            return 0;
    }

    int notTake = Knapsack1(ind-1, wt, arr,val);
    int take = INT_MIN;
    if(arr[ind]<=wt)
        take = val[ind] + Knapsack1(ind-1,wt-arr[ind],arr,val);
    return max(notTake,take);
}


// Memoization Approach
int Knapsack2(int ind, int wt, vector<int> &arr, vector<int> &val, vector<vector<int>> &dp)
{
    if(ind == 0)
    {
        if(arr[0]<=wt)
            return val[0];
        else
            return 0;
    }

    if(dp[ind][wt]!=-1)
        return dp[ind][wt];

    int notTake = 0 + Knapsack2(ind-1,wt,arr,val,dp);
    int take = INT_MIN;
    if(arr[ind]<=wt)
        take = val[ind] + Knapsack2(ind-1, wt-arr[ind], arr, val, dp);

    return dp[ind][wt] = max(take, notTake);
}


// Tabulation Approach
int Knapsack3(int n, int wt, vector<int> &arr, vector<int> &val)
{
    vector<vector<int>> dp (n, vector<int> (wt+1, -1));
    // base case
    for(int i=arr[0];i<=wt;i++)
        dp[0][i] = val[0];
    
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=wt;j++)
        {
            int notTake = dp[i-1][j];
            int take = INT_MIN;
            if(arr[i]<=j)
                take = val[i] + dp[i-1][j-arr[i]];
            dp[i][j] = max(take, notTake);
        }
    }
    return dp[n-1][wt];
}


// Tabulation Approach - Space Optimization
int Knapsack4(int n, int wt, vector<int> &arr, vector<int> &val)
{
    vector<int> cur(wt+1, 0), prev(wt+1, 0);
    // base case
    for(int i=arr[0];i<=wt;i++)
        prev[i] = val[0];
    
    for(int i=1;i<n;i++)
    {
        for(int cap=wt; cap>=0; cap--){
            
            int notTaken = 0 + prev[cap];
            
            int taken = INT_MIN;
            if(arr[i] <= cap)
                taken = val[i] + prev[cap - arr[i]];
                
            prev[cap] = max(notTaken, taken);
        }
    }
    return prev[wt];
}


int main()
{
    vector<int> arr = {3,2,5};
    vector<int> val = {30,40,60};
    int wt=6;
    int n=3;
    cout<<Knapsack1(n-1,wt,arr,val)<<endl;
    vector<vector<int>> dp(n+1, vector<int> (wt+1, -1));
    cout<<Knapsack2(n-1,wt,arr,val,dp)<<endl;
    cout<<Knapsack3(n, wt, arr, val)<<endl;
    cout<<Knapsack4(n,wt,arr,val)<<endl;
    return 0;
}
