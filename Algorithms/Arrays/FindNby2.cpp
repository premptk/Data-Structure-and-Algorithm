#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums)
{
    int n = nums.size();
    int candidate=-1,votes=0;
    for(int i=0;i<n;i++)
    {
        if(votes==0)
        {
            candidate = nums[i];
            votes=1;
        }
        else
        {
            if(nums[i]==candidate)
                votes++;
            else
                votes--;
        }
    }

    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(candidate==nums[i])
            cnt++;
    }

    if(cnt>n/2)
        return candidate;
    else return -1;
}

int main()
{
    vector<int> nums = {2,2,1,1,1,2,2};
    cout<<solve(nums);
    return 0;
}
