#include<bits/stdc++.h>
using namespace std;

void CombinationSum(int ind, int target, vector<int> arr, vector<vector<int>>& ans, vector<int> &ds)
{
    if(ind == arr.size())
    {
        if(target==0)
        {
            ans.push_back(ds);
        }
        return;
    }
    if(arr[ind]<=target)
    {
        // taken
        ds.push_back(arr[ind]);
        CombinationSum(ind, target - arr[ind], arr, ans, ds);
        ds.pop_back();
    }
    // not taken
    CombinationSum(ind+1, target, arr, ans, ds);
}

int main()
{
    vector<vector<int>> ans;
    vector<int> arr = {2,3,6,7};
    int target = 7;
    vector<int> ds;
    CombinationSum(0,target, arr,ans,ds);
    for(auto it : ans){
        for(auto z : it)
            cout<<z<<" ";
        cout<<"\n";
    }
    return 0;
}
