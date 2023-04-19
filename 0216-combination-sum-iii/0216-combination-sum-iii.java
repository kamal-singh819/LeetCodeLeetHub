class Solution {
    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> output = new ArrayList<>();
        int ind = 0;
        function(ind, k, n, output, ans);
        return ans;
    }
    
    static void function(int ind, int k, int n, List<Integer> output, List<List<Integer>> ans){
        if(output.size() == k && n == 0){
            ans.add(new ArrayList<>(output));
            return;
        }
        //we are checking every subset which can start from i
        for(int i=ind; i<9; i++){
            if(i+1 > n) break;
            output.add(i+1);
            n = n - (i+1);
            function(i+1, k, n, output, ans);
            output.remove(output.size()-1);
            n = n + (i+1);
        }
    }
}