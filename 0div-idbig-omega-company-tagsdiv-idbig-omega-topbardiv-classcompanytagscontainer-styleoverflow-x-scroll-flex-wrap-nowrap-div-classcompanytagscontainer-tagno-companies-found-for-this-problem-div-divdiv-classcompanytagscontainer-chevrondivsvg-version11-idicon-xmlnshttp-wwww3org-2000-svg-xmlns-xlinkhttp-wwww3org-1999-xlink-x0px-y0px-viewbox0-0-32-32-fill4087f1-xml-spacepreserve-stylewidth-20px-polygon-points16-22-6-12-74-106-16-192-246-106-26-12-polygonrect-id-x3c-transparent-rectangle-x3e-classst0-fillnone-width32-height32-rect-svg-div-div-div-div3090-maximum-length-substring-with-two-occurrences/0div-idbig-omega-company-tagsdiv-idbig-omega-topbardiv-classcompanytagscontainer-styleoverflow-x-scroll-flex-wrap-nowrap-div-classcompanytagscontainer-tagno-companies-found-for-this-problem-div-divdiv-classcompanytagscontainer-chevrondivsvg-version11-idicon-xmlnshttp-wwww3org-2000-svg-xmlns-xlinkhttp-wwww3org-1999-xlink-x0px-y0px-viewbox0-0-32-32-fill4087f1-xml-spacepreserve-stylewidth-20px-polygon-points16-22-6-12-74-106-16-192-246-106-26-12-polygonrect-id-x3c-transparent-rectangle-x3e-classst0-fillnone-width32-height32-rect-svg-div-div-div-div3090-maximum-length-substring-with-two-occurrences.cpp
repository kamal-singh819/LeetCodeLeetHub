class Solution {
public:
    int countOccurence(unordered_map<char, int> &mp) {
        for(auto x : mp){
            if(x.second > 2) return false;
        }
        return true;
    }
    int maximumLengthSubstring(string s) {
        int n = s.length();
        unordered_map<char, int> mp;
        int i = 0;
        int j = 0;
        int ans = 0;
        while(j < n){
            mp[s[j]]++;
            if(countOccurence(mp)) ans = max(ans, j-i+1);
            else {
                mp[s[i]]--;
                if(mp[s[i]] == 0) mp.erase(s[i]);
                i++;
            }
            j++;
        }
        return ans;
    }
};
