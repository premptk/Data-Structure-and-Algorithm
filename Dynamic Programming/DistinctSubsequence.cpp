#include<bits/stdc++.h>
using namespace std;

// Recursive Approach
int CountDistinct(string s1, string s2, int i, int j)
{
    // base case
    if(j<0)
        return 1;
    if(i<0)
        return 0;

    if(s1[i]==s2[j])
        return CountDistinct(s1,s2,i-1,j-1) + CountDistinct(s1,s2,i-1,j);
    else
        return CountDistinct(s1,s2,i-1,j);
}

// Memoization Approach
int CountDistinct2(string s1, string s2, int i, int j, vector<vector<int>> &dp)
{
    // base case
    if(j<0)
        return 1;
    if(i<0)
        return 0;

    if(dp[i][j]!=-1)
        return dp[i][j];

    if(s1[i]==s2[j])
        return dp[i][j] =  CountDistinct(s1,s2,i-1,j-1) + CountDistinct(s1,s2,i-1,j);
    else
        return dp[i][j] = CountDistinct(s1,s2,i-1,j);
}

// Tabulation Approach
int CountDistinct3(string s1, string s2, int n, int m)
{
    vector<vector<double>> dp(n+1, vector<double> (m+1, 0));
    // base case
    for(int i=0;i<=n;i++)
        dp[i][0] = 1;

    for(int i=1;i<=m;i++)
        dp[0][i] = 0;
    

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return (int)dp[n][m];
}

// Tabulation Approach - Space Optimization
int CountDistinct4(string s1, string s2, int n, int m)
{
    vector<double> prev(m+1, 0), curr(m+1, 0);
    // base case
    prev[0] = curr[0] = 1;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s1[i-1] == s2[j-1])
                curr[j] = prev[j-1] + prev[j];
            else
                curr[j] = prev[j];
        }
        prev = curr;
    }
    return (int)prev[m];
}

// Tabulation Approach - Space Optimization (One Dimensional Array)
int CountDistinct5(string s1, string s2, int n, int m)
{
    vector<double> prev(m+1, 0);
    // base case
    prev[0] = 1;

    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=1;j--)
        {
            if(s1[i-1] == s2[j-1])
                prev[j] = prev[j-1] + prev[j];
        }
    }
    return (int)prev[m];
}

int main()
{
    string s1 = "babagbag";
    string s2 = "bag";
    int n = s1.size();
    int m = s2.size();
    cout<<CountDistinct(s1,s2,n-1,m-1)<<endl;

    vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
    cout<<CountDistinct2(s1,s2,n-1,m-1,dp)<<endl;
    cout<<CountDistinct3(s1,s2,n,m)<<endl;
    cout<<CountDistinct4(s1,s2,n,m)<<endl;
    cout<<CountDistinct5(s1,s2,n,m)<<endl;
    return 0;
}
