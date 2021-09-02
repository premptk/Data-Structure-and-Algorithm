#include<bits/stdc++.h>
using namespace std;

//Leetcode 525
int solve(vector<int> nums)
{
    int result = 0, sum = 0;
		unordered_map<int,int> mp;
		mp[0] = -1;

		for(int i =0;i<nums.size();i++){
			if(nums[i] == 0){
				sum += -1; //treat 0 as -1
			}else{
				sum += 1;
			}

			if(mp.find(sum) != mp.end())
            {
				int length = i - mp[sum];
				if(length > result)result = length;
			}else{
				mp[sum] = i;
            }
		}
		return result;
}

int main()
{
    vector<int> v={0,1,1,0,1,1};
    cout<<solve(v);
    return 0;
}
