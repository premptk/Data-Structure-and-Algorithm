#include<bits/stdc++.h>
using namespace std;

int LDS(int n, vector<int> &arr)
{
    vector<int> dp(n,1), hash(n,0);
    int maxi = 1,lastindex=0;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if((arr[i] % arr[j] == 0) &&
                (dp[j]+1 > dp[i]))
                {
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
        }
        if(dp[i] > maxi){
            maxi = dp[i];
            lastindex = i;
        }
    }

    vector<int> temp;
    temp.push_back(arr[lastindex]);
    while(hash[lastindex] != lastindex)
    {
        lastindex = hash[lastindex];
        temp.push_back(arr[lastindex]);
    }
    reverse(temp.begin(),temp.end());
    for(auto it:temp)
        cout<<it<<" ";
    cout<<endl;
    return maxi;
}

int main()
{
    vector<int> arr = {16,7,4,8,1,18};
    int n = arr.size();
    cout<<LDS(n,arr)<<endl;
}
