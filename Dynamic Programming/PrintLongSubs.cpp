#include<bits/stdc++.h>
using namespace std;

// Printing Longest common Subsequence
string LongComSubs(string txt, string pat)
{
    int n = txt.size();
    int m = pat.size();
    vector<vector<int>> dp (n+1, vector<int> (m+1, 0));

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(txt[i-1]==pat[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];

            else    
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    string ans="";
    int k = dp[n][m];
    for(int i=0;i<k;i++)
        ans += '$';

    int index = k-1;
    int i=n,j=m;
    while(i>0 && j>0){
            if(txt[i-1]==pat[j-1]){
                ans[index] = txt[i-1];
                index--;
                i--;
                j--;
            }
            
            else if(dp[i-1][j] > dp[i][j-1])
            {
                i--;
            }
            else
                j--;
    }
    return ans;
}

int main()
{
    string txt = "abcde";
    string pat = "abadfge";
    cout<<LongComSubs(txt,pat)<<endl;
    return 0;
}
