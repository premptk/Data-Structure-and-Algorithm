#include<bits/stdc++.h>
using namespace std;

// Recursive Approach
int EditDist(string s1, string s2, int i, int j)
{
    // base case
    if(i<0)
        return j+1;
    if(j<0)
        return i+1;

    if(s1[i]==s2[j])
        return EditDist(s1,s2,i-1,j-1);
    else
        return 1 + min(EditDist(s1,s2,i-1,j),
                     min(EditDist(s1,s2,i,j-1),
                            EditDist(s1,s2,i-1,j-1)));
}

// Memoization Approach
int EditDist2(string s1, string s2, int i, int j, vector<vector<int>> &dp)
{
    // base case
    if(i<0)
        return j+1;
    if(j<0)
        return i+1;

    if(dp[i][j]!=-1)
        return dp[i][j];

    if(s1[i]==s2[j])
        return dp[i][j] = EditDist(s1,s2,i-1,j-1);
    else
        return dp[i][j] = 1 + min(EditDist(s1,s2,i-1,j),
                     min(EditDist(s1,s2,i,j-1),
                            EditDist(s1,s2,i-1,j-1)));
}

// Tabulation Approach
int EditDist3(string s1, string s2, int n, int m)
{
    vector<vector<int>> dp (n+1, vector<int> (m+1, 0));
    // base case
    for(int i=0;i<=m;i++)
        dp[0][i] = i; 
    
    for(int i=0;i<=n;i++)
        dp[i][0] = i;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s1[i-1]==s2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                 dp[i][j] = 1 + min(dp[i-1][j],
                            min(dp[i][j-1],
                                    dp[i-1][j-1]));
        }
    }
    return dp[n][m];
}

// Tabulation Approach - Space Optimization
int EditDist4(string s1, string s2, int n, int m)
{
    vector<int> prev(m+1, 0), cur(m+1, 0);
    // base case    
    for(int i=0;i<=m;i++)
        prev[i] = i; 

    for(int i=1;i<=n;i++)
    {
        cur[0] = i;
        for(int j=1;j<=m;j++)
        {
            if(s1[i-1]==s2[j-1])
                cur[j] = prev[j-1];
            else
                 cur[j] = 1 + min(prev[j],
                            min(cur[j-1],
                                    prev[j-1]));
        }
        prev = cur;
    }
    return prev[m];
}

int main()
{
    string s1 = "roros";
    string s2 = "ros";
    int n = s1.size();
    int m = s2.size();
    cout<<EditDist(s1,s2,n-1,m-1)<<endl;
    vector<vector<int>> dp(n, vector<int> (m+1, -1));
    cout<<EditDist2(s1,s2,n-1,m-1, dp)<<endl;
    cout<<EditDist3(s1,s2,n,m)<<endl;
    cout<<EditDist4(s1,s2,n,m)<<endl;
    return 0;
}
