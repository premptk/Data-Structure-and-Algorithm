#include<bits/stdc++.h>
using namespace std;

// Recursive Approach
int BuySell(int ind, int buy, vector<int>&prices)
{
    // base case
    if(ind>=prices.size())
        return 0;

    if(buy)
    {
        return max(-prices[ind] + BuySell(ind+1,0,prices),
                BuySell(ind+1,1,prices));
    }
    else
        return max(prices[ind]+BuySell(ind+2,1,prices), 
                BuySell(ind+1,0,prices));
}

// Memoization Approach
int BuySell2(int ind, int buy, vector<int>&prices, vector<vector<int>> &dp)
{
    // base case
    if(ind>=prices.size())
        return 0;

    if(dp[ind][buy]!=-1)
        return dp[ind][buy];

    if(buy)
    {
        return dp[ind][buy] = max(-prices[ind] + BuySell(ind+1,0,prices),
                BuySell(ind+1,1,prices));
    }
    else
        return dp[ind][buy] = max(prices[ind]+BuySell(ind+2,1,prices), 
                BuySell(ind+1,0,prices));
}


// Tabulation Approach
int BuySell3(int n, vector<int>&prices)
{
    vector<vector<int>> dp(n+2, vector<int> (2,0));
    for(int ind=n-1;ind>=0;ind--)
    {
        for(int buy=0;buy<=1;buy++)
        {
            dp[ind][1] = max(-prices[ind] + dp[ind+1][0],
                    dp[ind+1][1]);

            dp[ind][0] = max(prices[ind]+dp[ind+2][1], 
                    dp[ind+1][0]);
        }
    }
    return dp[0][1];
}


int main()
{
    vector<int> prices = {4,9,0,4,10};
    int n = prices.size();
    cout<<BuySell(0,1,prices)<<endl;

    vector<vector<int>> dp(n+1, vector<int> (2,-1));
    cout<<BuySell2(0,1,prices,dp)<<endl;
    cout<<BuySell3(n,prices)<<endl;
    return 0;
}
