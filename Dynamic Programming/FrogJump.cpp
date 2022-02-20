#include<bits/stdc++.h>
using namespace std;

// Recursive code
int func1(int ind, vector<int> &heights)
{
    if(ind==0)
        return 0;
    int left = func1(ind-1, heights) + abs(heights[ind]-heights[ind-1]);
    int right = INT_MAX;
    if(ind>1)
    {
        right = func1(ind-2, heights) + abs(heights[ind]-heights[ind-2]);
    }
    return min(left, right);
}

// Memoization
int func2(int ind, vector<int> &heights, vector<int> &dp)
{
    if(ind==0)
        return 0;
    if(dp[ind]!=-1)
        return dp[ind];
    int first = func2(ind-1, heights, dp) + abs(heights[ind] - heights[ind-1]);
    int second=INT_MAX;
    if(ind>1)
        second = func2(ind-2, heights, dp) + abs(heights[ind] - heights[ind-2]);
    return dp[ind] = min(first,second);
}

// Tabulation
int func3(int n, vector<int> &heights)
{
    if(n==0)
        return 0;
    vector<int> dp(n,-1);
    dp[0]=0;
    for(int i=1;i<n;i++)
    {
        int second = INT_MAX;
        int first = dp[i-1] + abs(heights[i] - heights[i-1]);
        if(i>1)
            second = dp[i-2] + abs(heights[i-2] - heights[i]);
        dp[i] = min(first, second);
    }
    return dp[n-1];
}

// Tabulation (Space Optimization)
int func4(int n, vector<int> &heights)
{
    int prev=0,prev2=0;
    for(int i=1;i<n;i++)
    {
        int ss=INT_MAX;
        int fs = prev + abs(heights[i]-heights[i-1]);
        if(i>1)
            ss = prev2 + abs(heights[i]-heights[i-2]);
        int curi = min(fs, ss);
        prev2 = prev;
        prev = curi;
    }
    return prev;
}

int main()
{
    vector<int> heights = {30,10,60,10,60,50};
    int n = sizeof(heights)/sizeof(heights[0]);
    cout<<func1(n-1,heights)<<endl;
    vector<int> dp(n+1, -1);
    cout<<func2(n-1, heights,dp)<<endl;
    cout<<func3(n, heights)<<endl;
    cout<<func4(n,heights)<<endl;
    return 0;
}
