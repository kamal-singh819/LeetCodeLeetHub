class Solution {
    public int waysToSplitArray(int[] nums) {
        int n = nums.length;
        if(n <= 1) return 0;
        int ans = 0;
        //create prefix array
        long[] prefix = new long[n];
        prefix[0] = (long)nums[0];
        long total = nums[0];
        for(int i=1; i<n; i++){
            total += (long)nums[i];
            prefix[i] = prefix[i-1] + (long)nums[i];
        }
        
        for(int i=0; i<n-1; i++){
            if(prefix[i] >= total-prefix[i]) ans++;
        }
        return ans;
    }
}