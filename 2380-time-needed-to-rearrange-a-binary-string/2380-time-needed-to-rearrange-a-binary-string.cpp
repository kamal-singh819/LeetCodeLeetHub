class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int n = s.length();
        int one = 0;
        int zero = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '1') one++;
            if(s[i] == '0') zero++;
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            bool flag = false;
            for(int j=0; j<n-1; ){
                if(s[j] == '0' && s[j+1] == '1'){
                    swap(s[j], s[j+1]);
                    j += 2;
                    flag = true;
                }
                else j++;
            }
            if(flag) ans++;
            else if(flag == false) return ans;
        }
        return ans;  
    }
};