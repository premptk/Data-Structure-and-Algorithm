class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        unordered_set<int> st;
        for(auto it : nums)
            st.insert(it);

        int ans = 1;
        for(auto it : st){
            if(st.find(it - 1) == st.end()){
                int k = it, cnt = 1;
                while(st.find(k+1) != st.end()){
                    cnt = cnt + 1;
                    k = k + 1;
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};
