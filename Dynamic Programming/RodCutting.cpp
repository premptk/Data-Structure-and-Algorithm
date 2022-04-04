#include<bits/stdc++.h>
using namespace std;

// Recursive Approach
int RodCut1(int ind, vector<int> &prices, int N)
{
    if(ind==0)
    {
        // base case
        return N*prices[0];
    }

    int nottake = RodCut1(ind-1,prices,N);
    int take = -1e9;
    int  rodlen = ind+1;
    if(rodlen<=N)
        take = prices[ind] + RodCut1(ind, prices, N - rodlen);
    return max(nottake, take);
}

// Memoization Approach
int RodCut2(int ind, vector<int> &prices, int N, vector<vector<int>> &dp)
{
    if(ind==0)
    {
        return N*prices[0];
    }

    if(dp[ind][N]!=-1)
        return dp[ind][N];

    int nottake = RodCut1(ind-1,prices,N);
    int take = -1e9;
    int  rodlen = ind+1;
    if(rodlen<=N)
        take = prices[ind] + RodCut1(ind, prices, N - rodlen);

    return dp[ind][N] = max(nottake, take);
}

// Tabulation Approach
int RodCut3(int N, vector<int> &prices)
{
    vector<vector<int>> dp (N, vector<int> (N+1, 0));
    // base case
    for(int i=0;i<=N;i++)
    {
        dp[0][i] = i*prices[0];
    }

    for(int i=1;i<N;i++)
    {
        for(int j=0;j<=N;j++)
        {
            int nottake = dp[i-1][j];
            int take = -1e9;
            int  rodlen = i+1;
            if(rodlen<=j)
                take = prices[i] + dp[i][j-rodlen];
            dp[i][j] = max(take, nottake);
        }
    }
    return dp[N-1][N];
}

// Tabulation - Space Optimization
int RodCut4(int N, vector<int> &prices)
{
    vector<int> cur(N+1, 0), prev(N+1, 0);
    // base case
    for(int i=0;i<=N;i++)
    {
        prev[i] = i*prices[0];
    }

    for(int i=1;i<N;i++)
    {
        for(int j=0;j<=N;j++)
        {
            int nottake = prev[j];
            int take = -1e9;
            int  rodlen = i+1;
            if(rodlen<=j)
                take = prices[i] + cur[j-rodlen];
            cur[j] = max(take, nottake);
        }
        prev = cur;
    }
    return prev[N];
}

// Tabulation - Single Array Optimization
int RodCut5(int N, vector<int> &prices)
{
    vector<int> prev(N+1, 0);
    // base case
    for(int i=0;i<=N;i++)
    {
        prev[i] = i*prices[0];
    }

    for(int i=1;i<N;i++)
    {
        for(int j=0;j<=N;j++)
        {
            int nottake = prev[j];
            int take = -1e9;
            int  rodlen = i+1;
            if(rodlen<=j)
                take = prices[i] + prev[j-rodlen];
            prev[j] = max(take, nottake);
        }
    }
    return prev[N];
}


int main()
{
    vector<int> prices = {2,5,7,8,10};
    int N = prices.size();
    cout<<RodCut1(N-1, prices, N)<<endl;

    vector<vector<int>> dp (N, vector<int> (N+1, -1));
    cout<<RodCut2(N-1,prices,N,dp)<<endl;

    cout<<RodCut3(N, prices)<<endl;
    cout<<RodCut4(N,prices)<<endl;
    cout<<RodCut5(N,prices)<<endl;
    return 0;
}
