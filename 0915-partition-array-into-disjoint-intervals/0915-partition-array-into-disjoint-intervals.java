class Solution {
    public int partitionDisjoint(int[] nums) {
        int n = nums.length;
        //create prefix max array (from starting)
        int[] premax = new int[n];
        premax[0] = nums[0];
        for(int i=1; i<n; i++) premax[i] = Math.max(premax[i-1], nums[i]);
        
        //create postfix min array (from last)
        int[] postmin = new int[n];
        postmin[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--) postmin[i] = Math.min(postmin[i+1], nums[i]);
        
        //now find an index such that premax[i] <= postmin[i+1]
        int ans = 0;
        for(int i=0; i<n-1; i++){
            if(premax[i] <= postmin[i+1]){
                ans = i;
                break;
            }
        }
        return ans+1; //as we need size of left array
    }
}