#include<bits/stdc++.h>
using namespace std;

int BuySell(vector<int> &prices)
{
    int n = prices.size();
    int maxProfit = 0;
    int mini = prices[0];
    for(int i=1;i<n;i++)
    {
        int profit = prices[i] - mini;
        maxProfit = max(maxProfit, profit);
        mini = min(prices[i],mini);
    }
    return maxProfit;
}

int main()
{
    vector<int> arr = {7,1,5,3,6,4};
    cout<<BuySell(arr)<<endl;
    return 0;
}
