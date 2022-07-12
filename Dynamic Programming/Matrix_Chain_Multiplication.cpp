#include<bits/stdc++.h>
using namespace std;

// Recurrence Approach
int matrixMulti(int i, int j, vector<int> &arr)
{
    if(i==j)
        return 0;

    int mini = 1e9;
    for(int k=i;k<j;k++)
    {
        int steps = arr[i-1] * arr[k] * arr[j]
         + matrixMulti(i,k,arr) + matrixMulti(k+1,j,arr);
        mini = min(steps, mini);
    }
    return mini;
}


// Memoziation Approach
int matrixMulti2(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
{
    if(i==j)
        return 0;

    if(dp[i][j]!=-1)    
        return dp[i][j];

    int mini = 1e9;
    for(int k=i;k<j;k++)
    {
        int steps = arr[i-1] * arr[k] * arr[j]
         + matrixMulti2(i,k,arr,dp) + matrixMulti2(k+1,j,arr,dp);
        mini = min(steps, mini);
    }
    return dp[i][j] = mini;
}

// Tabulation Approach
int matrixMulti3(int n, vector<int> &arr)
{
    vector<vector<int>> dp(n, vector<int> (n, 0));
    for(int i=0;i<n;i++)
        dp[i][i] = 0;

    for(int i=n-1;i>=1;i--)
    {
        for(int j=i+1;j<n;j++)
        { 
            int mini = 1e9;
            for(int k=i;k<j;k++)
            {
                int steps = arr[i-1] * arr[k] * arr[j]
                + dp[i][k] + dp[k+1][j];
                mini = min(steps, mini);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][n-1];
}

int main()
{
    vector<int> arr = {10, 20, 30, 40};
    int n = arr.size();
    cout<<matrixMulti(1, n-1, arr)<<endl;

    vector<vector<int>> dp(n, vector<int> (n, -1));
    cout<<matrixMulti2(1, n-1, arr,dp)<<endl;
    cout<<matrixMulti3(n, arr)<<endl;
    return 0;
}
