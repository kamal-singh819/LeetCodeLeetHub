class Solution {
private:
    void recFunction(int start, int &n, int &k, vector<int> &output, vector<vector<int>> &ans){
        if(output.size() == k){
            ans.push_back(output);
            return;
        }
        //we don't want any sum, we need only subsets
        //try for all subset which can start with any number between [1,n]
        for(int i=start; i<n; i++){
            output.push_back((i+1));
            recFunction(i+1, n, k, output, ans);
            //backtrack
            output.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> output;
        int start = 0;
        recFunction(start, n, k, output, ans);
        return ans;
    }
};