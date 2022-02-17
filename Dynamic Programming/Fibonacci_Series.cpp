#include<bits/stdc++.h>
using namespace std;

// Memoization
int fibo(int n, vector<int> &dp)
{
    if(n<=1)
        return n;
    if(dp[n]!=-1) 
        return dp[n];
    return dp[n] = fibo(n-1, dp) + fibo(n-2, dp);
}

// Tabulation
int fibo2(int n, vector<int> dp)
{
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++)
        dp[i] = dp[i-1] + dp[i-2];
    return dp[n];
}

// Space optimization Approach
int fibo3(int n)
{
    int prev2=0,prev=1;
    for(int i=2;i<=n;i++)
    {
        int curi = prev + prev2;
        prev2=prev;
        prev=curi;
    }
    return prev;
}

int main()
{
    int n=10;
    vector<int> dp(n+1, -1);
    cout<<fibo2(n,dp)<<endl;
    cout<<fibo(n, dp)<<endl;
    cout<<fibo3(n);
    return 0;
}
