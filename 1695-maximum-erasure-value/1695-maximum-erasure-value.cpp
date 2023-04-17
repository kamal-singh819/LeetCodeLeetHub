class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        int ans = INT_MIN;
        int sum = 0;
        int i=0, j=0;
        while(j < n){
            if(!st.count(nums[j])){
                sum += nums[j];
                st.insert(nums[j]);
                j++;
            }
            else{
                ans = max(ans, sum);
                while(st.count(nums[j])){
                    sum -= nums[i];
                    st.erase(nums[i]);
                    i++;
                }
                st.insert(nums[j]);
                sum += nums[j];
                j++;
            }
        }
        return max(ans, sum); 
    }
};