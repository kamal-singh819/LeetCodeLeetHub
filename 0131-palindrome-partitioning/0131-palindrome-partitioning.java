class Solution {
    public List<List<String>> partition(String s) {
        List<List<String>> ans = new ArrayList<>();
        List<String> component = new ArrayList<>();
        function(0, s, component, ans);
        return ans;
    }
    
    void function(int index, String s, List<String> component, List<List<String>> ans){
        if(index == s.length()){
            ans.add(new ArrayList<>(component));
            return;
        }
        
        for(int i=index; i<s.length(); i++){
            if(isPalindrome(s, index, i)){
                component.add(s.substring(index, i+1)); //substring from index to i is palindrome
                function(i+1, s, component, ans);
                component.remove(component.size()-1);
            }
        }
    }
    
    boolean isPalindrome(String s, int i, int j){
        while(i <= j){
            if(s.charAt(i) != s.charAt(j)) return false;
            i++;
            j--;
        }
        return true;
    }
}