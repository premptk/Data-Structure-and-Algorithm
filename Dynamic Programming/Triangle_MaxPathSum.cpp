#include<bits/stdc++.h>
using namespace std;

// Recursive Approach
int MinPathSum(int i, int j,int n, vector<vector<int>> &tria)
{
    if(i==n-1)
        return tria[i][j];
    
    else{
        int down = tria[i][j];
        if(i<n) down += MinPathSum(i+1,j,n,tria);
        else down += 1e9;

        int Rdown = tria[i][j];
        if(i<n) Rdown += MinPathSum(i+1,j+1,n,tria);
        else Rdown += 1e9;

        return min(down,Rdown);
    }
}

// Memoization Approach
int MinPathSum2(int i, int j, int n, vector<vector<int>> &tria, vector<vector<int>> &dp)
{
    if(i==n-1)
        return tria[i][j];
    else if(i>n-1 || i>n-1)
        return 1e9;
    else if(dp[i][j]!=-1)
        return dp[i][j];
    else
    {
        int down = tria[i][j] + MinPathSum2(i+1,j,n,tria,dp);
        int Rdown = tria[i][j] + MinPathSum2(i+1,j+1,n,tria,dp);
        return dp[i][j] = min(down,Rdown);
    }
    return 1e9;
}

// Tabulation
int MinPathSum3(int n, vector<vector<int>> &tria)
{
    vector<vector<int>> dp(n,vector<int> (n,0));
    // base case
    for(int j=0;j<n;j++)
        dp[n-1][j] = tria[n-1][j];
    
    for(int i=n-2;i>=0;i--)
    {
        for(int j=i;j>=0;j--)
        {
            int down = tria[i][j] + dp[i+1][j];
            int Rdown = tria[i][j] + dp[i+1][j+1];
            dp[i][j] = min(down,Rdown);
        }
    }
    return dp[0][0];
}

// Tabulation - Space Optimization
int MinPathSum4(int n, vector<vector<int>> &tria)
{
    vector<int> next(n);
    for(int i=0;i<n;i++)
        next[i] = tria[n-1][i];
    
    for(int i=n-2;i>=0;i--)
    {
        vector<int> cur(n,0);
        for(int j=i;j>=0;j--)
        {
            int down = tria[i][j] + next[j];
            int Rdown = tria[i][j] + next[j+1];
            cur[j] = min(down,Rdown);
        }
        next = cur;
    }
    return next[0];
}

int main()
{
    int n=4;
    vector<vector<int>> tria = {{1},{2,3},{4,5,6},{7,8,9,10}};
    cout<<MinPathSum(0,0,n,tria)<<endl;

    vector<vector<int>> dp (n, vector<int> (n,-1));
    cout<<MinPathSum2(0,0,n,tria,dp)<<endl;
    cout<<MinPathSum3(n,tria)<<endl;
    cout<<MinPathSum4(n,tria)<<endl;
    return 0;
}   
