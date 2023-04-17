class Solution {
    public String largestGoodInteger(String num) {
        int n = num.length();
        String ans = "";
        for(int i=0; i<n-2; i++){
            if(num.charAt(i) == num.charAt(i+1) && num.charAt(i) == num.charAt(i+2)){
                String substr = num.substring(i, i+3);
                if(satisfy(ans, substr)) ans = substr;
            }
        }
        return ans;  
    }
    
     boolean satisfy(String ans, String str){
        if(ans == "") return true;
        for(int i=0; i<3; i++){
            if(ans.charAt(i) < str.charAt(i)) return true;
        }
        return false;
    }
}