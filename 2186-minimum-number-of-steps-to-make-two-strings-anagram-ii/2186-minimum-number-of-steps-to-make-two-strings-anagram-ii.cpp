class Solution {
public:
    int minSteps(string s, string t) {
        int ans = 0;
        unordered_map<char, int> mp; //for s
        for(int i=0; i<s.length(); i++) mp[s[i]]++;
        for(int i=0; i<t.length(); i++){
            if(!mp.count(t[i])) ans++;
            else{
                if(mp[t[i]] >= 1) mp[t[i]]--;
                else ans++;
            }
        }
        for(auto x : mp){
            ans += x.second;
        }
        return ans;
    }
};