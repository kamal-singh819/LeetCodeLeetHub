class Solution {
private:
    bool isPossible(int diff, int &p, vector<int> &nums){
        int d = 0;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i+1]-nums[i] <= diff){
                d++;
                i++;
            }
        } 
        if(d >= p) return true;
        return false;
    }
public:
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int mindiff = 0;
        int maxdiff = nums[n-1];
        int ans = 0;
        while(mindiff <= maxdiff){
            int mid = mindiff + (maxdiff - mindiff)/2;
            if(isPossible(mid, p, nums)){
                ans = mid;
                maxdiff = mid-1;
            }
            else mindiff = mid+1;
        }
        return ans;   
    }
};