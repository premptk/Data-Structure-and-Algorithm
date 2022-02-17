#include<bits/stdc++.h>
using namespace std;

int fibo(int n, vector<int> &dp)
{
    if(n<=1)
        return n;
  
    //checking for overlapping subproblem
    if(dp[n]!=-1)
        return dp[n];
  
    // return and initializing dp
    return dp[n] = fibo(n-1, dp) + fibo(n-2, dp);
}

int main()
{
    int n=10;
  
    // step 1 - declaration
    vector<int> dp(n+1, -1);
  
    cout<<fibo(n, dp);
    return 0;
}
