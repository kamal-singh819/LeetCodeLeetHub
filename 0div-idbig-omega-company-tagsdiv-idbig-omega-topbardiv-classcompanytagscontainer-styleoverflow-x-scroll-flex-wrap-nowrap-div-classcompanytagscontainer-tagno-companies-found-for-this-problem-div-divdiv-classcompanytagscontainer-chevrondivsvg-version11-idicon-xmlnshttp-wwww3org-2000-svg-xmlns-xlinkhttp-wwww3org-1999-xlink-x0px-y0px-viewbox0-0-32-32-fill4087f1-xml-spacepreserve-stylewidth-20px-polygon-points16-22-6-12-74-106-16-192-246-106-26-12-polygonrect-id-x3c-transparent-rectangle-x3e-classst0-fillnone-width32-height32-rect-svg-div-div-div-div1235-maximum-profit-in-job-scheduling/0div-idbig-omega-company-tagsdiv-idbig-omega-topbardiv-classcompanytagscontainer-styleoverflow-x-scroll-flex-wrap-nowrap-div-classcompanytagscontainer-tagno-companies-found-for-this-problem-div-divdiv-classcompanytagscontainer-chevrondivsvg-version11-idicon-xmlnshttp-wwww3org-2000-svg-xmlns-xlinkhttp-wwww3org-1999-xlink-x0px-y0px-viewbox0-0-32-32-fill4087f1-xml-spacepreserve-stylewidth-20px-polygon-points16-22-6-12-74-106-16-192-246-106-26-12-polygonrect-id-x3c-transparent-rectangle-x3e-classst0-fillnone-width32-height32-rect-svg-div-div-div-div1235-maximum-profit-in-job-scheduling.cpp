class Solution {
public:
    int fun(int i, int &n, vector<int> &st, vector<vector<int>> &vec, vector<int> &dp){
        if(i >= n) return 0;

        if(dp[i] != -1) return dp[i];
        //choice 1 - Take
        int newInd = lower_bound(st.begin(), st.end(), vec[i][1]) - st.begin();
        int take = vec[i][2] + fun(newInd, n, st, vec, dp);
        //choice 2 - not-take
        int nottake = fun(i+1, n, st, vec, dp);
        return dp[i] = max(take, nottake);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();
        vector<vector<int>> vec;
        for(int i=0; i<n; i++){
            vec.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(vec.begin(), vec.end());
        sort(startTime.begin(), startTime.end());
        vector<int> dp(n, -1);
        return fun(0, n, startTime, vec, dp);
    }
};