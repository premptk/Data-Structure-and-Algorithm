#include<bits/stdc++.h>
using namespace std;

// Longest Palindromic Subsequence
// Tabulation Approach
int LongPalinSubs(string txt, string pat)
{
    int n = txt.size();
    int m = pat.size();
    vector<vector<int>> dp(n+1, vector<int> (m+1,0));

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(txt[i-1]==pat[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][m];
}

// Tabulation Approach - Space Optimization
int LongPalinSubs2(string txt, string pat)
{
    int n = txt.size();
    int m = pat.size();
    vector<int> cur(m+1,0), prev(m+1,0);

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(txt[i-1]==pat[j-1])
            {
                cur[j] = 1 + prev[j-1];
            }
            else
                cur[j] = max(prev[j], cur[j-1]);
        }
        prev = cur;
    }
    return prev[m];
}

int main()
{
    string txt = "abcdba";
    // abcdba - abdcba => abcba (5)
    string pat = txt;
    reverse(pat.begin(),pat.end());
    cout<<LongPalinSubs(txt, pat)<<endl;
    cout<<LongPalinSubs2(txt, pat)<<endl;
    return 0;
}
