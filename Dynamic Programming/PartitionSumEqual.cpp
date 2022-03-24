#include<bits/stdc++.h>
using namespace std;

// Recursive Approach
bool SubSum(int ind, vector<int> &arr, int k)
{
    if(k == 0)
        return true;

    if(ind == 0)
        return (arr[0]==k);

    bool notTake = SubSum(ind-1, arr, k);

    bool take = false;
    if(arr[ind] <= k)
        take = SubSum(ind-1, arr, k-arr[ind]);
    
    return (take || notTake);
}

// Memoization Approach
bool SubSum2(int ind, vector<int> &arr, int k, vector<vector<int>> &dp)
{
    if(k==0)
        return true;
    
    if(ind == 0)
        return (arr[0]==k);
    
    if(dp[ind][k]!=-1)
        return dp[ind][k];

    bool notTake = SubSum2(ind-1, arr, k, dp);
    bool take = false;
    if(arr[ind]<=k)
        take = SubSum2(ind-1, arr,k-arr[ind],dp);
    return dp[ind][k] = (take || notTake);
}

// Tabulation Approach
bool SubSum3(int n, vector<int> &arr, int k)
{
    vector<vector<bool>> dp(n, vector<bool> (k+1, -1));

    // for target = 0 
    for(int i=0;i<n;i++)
        dp[0][i]=true;

    if(arr[0] <= k)
        dp[0][arr[0]] = true;
    
    for(int ind=1;ind<n;ind++)
    {
        for(int target=1;target<=k;target++)
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
bool SubSum4(int n, vector<int> &arr, int k)
{
    vector<bool> prev(k+1,false);
    
    prev[0] = true;
    if(arr[0]<=k)
        prev[arr[0]] = true;
    

    for(int ind=1;ind<n;ind++)
    {
        vector<bool> cur(k+1,false);
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

void EqualSum(vector<int> &arr)
{
    int n = arr.size();
    int sum=0;
    for(auto it : arr)
        sum += it;

    if(sum%2!=0)
        cout<<false;
    else{
        cout<<SubSum(n-1,arr,sum/2)<<endl;

        vector<vector<int>> dp(n, vector<int> (sum/2+1,-1));
        cout<<SubSum2(n-1,arr,sum/2, dp)<<endl;

        cout<<SubSum3(n,arr,sum/2)<<endl;

        cout<<SubSum4(n,arr,sum/2)<<endl;
    }
}

int main()
{
    vector<int> arr = {1,2,3,4};
    EqualSum(arr);
    return 0;
}
