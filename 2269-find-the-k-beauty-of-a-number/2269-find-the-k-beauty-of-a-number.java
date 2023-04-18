class Solution {
    public int divisorSubstrings(int num, int k) {
        String numm = Integer.toString(num);
        int i=0, j=0;
        String div = "";
        int ans = 0;
        while(j < numm.length()){
            div += numm.charAt(j);
            if(j-i+1 == k){
                if(Integer.parseInt(div) != 0 && num%(Integer.parseInt(div)) == 0) ans++;
                div = div.substring(1, k); //(1, 1+k-1)
                i++;
            }
            j++;
        }
        return ans;
    }
}