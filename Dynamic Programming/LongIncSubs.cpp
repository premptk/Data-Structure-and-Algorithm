#include<bits/stdc++.h>
using namespace std;

// Recursive Approach
int LongIncSubs(vector<int> &seq, int ind, int prev)
{
    if(ind==seq.size())
        return 0;
    
    int len = LongIncSubs(seq, ind+1, prev);   // not take

    if(prev==-1 || seq[ind]>seq[prev])    // take
        len = max(len, 1 + LongIncSubs(seq, ind+1,ind));

    return len;
}


// Memoization Approach
int LongIncSubs2(vector<int> &seq, int ind, int prev, vector<vector<int>> &dp)
{
    if(ind==seq.size())
        return 0;

    if(dp[ind][prev+1]!=-1)
        return dp[ind][prev+1];
    
    int len = LongIncSubs(seq, ind+1, prev);   // not take

    if(prev==-1 || seq[ind]>seq[prev])    // take
        len = max(len, 1 + LongIncSubs(seq, ind+1,ind));

    return dp[ind][prev+1] = len;
}

int main()
{
    vector<int> seq = {10,9,2,5,3,7,101,18};
    cout<<LongIncSubs(seq,0,-1)<<endl;

    int n = seq.size();
    vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
    cout<<LongIncSubs2(seq,0,-1,dp)<<endl;
    return 0;
}
