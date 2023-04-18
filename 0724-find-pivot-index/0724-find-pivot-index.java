class Solution {
    public int pivotIndex(int[] nums) {
        int n = nums.length;
        if(n == 1) return 0;
        //create prefix array
        for(int i=1; i<n; i++){
            nums[i] = nums[i-1] + nums[i];
        }
        if(nums[n-1]-nums[0] == 0) return 0;
        for(int i=1; i<n-1; i++){
            if(i > 0 && nums[i-1] == nums[n-1]-nums[i]) return i;
        }
        if(nums[n-2] == 0) return n-1;
        return -1;
    }
}
