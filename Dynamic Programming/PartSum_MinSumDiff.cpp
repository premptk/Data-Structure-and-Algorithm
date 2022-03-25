#include<bits/stdc++.h>
using namespace std;

// Tabulation Approch
int PartiSearch1(int n, vector<int> &arr, int target)
{
    vector<vector<bool>> dp(n, vector<bool> (target+1, false));
    // base case
    for(int i=0;i<n;i++)
        dp[i][0] = true;

    if(arr[0]<=target) dp[0][arr[0]]=true;

    for(int i=1;i<n;i++)
    {
        for(int k=1;k<=target;k++)
        {
            bool notTake = dp[i-1][k];
            bool take = false;
            if(arr[i]<=k)
                take = dp[i-1][k-arr[i]];
            dp[i][k] = take||notTake;
        }
    }

    int mini = 1e9;
    for(int i=0;i<=target;i++)
    {
       if(dp[n-1][i]==true) 
       {
           int diff = abs(i - (target-i));
           mini = min(mini, diff);
       }
    }
    return mini;
}

// Tabulation - Space Optimization
int PartiSearch2(int n, vector<int> &arr, int totSum)
{
    vector <bool> prev(totSum + 1, false);

  prev[0] = true;

  if (arr[0] <= totSum)
    prev[arr[0]] = true;

  for (int ind = 1; ind < n; ind++) {
    vector <bool> cur(totSum + 1, false);
    cur[0] = true;
    for (int target = 1; target <= totSum; target++) {
      bool notTaken = prev[target];

      bool taken = false;
      if (arr[ind] <= target)
        taken = prev[target - arr[ind]];

      cur[target] = notTaken || taken;
    }
    prev = cur;
  }

  int mini = 1e9;
  for (int i = 0; i <= totSum; i++) {
    if (prev[i] == true) {
      int diff = abs(i - (totSum - i));
      mini = min(mini, diff);
    }
  }
  return mini;
}


int PartiSearch(vector<int> &arr)
{
    int n = arr.size();
    int sum=0;
    for(auto it:arr)
        sum+=it;
    // return PartiSearch1(n,arr,sum);
    return PartiSearch2(n,arr,sum);
}

int main()
{
    vector<int> arr = {1,2,3,7};
    cout<<PartiSearch(arr)<<endl;
    return 0;
}
