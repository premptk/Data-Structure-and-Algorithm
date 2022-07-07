#include<bits/stdc++.h>
using namespace std;

int NumSubs(int n, vector<int> &arr)
{
    vector<int> dp(n,1), cnt(n,1);
    int maxi = -1e9;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[j] < arr[i] && 1+dp[j] > dp[i])
            {
                dp[i] = dp[j] + 1;
                cnt[i] = cnt[j];
            }
            else if(arr[j] < arr[i] && dp[i] == 1 + dp[j]){
                cnt[i] += cnt[j];
            }
            maxi = max(maxi, dp[i]);
        }
    }

    int res = 0;
    for(int i=0;i<n;i++)
    {
        if(dp[i] == maxi) 
            res += cnt[i];
    }
    return res;
}

int main()
{
    vector<int> arr = {1,5,4,3,2,6,7,10,8,9};
    int n = arr.size();
    cout<<NumSubs(n,arr)<<endl;
    return 0;
}
