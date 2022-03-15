#include<bits/stdc++.h>
using namespace std;

// Recursive Approach
int MinPathSum(int i, int j, vector<vector<int>> &grid)
{
    if(i==0 && j==0)
        return grid[i][j];
    if(i<0 || j<0)
        return 1e9;
    int left = grid[i][j] + MinPathSum(i,j-1,grid);
    int up = grid[i][j] + MinPathSum(i-1,j,grid);
    return min(up,left);
}


// Memoization Approach
int MinPathSum2(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if(i==0 && j==0)
        return grid[i][j];
    if(i<0 || j<0)  return 1e9;
    if(dp[i][j]!=-1) return dp[i][j];
    int up = grid[i][j] + MinPathSum2(i-1,j,grid,dp);
    int left = grid[i][j] + MinPathSum2(i,j-1,grid,dp);
    return dp[i][j] = min(up,left);
}

// Tabulation Approach
int MinPathSum3(int n, int m, vector<vector<int>> &grid)
{
    int dp[n][m] = {0};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i==0 && j==0)
                dp[i][j]=grid[i][j];
            else{
                int up = grid[i][j];
                if(i>0) up += dp[i-1][j];
                else up += 1e9;

                int left = grid[i][j];
                if(j>0) left += dp[i][j-1];
                else left += 1e9;

                dp[i][j] = min(up, left);
            }
        }
    }
    return dp[n-1][m-1];
}

// Tabulation - Space Optimization
int MinPathSum4(int n, int m, vector<vector<int> > &grid){
      vector<int> prev(m,0);
    for(int i=0; i<n ; i++){
        vector<int> temp(m,0);
        for(int j=0; j<m; j++){
            if(i==0 && j==0) temp[j] = grid[i][j];
            else{
                
                int up = grid[i][j];
                if(i>0) up += prev[j];
                else up += 1e9;
                
                int left = grid[i][j];
                if(j>0) left+=temp[j-1];
                else left += 1e9;
                
                temp[j] = min(up,left);
            }
        }
        prev=temp;
    }
    
    return prev[m-1];
    
}

int main()
{
    int n=2,m=3;
    vector<vector<int>> grid = {{5,9,6}, {11,5,2}};
    cout<<MinPathSum(n-1,m-1,grid)<<endl;

    vector<vector<int>> dp (n, vector<int> (m,-1));
    cout<<MinPathSum2(n-1,m-1,grid,dp)<<endl;

    cout<<MinPathSum3(n,m,grid)<<endl;
    cout<<MinPathSum4(n,m,grid)<<endl;
    return 0;
}   
