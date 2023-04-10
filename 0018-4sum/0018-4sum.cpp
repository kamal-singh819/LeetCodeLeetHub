#define ll long long int
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        if(n < 4) return {};
        set<vector<int>> st;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                ll temp = (ll)target - ((ll)nums[i]+(ll)nums[j]);
                int x = j+1;
                int y = n-1;
                while(x < y && x < n && y < n){
                    vector<int> v;
                    if(nums[x]+nums[y] == temp){
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[x]);
                        v.push_back(nums[y]);
                        st.insert(v);
                        y--;
                        x++;
                    }
                    else if((ll)nums[x]+(ll)nums[y] > temp){
                        while(x < y && (ll)nums[y] == (ll)nums[y-1]) y--;
                        y--;
                    }
                    else{
                        while(x < y && (ll)nums[x] == (ll)nums[x+1]) x++;
                        x++;
                    }
                }
            }
        }
        vector<vector<int> > ans(st.begin(), st.end());
        return ans;
    }
};