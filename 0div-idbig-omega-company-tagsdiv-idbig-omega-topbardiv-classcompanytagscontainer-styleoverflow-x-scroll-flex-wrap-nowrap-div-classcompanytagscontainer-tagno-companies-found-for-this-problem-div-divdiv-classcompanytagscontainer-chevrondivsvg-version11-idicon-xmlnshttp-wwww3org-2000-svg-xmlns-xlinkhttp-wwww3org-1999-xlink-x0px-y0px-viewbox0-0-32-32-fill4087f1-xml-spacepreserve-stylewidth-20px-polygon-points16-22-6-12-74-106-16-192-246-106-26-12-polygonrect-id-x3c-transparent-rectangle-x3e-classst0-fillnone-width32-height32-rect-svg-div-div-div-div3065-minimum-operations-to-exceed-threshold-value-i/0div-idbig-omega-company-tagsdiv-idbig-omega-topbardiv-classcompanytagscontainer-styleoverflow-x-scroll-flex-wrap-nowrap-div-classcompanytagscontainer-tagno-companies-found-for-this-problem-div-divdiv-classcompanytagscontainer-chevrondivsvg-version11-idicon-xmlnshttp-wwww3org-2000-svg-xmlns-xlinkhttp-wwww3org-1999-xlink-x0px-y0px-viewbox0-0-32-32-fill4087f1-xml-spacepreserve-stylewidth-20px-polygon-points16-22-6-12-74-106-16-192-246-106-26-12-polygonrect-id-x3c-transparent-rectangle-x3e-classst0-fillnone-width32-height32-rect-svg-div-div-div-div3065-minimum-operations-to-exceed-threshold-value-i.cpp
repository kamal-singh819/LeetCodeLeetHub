class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int x : nums) {
            if(x < k) ans++;
            else return ans;
        }
        return ans;
    }
};