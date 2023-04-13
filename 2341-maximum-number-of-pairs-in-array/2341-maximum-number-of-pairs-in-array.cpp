class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        if(nums.size() == 1) return {0, 1};
        int M = 2;
        vector<int> ans(M, 0);
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++) mp[nums[i]]++;
        for(auto p : mp){
            ans[0] += p.second/2;
            ans[1] += p.second%2;
        }
        return ans;
    }
};