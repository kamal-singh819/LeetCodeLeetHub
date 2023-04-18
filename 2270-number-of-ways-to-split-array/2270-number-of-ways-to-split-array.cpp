class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return 0;
        int ans = 0;
        long long total = nums[0]; //store total sum of array
        //find prefix sum of nums
        vector<long long> prefix(n);
        prefix[0] = (long long)nums[0];
        for(int i=1; i<n; i++){
            total += (long long)nums[i];
            prefix[i] = prefix[i-1] + (long long)nums[i];
        }

        for(int i=0; i<n-1; i++){
            if(prefix[i] >= total-prefix[i]) ans++;
        }
        return ans;
    }
};