class Solution {
private:
    bool check(string ans, string num){
        if(ans.length() == 0) return true;
        
        int i = 0;
        while(i < ans.length()){
            if(ans[i] == num[i]) i++;
            else if(ans[i] < num[i]) return true;
            else return false;
        }
        return true;
    }
public:
    string removeDigit(string number, char digit) {
        int n = number.length();
        string ans = "";
        for(int i=0; i<n; i++){
            if(number[i] == digit){
                string num = number.substr(0, i) + number.substr(i+1, n-(i+1));
                if(check(ans, num)){ //if num is greater than prev, condion will be true
                    ans = num;
                }
            }
        }
        return ans;
    }
};