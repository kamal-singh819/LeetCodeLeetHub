//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
private:
    bool isValid(int i, int j, int &n, int &m, vector<vector<int>> &matrix, bool &res){
        if(i < 0 || j < 0 || i >= n || j >= m || matrix[i][j] == 0) return false;
        return true;
    }
    void dfs(int i, int j, int &n, int &m, vector<vector<int>> &matrix, bool &res){
        if((i == 0 || j == 0 || i == n-1 || j == m-1) && matrix[i][j] == 1) res = false;
        matrix[i][j] = 0;
        if(isValid(i+1, j, n, m, matrix, res)) dfs(i+1, j, n, m, matrix, res);
        if(isValid(i-1, j, n, m, matrix, res)) dfs(i-1, j, n, m, matrix, res);
        if(isValid(i, j+1, n, m, matrix, res)) dfs(i, j+1, n, m, matrix, res);
        if(isValid(i, j-1, n, m, matrix, res)) dfs(i, j-1, n, m, matrix, res);
    }
public:
    int closedIslands(vector<vector<int>>& matrix, int N, int M) {
        int ans = 0;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(matrix[i][j] == 1){
                    bool res = true;
                    dfs(i, j, N, M, matrix, res);
                    if(res) ans++;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends