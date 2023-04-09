class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        
        unordered_map<int, long long> mp;
        //change index to out edge and vice versa
        for(int i=0; i<n; i++){
            mp[edges[i]] += i; // v -> u (sum of all u) not u -> v
        }
 /*       //first example
        1 -> {0 = 0}
        0 -> {1+2+3+4 = 10}
        7 -> {5+6 = 11}
        5 -> {7 = 7}  */
        long long val = LLONG_MIN;
        int ans = 0;
        for(auto x : mp){
            if(x.second > val){
                ans = x.first;
                val = x.second;
            }
            else if(x.second == val){
                ans = x.first < ans ? x.first : ans;
            }
        }
        return ans;   
    }
};