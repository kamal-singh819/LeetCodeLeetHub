class Solution {
public:
    string lastNonEmptyString(string s) {
        int n = s.length();
        int mxCount = 0;
        unordered_map<char, int> mp;
        for(char ch : s){
            mp[ch]++;
            mxCount = max(mxCount, mp[ch]);
        }
        string ans = "";
        unordered_set<char> track;
        for(int i=n-1; i>=0; i--){
            if(!track.count(s[i]) && mp[s[i]] == mxCount){
                ans = s[i]+ans;
                track.insert(s[i]);
            }
        }
        return ans;
    }
};