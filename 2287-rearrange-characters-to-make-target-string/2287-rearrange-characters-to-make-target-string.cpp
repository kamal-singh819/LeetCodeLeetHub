class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char, int> mps;
        for(int i=0; i<s.length(); i++) mps[s[i]]++;
        
        unordered_map<char, int> mpt;
        for(int i=0; i<target.length(); i++) mpt[target[i]]++;
        
        int ans = 200;
        for(int i=0; i<target.length(); i++){
            if(mps.count(target[i])){
                ans = min(ans, mps[target[i]]/mpt[target[i]]);
            }
            if(!mps.count(target[i])) return 0;
        }
        return ans;
    }
};