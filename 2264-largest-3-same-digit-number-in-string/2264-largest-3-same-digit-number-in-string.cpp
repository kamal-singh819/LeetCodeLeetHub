class Solution {
private:
    bool satisfy(string ans, string str){
        if(ans == "") return true;
        for(int i=0; i<3; i++){
            if(ans[i] < str[i]) return true;
        }
        return false;
    }
public:
    string largestGoodInteger(string num) {
        int n = num.length();
        string ans = "";
        for(int i=0; i<n-2; i++){
            if(num[i] == num[i+1] && num[i] == num[i+2]){
                string str = num.substr(i, 3);
                if(satisfy(ans, str)) ans = str;
            }
        }
        return ans;
    }
};