class Solution {
    public int minDistance(String word1, String word2) {
        //first find the Longest Common Subsequence between word1 and word2
        
        int m = word1.length();
        int n = word2.length();
        // create dp table of (m+1)*(n+1) size
        int[][] dp = new int[m+1][n+1];
        //fill first row & col with 0.
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if(i == 0 || j == 0)
                    dp[i][j] = 0;
            }
        }

        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(word1.charAt(i-1) == word2.charAt(j-1)) dp[i][j] = dp[i-1][j-1]+1;
                else dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]);
            }
        }
        //now dp is created,
        int lcs = dp[m][n]; //length of Longest Common subsequence
        int ans = (m-lcs) + (n-lcs);
        return ans;
    }
}