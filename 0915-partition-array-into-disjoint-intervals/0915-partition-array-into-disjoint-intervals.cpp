using ll = long long int;
class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        //create prefix max array from starting
        vector<ll> premax(n);
        premax[0] = (ll)nums[0];
        for(int i=1; i<n; i++) premax[i] = max(premax[i-1], (ll)nums[i]);
        
        //create postfix min array from last
        vector<ll> postmin(n);
        postmin[n-1] = (ll)nums[n-1];
        for(int i=n-2; i>=0; i--) postmin[i] = min(postmin[i+1], (ll)nums[i]);
        
        //now find a position where premax[i] <= postmin[i+1] if found return i;
        int ans = 0;
        for(int i=0; i<n-1; i++){
            if(premax[i] <= postmin[i+1]){
                ans = i;
                break;
            }
        }
        return (ans+1); //as we need length of left partition
    }
};