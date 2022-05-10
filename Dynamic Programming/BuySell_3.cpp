#include<bits/stdc++.h>
using namespace std;

// Recursive Approach
int BuySell(int ind,int buy, vector<int> &prices, int cap)
{
    // base case
    if(cap==0)
        return 0;

    if(ind==prices.size())
        return 0;

    if(buy)
    {
        return max(-prices[ind] + BuySell(ind+1,0,prices,cap),
                    BuySell(ind+1,1,prices,cap));
    }
    else{ // sell
        return max(prices[ind] + BuySell(ind+1,1,prices,cap-1),
                    BuySell(ind+1,0,prices,cap));
    }
}

// Memoization Approach
int BuySell2(int ind,int buy, vector<int> &prices, int cap, vector<vector<vector<int>>> &dp)
{
    // base case
    if(cap==0)
        return 0;

    if(ind==prices.size())
        return 0;

    if(dp[ind][buy][cap]!=-1)
        return dp[ind][buy][cap];

    if(buy)
    {
        return dp[ind][buy][cap] = max(-prices[ind] + BuySell(ind+1,0,prices,cap),
                    BuySell(ind+1,1,prices,cap));
    }
    else{ // sell
        return dp[ind][buy][cap] = max(prices[ind] + BuySell(ind+1,1,prices,cap-1),
                    BuySell(ind+1,0,prices,cap));
    }
}

// Tabulation Approach
int BuySell3(int n, vector<int> &prices, int k)
{
    vector<vector<vector<int>>> dp(n+1,
            vector<vector<int>> (2, 
                    vector<int> (k+1,0)));
    // base case
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=1;j++)
        {   
            dp[i][j][0] = 0;
        }
    }

    for(int j=0;j<=1;j++)
    {  
        for(int cap=0;cap<=k;cap++)
        {  
                dp[n][j][cap] = 0;
        }
    }

    for(int ind=n-1;ind>=0;ind--)
    {
        for(int buy=0;buy<=1;buy++)
        {
            for(int cap=1;cap<=k;cap++)
            {
                if(buy)
                {
                    dp[ind][buy][cap] = max(-prices[ind] + dp[ind+1][0][cap],
                                dp[ind+1][1][cap]);
                }
                else{ // sell
                    dp[ind][buy][cap] = max(prices[ind] + dp[ind+1][1][cap-1],
                                dp[ind+1][0][cap]);
                }
            }
        }
    }
    return dp[0][1][k];
}

// Tabulation Approach - Space Optimization
int BuySell4(int n, vector<int> &prices, int k)
{
    vector<vector<int>> after(2, vector<int> (k+1, 0));
    vector<vector<int>> cur(2, vector<int> (k+1, 0));
                    
    // base case
    // No need as dp array is already initialized with all 0's!
    // for(int i=0;i<=n;i++)
    // {
    //     for(int j=0;j<=1;j++)
    //     {   
    //         dp[i][j][0] = 0;
    //     }
    // }

    // for(int j=0;j<=1;j++)
    // {  
    //     for(int cap=0;cap<=k;cap++)
    //     {  
    //             dp[n][j][cap] = 0;
    //     }
    // }

    for(int ind=n-1;ind>=0;ind--)
    {
        for(int buy=0;buy<=1;buy++)
        {
            for(int cap=1;cap<=k;cap++)
            {
                if(buy)
                {
                    cur[buy][cap] = max(-prices[ind] + after[0][cap],
                                after[1][cap]);
                }
                else{ // sell
                    cur[buy][cap] = max(prices[ind] + after[1][cap-1],
                                after[0][cap]);
                }
            }
        }
        after = cur;
    }
    return after[1][k];
}


int main()
{
    vector<int> prices = {3,3,5,0,0,3,1,4};
    int k = 2;
    int n = prices.size();
    cout<<BuySell(0,1,prices,k)<<endl;

    vector<vector<vector<int>>> dp(n,
            vector<vector<int>> (2, 
                    vector<int> (k+1,-1)));
    cout<<BuySell2(0,1,prices,k,dp)<<endl;
    cout<<BuySell3(n,prices,2)<<endl;
    cout<<BuySell4(n,prices,2)<<endl;
    return 0;
}
