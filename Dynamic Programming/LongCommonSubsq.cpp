#include<bits/stdc++.h>
using namespace std;
// Longest common subsequence
// aabcd , abcad --> abcd --> 4

// Recursive Approach
int LongComSubs(int ind1, int ind2, string txt, string pat)
{
    // base case
    if(ind1<0 || ind2<0)
        return 0;

    if(txt[ind1] == pat[ind2])
        return 1 + LongComSubs(ind1-1, ind2-1, txt, pat);

    else 
        return 0 + max( LongComSubs(ind1, ind2-1, txt, pat), LongComSubs(ind1-1, ind2, txt, pat));
}

// Memoization Approach
int LongComSubs2(int ind1, int ind2, string txt, string pat, vector<vector<int>> &dp)
{
    // base case
    if(ind1==0 || ind2==0)
        return 0;

    if(dp[ind1][ind2]!=-1)
        return dp[ind1][ind2];

    if(txt[ind1-1] == pat[ind2-1])
        return dp[ind1][ind2] = 1 + LongComSubs2(ind1-1, ind2-1, txt, pat, dp);

    else 
        return dp[ind1][ind2] = 0 + max( LongComSubs2(ind1-1, ind2, txt, pat, dp), LongComSubs2(ind1, ind2-1, txt, pat, dp));
     
}


// Tabulation Approach
int LongComSubs3(int n,int m,string txt,string pat)
{
    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
    for(int i=0;i<=n;i++)
        dp[i][0] = 0;
    
    for(int j=0;j<=m;j++)
        dp[0][j] = 0;

    for(int i = 1;i <= n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(txt[i-1] == pat[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];

            else 
                dp[i][j] = 0 + max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][m];
}


// Tabulation - Space Optimization
int LongComSubs4(int n, int m, string txt, string pat)
{
    vector<int> prev(m+1,0), cur(m+1,0);
    for(int i=0;i<=m;i++)
        prev[i] = 0;

    for(int i = 1;i <= n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(txt[i-1] == pat[j-1])
                cur[j] = 1 + prev[j-1];

            else 
                cur[j] = 0 + max(prev[j], cur[j-1]);
        }
        prev = cur;
    }
    return prev[m];
}


int main()
{
    string txt = "aabcd";
    string pat = "abcad";
    int n = txt.length();
    int m = pat.length();
    cout<<LongComSubs(n-1, m-1, txt, pat)<<endl;

    vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
    cout<<LongComSubs2(n, m, txt, pat, dp)<<endl;
    cout<<LongComSubs3(n, m, txt, pat)<<endl;
    cout<<LongComSubs4(n, m, txt, pat)<<endl;
    return 0;
}
