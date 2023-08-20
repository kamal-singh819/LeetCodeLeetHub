//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int fun(int i, int j, vector<vector<int> >& mat, int &m, int &n){
        int zeros = 0;
        
        if(i+1 < m && mat[i+1][j] == 0) zeros++;
        if(i-1 >= 0 && mat[i-1][j] == 0) zeros++;
        if(j+1 < n && mat[i][j+1] == 0) zeros++;
        if(j-1 >= 0 && mat[i][j-1] == 0) zeros++;
        if(i+1 < m && j+1 < n && mat[i+1][j+1] == 0) zeros++;
        if(i-1 >= 0 && j-1 >= 0 && mat[i-1][j-1] == 0) zeros++;
        if(i-1 >= 0 && j+1 < n &&  mat[i-1][j+1] == 0) zeros++;
        if(i+1 < m && j-1 >= 0 && mat[i+1][j-1] == 0) zeros++;
        
        return zeros;
    }
    int Count(vector<vector<int> >& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 0) continue;
                int res = fun(i, j, matrix, m, n);
                if(res != 0 && res%2 == 0) ans++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends