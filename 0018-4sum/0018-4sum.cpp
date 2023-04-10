#define ll long long int
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        if(n < 4) return {};
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                ll temp = (ll)target - ((ll)nums[i]+(ll)nums[j]);
                int x = j+1;
                int y = n-1;
                while(x < y && x < n && y < n){
                    if(nums[x]+nums[y] == temp){
                        ans.push_back({nums[i], nums[j], nums[x], nums[y]});
                        int tempIndex1 = x, tempIndex2 = y;
                        while(x < y && nums[x] == nums[tempIndex1]) x++; //to remove duplicasy
                        while(x < y && nums[y] == nums[tempIndex2]) y--; //to remove duplicasy
                    }
                    else if((ll)nums[x]+(ll)nums[y] > temp) y--;
                    else x++;
                }
                while(j < n-1 && nums[j] == nums[j+1]) j++; //to remove duplicasy
            }
            while(i < n-1 && nums[i] == nums[i+1]) i++; //to remove duplicasy
        }
        return ans;
    }
};