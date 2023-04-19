class Solution {
    public int sumOfBeauties(int[] nums) {
        //brute force : check for every index T.C = O(n*n), give TLE
        //use prefix max(no need to maintain array) and postfix min arrays
        //T.C = O(n) && S.C = O(n)
        int n = nums.length;
        int mx = nums[0];
        //find postfix min array
        int[] postmin = new int[n];
        postmin[n-1] = nums[n-1];
        for(int i=n-2; i >= 0; i--) postmin[i] = Math.min(postmin[i+1], nums[i]);
        
        int ans = 0;
        //now traverse
        for(int i=1; i<n-1; i++){
            if(mx < nums[i] && nums[i] < postmin[i+1]) ans += 2;
            else if(nums[i-1] < nums[i] && nums[i] < nums[i+1]) ans += 1;
            //update mx(because we are not using prefix max array)
            mx = Math.max(mx, nums[i]);
        }
        return ans;
    }
}