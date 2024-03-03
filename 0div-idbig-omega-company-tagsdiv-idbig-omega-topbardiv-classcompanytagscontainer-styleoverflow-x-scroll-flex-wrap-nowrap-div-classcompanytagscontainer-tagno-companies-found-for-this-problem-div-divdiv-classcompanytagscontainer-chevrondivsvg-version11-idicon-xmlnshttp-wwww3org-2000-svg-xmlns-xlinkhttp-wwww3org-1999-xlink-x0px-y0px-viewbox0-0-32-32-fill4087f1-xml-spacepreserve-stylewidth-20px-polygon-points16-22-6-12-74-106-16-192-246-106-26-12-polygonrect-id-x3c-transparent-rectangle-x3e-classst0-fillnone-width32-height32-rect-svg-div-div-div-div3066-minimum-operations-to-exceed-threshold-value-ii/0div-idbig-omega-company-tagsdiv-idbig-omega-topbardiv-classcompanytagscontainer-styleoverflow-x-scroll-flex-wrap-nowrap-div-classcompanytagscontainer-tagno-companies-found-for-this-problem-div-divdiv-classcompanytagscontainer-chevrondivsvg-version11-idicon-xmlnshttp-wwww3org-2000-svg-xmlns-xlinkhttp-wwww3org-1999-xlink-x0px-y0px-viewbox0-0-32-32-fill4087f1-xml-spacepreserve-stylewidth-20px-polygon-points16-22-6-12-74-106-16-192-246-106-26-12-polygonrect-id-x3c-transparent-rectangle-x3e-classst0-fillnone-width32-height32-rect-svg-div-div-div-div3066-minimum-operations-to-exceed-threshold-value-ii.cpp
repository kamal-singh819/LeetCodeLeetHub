class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        using ll = long long;
        priority_queue<ll, vector<ll>, greater<> > minHeap(nums.begin(), nums.end());
        int ans = 0;
        while(minHeap.top() < k){
            ll x = minHeap.top(); minHeap.pop();
            ll y = minHeap.top(); minHeap.pop();
            ll newAdd = min(x, y)*2 + max(x, y);
            minHeap.push(newAdd);
            ans++;
        }
        return ans;
    }
};