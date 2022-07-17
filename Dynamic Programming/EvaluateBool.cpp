#include<bits/stdc++.h>
using namespace std;


// Recurrence Approach
long long countTrueWays(int i, int j, bool isBool, string &exp)
{
    // base case
    if(i>j)
        return 0;
    
    if(i==j)
    {
        if(isBool)
            return exp[i] == 'T';
        else
            return exp[i] == 'F';
    }

    int mod=1000000007;
    long long ways=0;
    for(int ind = i+1;ind<=j-1;ind+=2)
    {
        int lT = countTrueWays(i,ind-1, 1, exp);
        int rT = countTrueWays(ind+1, j, 1, exp);
        int lF = countTrueWays(i,ind-1, 0, exp);
        int rF = countTrueWays(ind+1, j, 0, exp);

        if(exp[ind] == '&')
        {
            if(isBool) // for true 
                ways = (ways + (lT*rT)%mod)%mod;
            else 
                ways = (ways + (lT*rF)%mod + (lF*rT)%mod + (lF*rF)%mod)%mod;
        }
        else if(exp[ind] == '|')
        {
            if(isBool)
                ways = (ways + (lT*rT)%mod + (lT*rF)%mod + (lF*rT)%mod)%mod;
            else
                ways = (ways + lF*rF)%mod;
        }
        else
        {
            if(isBool)
                ways = (ways + (lT*rF)%mod + (lF*rT)%mod)%mod;
            else
                ways = (ways + (lT*rT)%mod + (lF*rF)%mod)%mod;
        }
    }
    return ways;
}

// Memoization Approach
long long countTrueWays2(int i, int j, bool isBool, string &exp, vector<vector<vector<int>>> &dp)
{
    // base case
    if(i>j)
        return 0;

    if(dp[i][j][isBool] != -1)
        return dp[i][j][isBool];


    if(i==j)
    {
        if(isBool)
            return exp[i] == 'T';
        else
            return exp[i] == 'F';
    }

    int mod=1000000007;
    long long ways=0;
    for(int ind = i+1;ind<=j-1;ind+=2)
    {
        int lT = countTrueWays(i,ind-1, 1, exp);
        int rT = countTrueWays(ind+1, j, 1, exp);
        int lF = countTrueWays(i,ind-1, 0, exp);
        int rF = countTrueWays(ind+1, j, 0, exp);

        if(exp[ind] == '&')
        {
            if(isBool) // for true 
                ways = (ways + (lT*rT)%mod)%mod;
            else 
                ways = (ways + (lT*rF)%mod + (lF*rT)%mod + (lF*rF)%mod)%mod;
        }
        else if(exp[ind] == '|')
        {
            if(isBool)
                ways = (ways + (lT*rT)%mod + (lT*rF)%mod + (lF*rT)%mod)%mod;
            else
                ways = (ways + lF*rF)%mod;
        }
        else
        {
            if(isBool)
                ways = (ways + (lT*rF)%mod + (lF*rT)%mod)%mod;
            else
                ways = (ways + (lT*rT)%mod + (lF*rF)%mod)%mod;
        }
    }
    return dp[i][j][isBool] = ways;
}

// Tabulation Approach
long long countTrueWays3(string &exp)
{
    int n = exp.size();
    vector<vector<vector<int>>> dp (n, vector<vector<int>> (n, vector<int>(2,0)));

    for(int i=n-1;i>=0;i--)
    {
        for(int j=i;j<=n-1;j++)
        {

            if(i==j)
            {
                dp[i][j][1] = (exp[i] == 'T');
                dp[i][j][0] = (exp[i] == 'F');
            }
            else{
                int mod=1000000007;
                long long ways=0;
                for(int ind = i+1;ind<=j-1;ind+=2)
                {
                    int lt = dp[i][ind-1][1];
                    int rt = dp[ind+1][j][1];
                    int lf = dp[i][ind-1][0];
                    int rf = dp[ind+1][j][0];

                    if(exp[ind] == '&')
                    {
                        dp[i][j][0]=(dp[i][j][0]+(lt*rf+lf*rt+lf*rf))%mod;
                        dp[i][j][1]=(dp[i][j][1]+(lt*rt))%mod;
                    }
                    else if(exp[ind] == '|')
                    {
                        dp[i][j][0]=(dp[i][j][0]+(lf*rf))%mod;
                        dp[i][j][1]=(dp[i][j][1]+(lt*rf+lf*rt+lt*rt))%mod;
                    }
                    else
                    {
                        dp[i][j][0]=(dp[i][j][0]+(lt*rt+lf*rf))%mod;
                        dp[i][j][1]=(dp[i][j][1]+(lt*rf+lf*rt))%mod;
                    }
                }
            }
        }
    }
    return dp[0][n-1][1];
}

int main()
{
    string exp = "F|T^F";
    int n = exp.size();
    cout<<countTrueWays(0,n-1,1,exp)<<endl;

    vector<vector<vector<int>>> dp (n+1, vector<vector<int>> (n+1, vector<int>(2,-1)));
    cout<<countTrueWays2(0,n-1,1,exp,dp)<<endl;
    cout<<countTrueWays3(exp)<<endl;
    return 0;
}
