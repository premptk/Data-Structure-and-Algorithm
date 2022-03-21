#include<bits/stdc++.h>
using namespace std;

// Recursive Approach
int CherryPickup1(int i, int j1, int j2, int n, int m,vector<vector<int>> &grid)
{
    if(j1<0 || j1>=m || j2<0 || j2>=m)
        return -1e8;
    if(i == n-1)
    {
        if(j1==j2)
            return grid[i][j1];
        else return grid[i][j1] + grid[i][j2];
    }
        // Explore paths
    int maxi = -1e8;
        for(int dj1=-1;dj1<= +1; dj1++)
        {
            for(int dj2 = -1; dj2 <= +1; dj2++)
            {
                int val = 0;
                if(j1 == j2)
                    val = grid[i][j1];
                else
                    val = grid[i][j1] + grid[i][j2];
                val += CherryPickup1(i+1, j1+dj1, j2+dj2, n, m, grid);

                maxi = max(maxi, val);
            }
        }
    return maxi;
}

// Memoization Approach
int CherryPickup2(int i, int j1, int j2, int n, int m, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
{
    if(j1<0 || j1>=m || j2<0 || j2>=m)
        return -1e8;
    if(i==n-1)
    {
        if(j1 == j2)
            return grid[i][j1];
        else return grid[i][j1] + grid[i][j2];
    }

    if(dp[i][j1][j2]!=-1)
        return dp[i][j1][j2];

    int maxi = -1e8;
    for(int dj1 = -1;dj1 <= 1;dj1++)
    {
        for(int dj2=-1;dj2<=1;dj2++)
        {
            int val=0;
            if(dj1 == dj2)
                val = grid[i][j1];
            else val = grid[i][j1] + grid[i][j2];

            val += CherryPickup2(i+1, j1+dj1, j2+dj2, n, m, grid, dp);
            maxi = max(maxi, val);
        }
    }
    return dp[i][j1][j2] = maxi;
}


// Tabulation Approach
int CherryPickup3(int n, int m, vector<vector<int>> &grid)
{
    vector<vector<vector<int>>> dp(n, vector<vector<int>> (m,vector<int> (m, -1)));
    // base case
    for(int j1=0;j1<m;j1++)
    {
        for(int j2=0;j2<m;j2++)
        {
            if(j1==j2)
                dp[n-1][j1][j2] = grid[n-1][j1];
            else
                dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
        }
    }

    for(int i=n-2;i>=0;i--)
    {
        for(int j1=0;j1<m;j1++)
        {
            for(int j2=0;j2<m;j2++)
            {
                int maxi=-1e8;
                for(int dj1=-1;dj1<=1;dj1++)
                {
                    for(int dj2=-1;dj2<=1;dj2++)
                    {
                        int val=0;
                        if(j1==j2)
                            val = grid[i][j1];
                        else
                            val = grid[i][j1] + grid[i][j2];
                        
                        if(j1+dj1>=0 && j1+dj1<m && j2+dj2>=0 && dj2+j2<m)
                            val += dp[i+1][j1+dj1][j2+dj2];
                        else
                            val += -1e8;
                        maxi = max(maxi,val);
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }
    return dp[0][0][m-1];
}


// Tabulation - Space Optimization
int CherryPickup4(int n, int m, vector<vector<int>> &grid)
{
    vector<vector<int>> front(m, vector<int> (m,0));
    vector<vector<int>> cur(m, vector<int> (m,0));

    // base case
    for(int j1=0;j1<m;j1++)
    {
        for(int j2=0;j2<m;j2++)
        {
            if(j1==j2)
                front[j1][j2] = grid[n-1][j1];
            else
                front[j1][j2] = grid[n-1][j2] + grid[n-1][j1];
        }
    }

    for(int i=n-2;i>=0;i--)
    {
        for(int j1=0;j1<m;j1++)
        {
            for(int j2=0;j2<m;j2++)
            {
                int maxi=-1e8;
                for(int dj1=-1;dj1<=1;dj1++)
                {
                    for(int dj2=-1;dj2<=1;dj2++)
                    {
                        int val=0;
                        if(j1==j2)
                            val = grid[i][j1];
                        else
                            val = grid[i][j1] + grid[i][j2];
                        
                        if(j1+dj1>=0 && j1+dj1<m && j2+dj2>=0 && dj2+j2<m)
                            val += front[j1+dj1][j2+dj2];
                        else
                            val += -1e8;
                        maxi = max(maxi,val);
                    }
                }
                cur[j1][j2] = maxi;
            }
        }
        front = cur;
    }
    return front[0][m-1];
}


int main()
{
    int n=3,m=4;
    vector<vector<int>> grid = {{2,3,1,2},{3,4,2,2},{5,6,3,5}};
    cout<<CherryPickup1(0,0,m-1,n,m,grid)<<endl;

    vector<vector<vector<int>>> dp(n, vector<vector<int>> (m,vector<int> (m, -1)));
    cout<<CherryPickup2(0,0,m-1,n,m,grid,dp)<<endl;

    cout<<CherryPickup3(n,m,grid)<<endl;
    cout<<CherryPickup4(n,m,grid)<<endl;
    return 0;
}
