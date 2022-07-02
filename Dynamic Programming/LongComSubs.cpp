#include<bits/stdc++.h>
using namespace std;

// Recurrence Approach
int LIS(int ind, int prev_ind, int n, vector<int> &arr)
{
    if(ind == n)
        return 0;

    int nottake = 0 + LIS(ind+1,prev_ind,n,arr); // not take

    int take = -1e9;
    if(prev_ind==-1 || arr[ind]>arr[prev_ind])
        take = 1 + LIS(ind+1,ind,n,arr);  // take
    
    return max(take,nottake);
}


// Memoization Approach
int LIS2(int ind, int prev_ind, int n, vector<int> &arr, vector<vector<int>> &dp)
{
    if(ind == n)
        return 0;

    if(dp[ind][prev_ind+1]!=-1)
        return dp[ind][prev_ind+1];

    int nottake = 0 + LIS2(ind+1,prev_ind,n,arr,dp); // not take

    int take = -1e9;
    if(prev_ind==-1 || arr[ind]>arr[prev_ind])
        take = 1 + LIS2(ind+1,ind,n,arr,dp);  // take
    
    return dp[ind][prev_ind+1] = max(take,nottake);
}


// Tabulation Approach
int LIS3(int n, vector<int> &arr)
{
    vector<vector<int>> dp(n+1,vector<int> (n+1,0));

    for(int ind=n-1;ind>=0;ind--)
    {
        for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--)
        {
            int nottake = 0 + dp[ind+1][prev_ind+1]; // not take

            int take = -1e9;
            if(prev_ind == -1 || arr[ind]>arr[prev_ind])
                take = 1 + dp[ind+1][ind+1];  // take
            
            dp[ind][prev_ind+1] = max(take,nottake);
        }
    }
    return dp[0][-1+1];    
}

// Tabulation - Space Optimization Approach
int LIS4(int n, vector<int> &arr)
{
    vector<int> curr(n+1,0), next(n+1,0);

    for(int ind=n-1;ind>=0;ind--)
    {
        for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--)
        {
            int nottake = 0 + next[prev_ind+1]; // not take

            int take = -1e9;
            if(prev_ind == -1 || arr[ind]>arr[prev_ind])
                take = 1 + next[ind+1];  // take
            
            curr[prev_ind+1] = max(take,nottake);
        }
        next = curr;
    }
    return next[0];    
}

// Another Space Optimized Approach
int LIS5(int n, vector<int> &arr)
{
    vector<int> dp(n,1), hash(n);
    int maxi = 1;
    int last = 0;
    for(int i=0;i<n;i++)
    {
        hash[i] = i;
        for(int prev=0;prev<i;prev++)
        {
            if(arr[prev] < arr[i] && dp[i] < 1+dp[prev])
            {
                dp[i] = 1+dp[prev];
                hash[i] = prev;
            }
        }
        if(dp[i] > maxi)
        {
            maxi = dp[i];
            last = i;
        }
    }
    vector<int> temp;
    temp.push_back(arr[last]);
    while(hash[last]!=last)
    {
        last = hash[last];
        temp.push_back(arr[last]);
    }
    reverse(temp.begin(),temp.end());
    for(auto it : temp)
        cout<<it<<" ";
    return maxi;
}



int main()
{
    int n=7;
    vector<int> arr = {10,9,2,5,3,7,101,50};
    cout<<LIS(0,-1,n,arr)<<endl;

    vector<vector<int>> dp(n, vector<int> (n,-1));
    cout<<LIS2(0,-1,n,arr,dp)<<endl;
    cout<<LIS3(n,arr)<<endl;
    cout<<LIS4(n,arr)<<endl;
    cout<<LIS5(n,arr)<<endl;
    return 0;
}
