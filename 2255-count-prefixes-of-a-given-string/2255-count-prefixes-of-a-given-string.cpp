class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int ans = 0;
        for(auto str : words){
            if(str == s.substr(0, str.length())) ans++;
        }
        return ans;
    }
};