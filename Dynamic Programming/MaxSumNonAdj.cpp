#include<bits/stdc++.h>
using namespace std;

// Recursive Approach
int func(int n, vector<int> &nums)
{
    if(n==0)  return nums[0];
    if(n<0) return 0;
    int take = nums[n] + func(n-2, nums);
    int nottake = func(n-1, nums);
    return max(take, nottake);
}

// Memoization
int func2(int n, vector<int> &nums, vector<int> &dp)
{
    if(n==0)    return nums[0];
    if(n<0)     return 0;
    if(dp[n]!=-1) return dp[n];
    int take = nums[n] + func2(n-2, nums, dp);
    int nottake = func2(n-1, nums, dp);
    return dp[n] = max(take, nottake);
}

// Tabulation
int func3(int n, vector<int> &nums)
{
    vector<int> dp(n,-1);
    dp[0]=nums[0];
    for(int i=1;i<n;i++)
    {
        int take = nums[i];
        if(i>1) take+=dp[i-2];
        int nottake = dp[i-1];
        dp[i] = max(take, nottake);
    }
    return dp[n-1];
}

// Tabulation - Space Optimization
int func4(int n, vector<int> &nums)
{
    int prev = nums[0];
    int prev2=0;
    int curi;
    for(int i=1;i<n;i++)
    {
        int pick = nums[i] + prev2;
        int notpick = prev;
        curi = max(pick, notpick);
        prev2 = prev;
        prev = curi;
    }
    return prev;
}

int main()
{
    vector<int> nums = {2,1,4,9};
    int n=nums.size();
    cout<<func(n-1, nums)<<endl;
    vector<int> dp(n,-1);
    dp[0]=0;
    cout<<func2(n-1, nums, dp)<<endl;
    cout<<func3(n,nums)<<endl;
    cout<<func4(n,nums)<<endl;
    return 0;
}
