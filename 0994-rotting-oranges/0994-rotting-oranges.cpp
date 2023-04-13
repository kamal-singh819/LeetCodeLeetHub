class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        
        //first push all rotten oranges into queue
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2) q.push({i, j});
            }
        }
        
        int ans = 0;
        while(!q.empty()){
            int siz = q.size();
            bool flag = false; //there may be possible the after some operations, no oranges is good,
            while(siz--){
                auto f = q.front();
                q.pop();
                //mark all 4 directions of f(rotten already)
                //right
                if(f.second+1 < n && grid[f.first][f.second+1] == 1){
                    grid[f.first][f.second+1] = 2;
                    flag = true;
                    q.push({f.first, f.second+1});
                }
                //left
                if(f.second-1 >= 0 && grid[f.first][f.second-1] == 1){
                    grid[f.first][f.second-1] = 2;
                    flag = true;
                    q.push({f.first, f.second-1});
                }
                //down
                if(f.first+1 < m && grid[f.first+1][f.second] == 1){
                    grid[f.first+1][f.second] = 2;
                    flag = true;
                    q.push({f.first+1, f.second});
                }
                //up
                if(f.first-1 >= 0 && grid[f.first-1][f.second] == 1){
                    grid[f.first-1][f.second] = 2;
                    flag = true;
                    q.push({f.first-1, f.second});
                }
            }
            if(flag) ans++;
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        return ans;
    }
};