class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int n = nums.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(nums[j] - nums[i] == diff){
                    int x = diff + nums[j];
                    //use binary search to search x in nums from j+1 to n
                    bool ispresent = binary_search(nums.begin()+(j+1), nums.end(), x);
                    if(ispresent) ans++;  
                }
            }
        }
        return ans;
        
    }
};