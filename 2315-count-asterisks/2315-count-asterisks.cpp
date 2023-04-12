class Solution {
public:
    int countAsterisks(string s) {
        int ans = 0;
        int i = 0;
        int n = s.length();
        while(i < n){
            int j = i;
            while(j < n && s[j] != '|'){
                if(s[j] == '*') ans++;
                j++;
            }
            if(s[j] == '|'){
                j++;
                while(j < n && s[j] != '|') j++;
            }
            i = j+1;
        }
        return ans; 
    }
};