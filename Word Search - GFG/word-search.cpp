//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    bool dfs(int i, int j, vector<vector<char>>& board, int k, string word, int &m, int &n){
        if(k == word.length()) return true;
        
        if(i >= m || i < 0 || j >= n || j < 0 || board[i][j] == '0' || board[i][j] != word[k])
            return false;
        
        int temp = board[i][j];
        board[i][j] = '0'; //mark visited
        
        bool res = false;
        //call right
        res = res | dfs(i, j+1, board, k+1, word, m, n);
        //cal left
        res = res | dfs(i, j-1, board, k+1, word, m, n);
        //call up
        res = res | dfs(i-1, j, board, k+1, word, m, n);
        //call down
        res = res | dfs(i+1, j, board, k+1, word, m, n);
        
        //now backtrack (undo changes)
        board[i][j] = temp;
        return res;
    }
public:
    bool isWordExist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == word[0]){
                    bool res = dfs(i, j, board, 0, word, m, n); //k is for traversing word
                    if(res) return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends