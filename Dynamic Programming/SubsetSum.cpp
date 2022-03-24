#include<bits/stdc++.h>
using namespace std;

// Recursive Approach
bool SubSum1(int ind, int target,vector<int> &arr)
{
    if(target==0)
        return true;

    if(ind==0)
        return (arr[0]==target);
    
    bool nottake = SubSum1(ind-1, target,arr);
    bool take = false;
    if(target >= arr[ind])
        take = SubSum1(ind-1, target-arr[ind], arr);

    return (take || nottake);
}


// Memoization Approach
bool SubSet2(int ind, int target, vector<int>& arr, vector<vector<int>> &dp){
    if(target==0)
        return true;
    
    if(ind == 0)
        return arr[0] == target;
    
    if(dp[ind][target]!=-1)
        return dp[ind][target];
        
    bool notTaken = SubSet2(ind-1,target,arr,dp);
    
    bool taken = false;
    if(arr[ind]<=target)
        taken = SubSet2(ind-1,target-arr[ind],arr,dp);
        
    return dp[ind][target]= notTaken||taken;
}


// Tabulation Approach
bool SubSet3(int n, int k, vector<int> &arr)
{
    vector<vector<bool>> dp (n, vector<bool> (k, false));
    // base case
    for(int i=0;i<n;i++)
    {
        // row = n values
        // column = target
        // first column --> all true as target=0
        dp[i][0] = true;
    }

    // first row for values less than target
    if(arr[0]<=k)
        dp[0][arr[0]] = true;

    for(int ind=1;ind<n;ind++)  // row
    {
        for(int target=1;target<=k;target++)  // column
        {
            bool notTaken = dp[ind-1][target];
            bool taken = false;
            if(arr[ind]<=target)
                taken = dp[ind-1][target-arr[ind]];
            dp[ind][target] = notTaken || taken;
        }
    }
    return dp[n-1][k];
}


// Tabulation - Space Optimization
bool SubSet4(int n, vector<int> &arr, int k)
{
    vector<bool> prev(k+1, false);
    prev[0]=true;
    if(arr[0]<=k)
        prev[arr[0]] = true;

    for(int ind=1;ind<n;ind++)
    {
        vector<bool> cur(k+1, false);
        cur[0] = true;
        for(int target=1;target<=k;target++)
        {
            bool notTaken = prev[target];

            bool taken = false;
            if(arr[ind]<=target)
                taken = prev[target-arr[ind]];
            
            cur[target] = notTaken || taken;
        }
        prev = cur;
    }
    return prev[k];
}

int main()
{
    vector<int> arr = {1,2,3,4};
    int n = arr.size();
    int k = 8;
    cout<<SubSum1(n-1,k,arr)<<endl;

    vector<vector<int>> dp(n , vector<int> (k+1,-1));
    cout<<SubSet2(n-1, k, arr, dp)<<endl;
    cout<<SubSet3(n,k,arr)<<endl;
    cout<<SubSet4(n,arr,k)<<endl;
    return 0;
}
