class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        //create prefix array
        for(int i=1; i<n; i++) nums[i] = nums[i-1] + nums[i];
        
        int ans = -1;
        for(int i=0; i<n-1; i++){
            if(i == 0 && nums[n-1]-nums[0] == 0) return 0;
            else if(i > 0 && nums[i-1] == nums[n-1]-nums[i]) return i;
        }
        if(nums[n-2] == 0) return n-1;
        return ans;
    }
};