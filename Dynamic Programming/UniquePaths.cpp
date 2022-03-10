#include<bits/stdc++.h>
using namespace std;

// Recursive Approach
int UniPaths1(int i, int j)
{
    if(i==0 && j==0)
        return 1;
    if(i<0 || j<0)
        return 0;
    int top = UniPaths1(i-1,j);
    int left = UniPaths1(i,j-1);
    return top + left;
}

// Memoization Approach
int UniPaths2(int i, int j, vector<vector<int>>& dp)
{
    if(i==0 && j==0)
        return 1;

    if(i<0 || j<0)
        return 0;

    if(dp[i][j]!=-1)
        return dp[i][j];

    int top = UniPaths2(i-1, j, dp);
    int left = UniPaths2(i, j-1, dp);
    return dp[i][j] = top+left;
}

// Tabulation Approach
int UniPaths3(int m, int n)
{
    int dp2[m][n];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==0 && j==0)
                dp2[i][j]=1;
            else
            {
                int up=0,left=0;
                if(i>0) up = dp2[i-1][j];
                if(j>0) left = dp2[i][j-1];
                dp2[i][j] = up + left;
            }
        }
    }
    return dp2[m-1][n-1];
}

// Tabulation - Space Optimization
int UniPaths4(int m, int n)
{
    vector<int> prev(n,0);
    for(int i=0;i<m;i++)
    {
        vector<int> temp(n,0);
        for(int j=0;j<n;j++)
        {
            if(i==0 && j==0)
            {
                temp[j]=1;
                continue;
            }
            else
            {
                int up=0,left=0;
                if(i>0) up = prev[j];
                if(j>0) left = temp[j-1];
                temp[j] = up + left;
            }
        }
        prev = temp;
    }
    return prev[n-1];
}

int main()
{
    int n=3,m=3;

    cout<<UniPaths1(m-1,n-1)<<endl;

    vector<vector<int>> dp(m, vector<int> (n,-1));
    cout<<UniPaths2(m-1,n-1,dp)<<endl;
    
    cout<<UniPaths3(m,n)<<endl;

    cout<<UniPaths4(m,n)<<endl;
    return 0;
}   
