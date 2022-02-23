#include<bits/stdc++.h>
using namespace std;

int func(vector<int> &nums)
{
    int n=nums.size();
    int prev=nums[0];
    int prev2=0;
    int curi;
    for(int i=1;i<n;i++)
    {
        int pick = nums[i] + prev2;
        int notpick = prev;
        curi = max(pick, notpick);
        prev2 = prev;
        prev = curi;
    }
    return prev;
}

int checkRobber(vector<int> &nums)
{
    int n = nums.size();
    vector<int> check1(n),check2(n);
    for(int i=0;i<n;i++)
    {
        if(i!=0) check2.push_back(nums[i]);
        if(i!=n-1) check1.push_back(nums[i]);
    }
    return max(func(check1), func(check2));
}

int main()
{
  // First and last are adjacent to each other
    vector<int> nums = {2,3,4,9,5};
    cout<<checkRobber(nums);
    return 0;
}
