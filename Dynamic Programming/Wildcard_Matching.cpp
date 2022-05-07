#include<bits/stdc++.h>
using namespace std;

// Wildcart Matching
// Recursive Approach
bool WildCart(string s1, string s2, int i, int j)
{
    // base case
    if(i<0 && j<0)
        return true;

    if(i<0 && j>=0)
        return false;

    if(j<0 && i>=0)
    {
        for(int i=0;i<i;i++)
            if(s1[i]!='*')
                return false;
        return true;
    }

    if(s1[i] == s2[j] || s1[i] == '$')
        return WildCart(s1,s2,i-1,j-1);

    else if(s1[i] == '*')
        return WildCart(s1,s2,i-1,j) or WildCart(s1,s2,i,j-1);

    return false;
}

// Memoization Approach
bool WildCart2(string s1, string s2, int i, int j, vector<vector<int>> &dp)
{
    // base case
    if(i<0 && j<0)
        return true;

    if(i<0 && j>=0)
        return false;

    if(j<0 && i>=0)
    {
        for(int i=0;i<i;i++)
            if(s1[i]!='*')
                return false;
        return true;
    }

    if(dp[i][j]!=-1)
        return dp[i][j];

    if(s1[i] == s2[j] || s1[i] == '$')
        return dp[i][j] = WildCart2(s1,s2,i-1,j-1,dp);

    else if(s1[i] == '*')
        return dp[i][j] = WildCart2(s1,s2,i-1,j,dp) or WildCart2(s1,s2,i,j-1,dp);

    return false;
}

// Tabulation Approach
bool WildCart3(string s1, string s2, int n, int m)
{
    vector<vector<bool>> dp (n+1, vector<bool> (m+1, 0));
    // base case
    dp[0][0] = 1;

    for(int i=1;i<=m;i++)
        dp[0][i] = 0;

    for(int i=1;i<=n;i++)
    {
        bool flag =  true;
        for(int k=1;k<=i;k++){
            if(s1[i] != '*'){
                flag = false;
                break;
            }
        }
        dp[i][0] = flag;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s1[i-1] == s2[j-1] || s1[i-1] == '$')
                dp[i][j] = dp[i-1][j-1];

            else if(s1[i-1] == '*')
                dp[i][j] = dp[i-1][j] | dp[i][j-1];

            else dp[i][j] = 0;
        }
    }
    return dp[n][m];
}

// Tabulation Approach - Space Optimization
bool WildCart4(string s1, string s2, int n, int m)
{
    vector<bool> prev(m+1, false), cur(m+1, false);
    // base case
    prev[0] = 1;

    for(int i=1;i<=m;i++)
        prev[i] = 0;

    for(int i=1;i<=n;i++)
    {
        bool flag =  true;
        for(int k=1;k<=i;k++){
            if(s1[i] != '*'){
                flag = false;
                break;
            }
        }
        prev[0] = flag;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s1[i-1] == s2[j-1] || s1[i-1] == '$')
                cur[j] = prev[j-1];

            else if(s1[i-1] == '*')
                cur[j] = prev[j] | cur[j-1];

            else cur[j] = 0;
        }
        prev = cur;
    }
    return prev[m];
}

int main()
{
    string s1 = "abc*gh";
    string s2 = "abcdefgh";
    int n = s1.size();
    int m = s2.size();
    cout<<WildCart(s1,s2,n-1,m-1)<<endl;

    vector<vector<int>> dp (n+1, vector<int> (m+1, -1));
    cout<<WildCart2(s1,s2,n-1,m-1,dp)<<endl;
    cout<<WildCart3(s1,s2,n,m)<<endl;
    cout<<WildCart4(s1,s2,n,m)<<endl;   
    return 0;
}
