class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map<int, int> mp; //will sort the key automatic
        for(auto pair : items1) mp[pair[0]] = pair[1];
        for(auto pair : items2) mp[pair[0]] += pair[1];
        
        int n = mp.size();
        vector<vector<int>> ans(n);
        int i = 0;
        for(auto x : mp){
            ans[i].push_back(x.first);
            ans[i].push_back(x.second);
            i++;
        }
        return ans; 
    }
};