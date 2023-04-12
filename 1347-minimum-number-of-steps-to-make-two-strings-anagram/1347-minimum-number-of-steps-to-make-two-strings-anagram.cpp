class Solution {
public:
    int minSteps(string s, string t) {
        int n = t.length();
        unordered_map<char, int> mp; //store char with its count in map of string s
        for(int i=0; i<s.length(); i++) mp[s[i]]++;
        int ans = 0;
        for(int i=0; i<n; i++){
            if(!mp.count(t[i])) ans++;
            else{
                if(mp[t[i]] >= 1) mp[t[i]]--;
                else ans++;
            }
        }
        return ans;
    }
};