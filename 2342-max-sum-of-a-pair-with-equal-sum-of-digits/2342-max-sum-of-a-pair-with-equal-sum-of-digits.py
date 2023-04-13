class Solution {
private:
    int sumOfDigits(int x){
        int summ = 0;
        while(x > 0){
            summ += x%10;
            x /= 10;
        }
        return summ;
    }
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int n = nums.size();
        for(int i=0; i<n; i++){
            int summ = sumOfDigits(nums[i]);
            mp[summ].push_back(nums[i]);
        }
        int ans = -1;
        for(auto p : mp){
            vector<int> v = p.second;
            int m = v.size();
            if(m <= 1) continue;
            sort(v.begin(), v.end());
            ans = max(ans, (v[m-1]+v[m-2]));
        }
        return ans;
    }
};