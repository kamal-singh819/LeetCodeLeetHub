class Solution {
private:
    void function(int ind, int &k, int n, vector<int> &output, vector<vector<int>> &ans){
        if(output.size() == k && n == 0){
            ans.push_back(output);
            return;
        }
        //we are checking every subset which can start from i
        for(int i=ind; i<9; i++){
            if(i+1 > n) break;
            output.push_back(i+1);
            n = n - (i+1);
            function(i+1, k, n, output, ans);
            output.pop_back();
            n = n + (i+1);
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> output;
        int ind = 0;
        function(ind, k, n, output, ans);
        return ans;
    }
};