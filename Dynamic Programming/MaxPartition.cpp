#include<bits/stdc++.h>
using namespace std;

// Recurrence Approach
int MaxParti(int ind, int n, int k, vector<int> &arr)
{
    if(ind == n)
        return 0;
    
    int len=0, maxi = INT_MIN;
    int max_ans = INT_MIN;
    for(int i = ind ; i < min(ind + k, n) ; i++)
    {
        len++;
        maxi = max(arr[i], maxi);
        int res = len*maxi + MaxParti(i+1,n,k,arr);
        max_ans = max(max_ans, res);
    }
    return max_ans;
}

// Memoization Approach
int MaxParti2(int ind, int n, int k, vector<int> &arr, vector<int> &dp)
{
    if(ind == n)
        return 0;

    if(dp[ind]!=-1)
        return dp[ind];
    
    int len=0, maxi = INT_MIN;
    int max_ans = INT_MIN;
    for(int i = ind ; i < min(ind + k, n) ; i++)
    {
        len++;
        maxi = max(arr[i], maxi);
        int res = len*maxi + MaxParti2(i+1,n,k,arr,dp);
        max_ans = max(max_ans, res);
    }
    return dp[ind] = max_ans;
}

// Tabulation Approach
int MaxParti3(int k, vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n+1, 0);
    
    int len,maxi,max_ans;
    for(int ind = n-1;ind>=0;ind--)
    {
        len=0; 
        max_ans = maxi = INT_MIN;
        for(int i = ind ; i < min(ind + k, n) ; i++)
        {
            len++;
            maxi = max(arr[i], maxi);
            int res = len*maxi + dp[i+1];
            max_ans = max(max_ans, res);
        }
        dp[ind] = max_ans;
    }
    return dp[0];
}

int main()
{
    vector<int> arr = {1,15,7,9,2,5,10};
    int k = 3;
    int n = arr.size();
    cout<<MaxParti(0, n, k, arr)<<endl;

    vector<int> dp(n, -1);
    cout<<MaxParti2(0, n, k, arr, dp)<<endl;
    cout<<MaxParti3(k,arr)<<endl;
    return 0;
}
