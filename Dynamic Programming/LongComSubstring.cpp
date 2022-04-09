#include<bits/stdc++.h>
using namespace std;

// Tabulation Approach
int LongComSub(string txt, string pat)
{
    int n = txt.size();
    int m = pat.size();
    vector<vector<int>> dp (n+1, vector<int> (m+1, 0));

    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(txt[i-1]==pat[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
                ans = max(ans, dp[i][j]);
            }
            else
                dp[i][j] = 0;
        }
    }
    return ans;
}

// Tabulation Approach - Space Optimization
int LongComSub2(string txt, string pat)
{
    int n = txt.size();
    int m = pat.size();
    vector<int> cur(m+1, 0), prev(m+1, 0);

    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(txt[i-1]==pat[j-1])
            {
                cur[j] = 1 + prev[j-1];
                ans = max(ans, cur[j]);
            }
            else
                cur[j] = 0;
        }
        prev = cur;
    }
    return ans;
}


int main()
{
    string txt,pat;
    txt = "abcdef";
    pat = "fkabcds";
    cout<<LongComSub(txt,pat)<<endl;
    cout<<LongComSub2(txt,pat)<<endl;
    return 0;
}
