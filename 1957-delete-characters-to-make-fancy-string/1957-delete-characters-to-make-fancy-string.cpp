class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        int n = s.length();
        int i = 0;
        while(i < n){
            if(i < n-1 && s[i] != s[i+1]){
                ans += s[i];
                i++;
            }
            else if(i == n-1){
                ans += s[n-1];
                i++;
            }
            else{
                char ch = s[i];
                int cnt = 0;
                while(i < n && ch == s[i]){
                    cnt++;
                    i++;
                }
                if(cnt >= 2){
                    ans += ch;
                    ans += ch;
                }
            }
        }
        return ans;
    }
};