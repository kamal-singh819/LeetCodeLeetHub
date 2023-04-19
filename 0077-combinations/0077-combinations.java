class Solution {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> output = new ArrayList<>();
        int start = 0;
        recFunction(start, n, k, output, ans);
        return ans;
    }
    
    void recFunction(int start, int n, int k, List<Integer> output, List<List<Integer>> ans){
        if(output.size() == k){
            ans.add(new ArrayList<>(output));
            return;
        }
        //we don't want any sum, we need only subsets
        //try for all subset which can start with any number between [1,n]
        for(int i=start; i<n; i++){
            output.add(i+1);
            recFunction(i+1, n, k, output, ans);
            //backtrack
            output.remove(output.size()-1);
        }
    }
}