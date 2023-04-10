class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_set<int> st; // will store the sum
        for(int i=1; i<nums.size(); i++){
            int summ = nums[i-1] + nums[i];
            if(st.count(summ)) return true;
            else st.insert(summ);
        }
        return false;
    }
};