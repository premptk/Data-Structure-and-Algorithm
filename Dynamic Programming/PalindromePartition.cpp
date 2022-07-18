#include<bits/stdc++.h>
using namespace std;

bool isPalin(int ind, int n, string &str)
{
    int i=ind,j=n-1;
    while(i<j)
    {
        if(str[i]!=str[j])
            return false;
        i++;
        j--;
    }
    return true;
}

// Reccurence Approach
int PalinPart(int ind, int n, string &str)
{
    if(ind == n)
        return 0;
    
    int mini = INT_MAX;
    for(int i = ind; i<n;i++)
    {
        if(isPalin(ind,i,str))
        {
            int cnt = 1 + PalinPart(i+1, n, str);
            mini = min(cnt, mini);
        }
    }
    return mini;
}

// Memoization Approach
int PalinPart2(int ind, int n, string &str, vector<int> &dp)
{
    if(ind == n)
        return 0;
    
    if(dp[ind]!=-1)
        return dp[ind];

    int mini = INT_MAX;
    for(int i = ind; i<n;i++)
    {
        if(isPalin(ind,i,str))
        {
            int cnt = 1 + PalinPart2(i+1, n, str,dp);
            mini = min(cnt, mini);
        }
    }
    return dp[ind] = mini;
}

// Tabulation Approach
int PalinPart3(string &str)
{
    int n = str.size();
    vector<int> dp(n+1, 0);

    for(int ind = n-1;ind>=0;ind--)
    {
        int mini = INT_MAX;
        for(int i = ind; i<n;i++)
        {
            if(isPalin(ind,i,str))
            {
                int cnt = 1 + PalinPart2(i+1, n, str,dp);
                mini = min(cnt, mini);
            }
        }
        dp[ind] = mini;
    }
    return dp[0];
}


int main()
{
    string str = "bababcbadcede";
    int n = str.size();
    cout<<PalinPart(0,n,str)-1<<endl;

    vector<int> dp(n,-1);
    cout<<PalinPart2(0,n,str,dp)-1<<endl;
    cout<<PalinPart3(str)-1<<endl;
    return 0;
}
