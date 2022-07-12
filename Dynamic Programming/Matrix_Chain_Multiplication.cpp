#include<bits/stdc++.h>
using namespace std;

int matrixMulti(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
{
    if(i==j)
        return 0;

    if(dp[i][j]!=-1)    
        return dp[i][j];

    int mini = 1e9;
    for(int k=i;k<j;k++)
    {
        int steps = arr[i-1] * arr[k] * arr[j]
         + matrixMulti(i,k,arr,dp) + matrixMulti(k+1,j,arr,dp);
        mini = min(steps, mini);
    }
    return dp[i][j] = mini;
}

int main()
{
    vector<int> arr = {10, 20, 30, 40};
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int> (n, -1));
    cout<<matrixMulti(1, n-1, arr,dp)<<endl;
    return 0;
}
