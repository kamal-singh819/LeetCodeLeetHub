class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr;
        while(n > 1){
            bool flag = true;
            for(int i=0; i<n-1; i += 2){
                if(flag){
                    arr.push_back(min(nums[i], nums[i+1]));
                    flag = false;
                }
                else{
                    arr.push_back(max(nums[i], nums[i+1])); 
                    flag = true;
                }
            }
            n = n/2;
            nums = arr;
            arr.clear();
        }
        return nums[0];
    }
};