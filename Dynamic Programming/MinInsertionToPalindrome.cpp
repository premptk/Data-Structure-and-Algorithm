#include<bits/stdc++.h>
using namespace std;

int LongPalinSub(string txt, string pat)
{
    int n = txt.size();
    int m = pat.size();
    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(txt[i-1] == pat[j-1])
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

int main()
{
    string txt = "ababc";
    string pat = txt;
    reverse(txt.begin(), txt.end());
    int res = txt.length() - LongPalinSub(txt, pat);
    cout<<res<<endl;
    return 0;
}
