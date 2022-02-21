#include<bits/stdc++.h>
using namespace std;

// Recursive
int func(int ind, vector<int> &heights, int k)
{
    if(ind==0)
        return 0;
    int minSteps = INT_MAX;
    for(int i=1;i<=k;i++)
    {
        if(ind - i >= 0){
            int first = func(ind - i, heights, k) + abs(heights[ind] - heights[ind-i]);
            minSteps = min(first, minSteps);
        }
    }
    return minSteps;
}

// Memoization
int func2(int ind, vector<int>& height, vector<int>& dp, int k){
    if(ind==0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    
    int mmSteps = INT_MAX;
        
    for(int j=1;j<=k;j++){
        if(ind-j>=0){
      int jump = func2(ind-j, height, dp, k)+ abs(height[ind]- height[ind-j]);
            mmSteps= min(jump, mmSteps);
        }
    }
    return dp[ind]= mmSteps;
    
}

// Tabulation
int func3(int ind, int k, vector<int> &heights)
{
    if(ind==0)
        return 0;
    int n = heights.size();
    vector<int> dp(n,-1);
    dp[0]=0;
    for(int i=1;i<n;i++)
    {
        int minSteps = INT_MAX;
        for(int j=1;j<=k;j++)
        {
            if(i-j >= 0)
            {
                int jump = dp[i-j] + abs(heights[i] - heights[i-j]);
                minSteps = min(minSteps, jump);
            }
        }
        dp[i] = minSteps;
    }
    return dp[n-1];
}


int main()
{
    int n;
    vector<int> heights = {30,10,60,10,60,50};
    n = heights.size();
    int k=2;
    cout<<func(n-1, heights,k)<<endl;

    vector<int> dp(n, -1);
    cout<<func2(n-1,heights,dp,k)<<endl;
    cout<<func3(n-1,k,heights)<<endl;
    return 0;
}
