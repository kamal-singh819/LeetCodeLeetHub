class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n-2, vector<int> (n-2));
        
        for(int i=0; i<n-2; i++){
            for(int j=0; j<n-2; j++){
                int k = i;
                int val = 0;
                while(k<n && k < i+3){
                    int l = j;
                    while(l<n && l < j+3){
                        val = max(val, grid[k][l]);
                        l++;
                    }
                    k++;
                }
                ans[i][j] = val;
            }
        }
        return ans;
    }
};