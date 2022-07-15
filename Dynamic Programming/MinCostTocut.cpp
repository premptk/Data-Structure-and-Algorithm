#include<bits/stdc++.h>
using namespace std;

// Recurrence Approach
int MinCost(int i, int j, vector<int> &cuts)
{
    if(i>j)
        return 0;
    int ans = 1e9;
    for(int cut = i; cut<=j; cut++)
    {
        int res = cuts[j+1] - cuts[i-1] +
                    MinCost(i, cut-1, cuts) + MinCost(cut+1, j, cuts);
        ans = min(ans, res);
    }
    return ans;
}

// Memoization Approach
int MinCost2(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
{
    if(i>j)
        return 0;

    if(dp[i][j]!=-1)
        return dp[i][j];

    int ans = 1e9;
    for(int cut = i; cut<=j; cut++)
    {
        int res = cuts[j+1] - cuts[i-1] +
                    MinCost(i, cut-1, cuts) + MinCost(cut+1, j, cuts);
        ans = min(ans, res);
    }
    return dp[i][j] = ans;
}


// Tabulation Approach
int MinCost3(int n, int c, vector<int> &cuts)
{
    vector<vector<int>> dp(c+2, vector<int> (c+2, 0));

    for(int i=c;i>=1;i--)
    {
        for(int j=1;j<=n;j++)
        {
            if(i>j) continue;
            int ans = 1e9;
            for(int cut = i; cut<=j; cut++)
            {
                int res = cuts[j+1] - cuts[i-1] +
                            dp[i][cut-1] + dp[cut+1][j];
                ans = min(ans, res);
            }
            dp[i][j] = ans;
        }
    }
    return dp[1][c];
}

int main()
{
    vector<int> cuts = {1,3,4,5};
    int n = 7;
    int c = cuts.size();
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());
    cout<<MinCost(1,c,cuts)<<endl;

    vector<vector<int>> dp(c+1, vector<int> (c+1, -1));
    cout<<MinCost2(1,c,cuts,dp)<<endl;

    cout<<MinCost3(n,c,cuts)<<endl;
    return 0;
}
