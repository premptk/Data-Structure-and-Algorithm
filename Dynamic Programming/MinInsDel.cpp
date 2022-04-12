#include<bits/stdc++.h>
using namespace std;

int lcs(string txt, string pat)
{
    int n = txt.size();
    int m = pat.size();
    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(txt[i-1] == pat[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][m];
}

int main()
{
    // txt to pat
    string txt = "abcdaf";
    string pat = "anca";
    int n = txt.size();
    int m = pat.size();
    int x = lcs(txt,pat);
    cout<<(n + m - 2*lcs(txt,pat))<<endl;
    return 0;
}
