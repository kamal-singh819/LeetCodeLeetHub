class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mps;
        unordered_map<char, char> mpt;
        for(int i=0; i<s.length(); i++){
            if(!mps.count(s[i]) && !mpt.count(t[i])){
                mps[s[i]] = t[i];
                mpt[t[i]] = s[i];
                
            }
            else if(mps.count(s[i]) && mpt.count(t[i])){
                if(mps[s[i]] != t[i] || mpt[t[i]] != s[i]) return false;
            }
            else return false;
        }
        return true;  
    }
};