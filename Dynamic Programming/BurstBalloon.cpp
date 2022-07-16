#include<bits/stdc++.h>
using namespace std;

// Recurrence Approach
int BurstBalloon1(int i, int j, vector<int> &arr)
{
    if(i>j) return 0;
    int mini = 1e9;
    for(int ind = i; ind <= j; ind++)
    {
        int cost = arr[i-1] * arr[ind] * arr[j+1]
                    + BurstBalloon1(i, ind-1, arr) + BurstBalloon1(ind+1, j, arr);
        mini = min(mini, cost);
    }
    return mini;
}

// Memoization Approach
int BurstBalloon2(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
{
    if(i>j) 
        return 0;

    if(dp[i][j] != -1) 
        return dp[i][j];

    int mini = 1e9;
    for(int ind = i; ind <= j; ind++)
    {
        int cost = arr[i-1] * arr[ind] * arr[j+1]
                    + BurstBalloon1(i, ind-1, arr) + BurstBalloon1(ind+1, j, arr);
        mini = min(mini, cost);
    }
    return dp[i][j] = mini;
}

// Tabulation Approach
int BurstBalloon3(int n, vector<int> &arr)
{
    vector<vector<int>> dp(n+2, vector<int> (n+2, 0));

    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=n;j++)
        {
            if(i>j) 
                continue;
            int mini = 1e9;
            for(int ind = i; ind <= j; ind++)
            {
                int cost = arr[i-1] * arr[ind] * arr[j+1]
                            + dp[i][ind-1] + dp[ind+1][j];
                mini = min(mini, cost);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][n];
}

int main()
{
    vector<int> arr = {3,1,5,8};
    int n = arr.size();
    arr.push_back(1);
    arr.insert(arr.begin(), 1);
    cout<<BurstBalloon1(1,n,arr)<<endl;

    vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
    cout<<BurstBalloon2(1,n,arr,dp)<<endl;
    cout<<BurstBalloon3(n,arr)<<endl;
    return 0;
}
