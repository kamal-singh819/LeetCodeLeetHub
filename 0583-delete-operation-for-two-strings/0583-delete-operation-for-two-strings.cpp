class Solution {
public:
    int minDistance(string word1, string word2) {
        //first find the Longest Common Subsequence between word1 and word2
        
        int m = word1.length();
        int n = word2.length();
        // create dp table of (m+1)*(n+1) size
        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
        //fill first row & col with 0. (already filled by above line)
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1]+1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        //now dp is created,
        int lcs = dp[m][n]; //length of Longest Common subsequence
        int ans = (m-lcs) + (n-lcs);
        return ans;
    }
};