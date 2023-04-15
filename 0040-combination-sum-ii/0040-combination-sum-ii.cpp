class Solution {
private:
    void function(int ind, vector<int> &nums, int &n, int target, vector<int> &sub, vector<vector<int>> &ans){
        if(target == 0){
            ans.push_back(sub);
            return;
        }
        //recursive call from each index
        for(int i=ind; i<n; i++){
            if(i > ind && nums[i] == nums[i-1]) continue; //avoid picking up same element
            if(nums[i] > target) break; //no more call, array is sorted, no more element will be smaller than target
            sub.push_back(nums[i]);
            function(i+1, nums, n, target-nums[i], sub, ans);
            sub.pop_back(); //backtrack
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> sub;
        sort(candidates.begin(), candidates.end());
        int ind = 0; //starting index
        function(ind, candidates, n, target, sub, ans);
        return ans;
    }
};