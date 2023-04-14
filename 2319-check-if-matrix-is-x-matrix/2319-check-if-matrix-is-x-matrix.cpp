class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for(int i=0; i<n; i++){
            if(grid[i][i] == 0 || grid[i][n-i-1] == 0) return false;
            for(int j=0; j<n; j++){
                if(i != j && i != n-j-1){
                    if(grid[i][j] != 0) return false;
                    else continue;
                }
            }
        }
        return true;
    }
};