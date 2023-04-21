class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return 0;
        int ans = 0;
        //first remove adjacent duplicates
        vector<int> temp;
        int i = 0;
        while(i < n){
            temp.push_back(nums[i]);
            //cout<<nums[i]<<" ";
            int j = i+1;
            while(j < n && nums[i] == nums[j]){
                j++;
            }
            i = j;
        }
        
        i = 1;
        while(i < temp.size()-1){
            if(temp[i] > temp[i-1] && temp[i] > temp[i+1]) ans++;
            else if(temp[i] < temp[i-1] && temp[i] < temp[i+1]) ans++;
            i++;
        }
        return ans;
    }
};