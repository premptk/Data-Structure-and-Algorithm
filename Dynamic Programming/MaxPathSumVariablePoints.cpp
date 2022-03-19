#include<bits/stdc++.h>
using namespace std;

// Recursive Approach
int MaxPathSum1conti(int i, int j,int m, vector<vector<int>> &grid)
{
    if(j<0 || j>=m)
        return -1e9;
    else if(i==0)
        return grid[0][j];

    int s = grid[i][j] + MaxPathSum1conti(i-1,j,m,grid);
    int l = grid[i][j] + MaxPathSum1conti(i-1,j-1,m,grid);
    int r = grid[i][j] + MaxPathSum1conti(i-1,j+1,m,grid);
    return max(s, max(l,r));
}

int MaxPathSum1(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int maxi = INT_MIN;
    for(int j=0;j<m;j++)
    {
        int ans = MaxPathSum1conti(n-1,j,m,grid);
        maxi = max(maxi,ans);
    }
    return maxi;
}


// Memoization Approach
int MaxPathSum2conti(int i, int j, int m, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if(j<0 || j>=m)
        return -1e9;
    else if(i==0)
        return grid[0][j];
    else if(dp[i][j]!=-1)
        return dp[i][j];

    int s = grid[i][j] + MaxPathSum2conti(i-1,j,m,grid,dp);
    int l = grid[i][j] + MaxPathSum2conti(i-1,j-1,m,grid,dp);
    int r = grid[i][j] + MaxPathSum2conti(i-1,j+1,m,grid,dp);
    return dp[i][j] = max(s,max(l,r));
}

int MaxPathSum2(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n,vector<int> (n,-1));
    int maxi = INT_MIN;
    for(int j=0;j<m;j++)
    {
        int ans = MaxPathSum2conti(n-1,j,m,grid,dp);
        maxi = max(maxi,ans);
    }
    return maxi;
}


// Tabulation
int MaxPathSum3(int n, vector<vector<int>> &grid)
{
    vector<vector<int>> dp (n,vector<int> (n,0));
    // base case
    for(int j=0;j<n;j++)
        dp[0][j] = grid[0][j];
    
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int up = grid[i][j] + dp[i-1][j];
            
            int left = grid[i][j];
            if(j-1>=0) left += dp[i-1][j-1];
            else left += -1e9;

            int right = grid[i][j];
            if(j+1<n) right += dp[i-1][j+1];
            else right += -1e9;

            dp[i][j] = max(up, max(left, right));
        }
    }
    int maxi = INT_MIN;
    for(int j=0;j<n;j++)
        maxi = max(maxi, dp[n-1][j]);
    
    return maxi;
 }


// Tabulation - Space Optimization
int MaxPathSum4(int n, vector<vector<int>> &grid)
{
    // base case
    vector<int> prev (n);
    for(int j=0;j<n;j++)
        prev[j] = grid[0][j];
    
    for(int i=1;i<n;i++)
    {
        vector<int> cur(n,0);
        for(int j=0;j<n;j++)
        {
            int up = grid[i][j] + prev[j];
            
            int left = grid[i][j];
            if(j-1>=0) left += prev[j-1];
            else left += -1e9;

            int right = grid[i][j];
            if(j+1<n) right += prev[j+1];
            else right += -1e9;

            cur[j] = max(up, max(left, right));
        }
        prev = cur;
    }
    
    int maxi = INT_MIN;
    for(int j=0;j<n;j++)
        maxi = max(maxi, prev[j]);
    return maxi;
}

int main()
{
    int n=4,m=4;
    vector<vector<int>> grid = {{1,2,10,4},{100,3,2,1},{1,1,20,2},{1,2,2,1}};
    cout<<MaxPathSum1(grid)<<endl;
    cout<<MaxPathSum2(grid)<<endl;
    cout<<MaxPathSum3(n,grid)<<endl;
    cout<<MaxPathSum4(n,grid)<<endl;
    return 0;
}
