class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        unordered_map<char, int> mp;
        for(int i=0; i<s.length(); i++){
            if(!mp.count(s[i])) mp[s[i]] = i;
            else if(mp.count(s[i])){
                if((i-mp[s[i]]-1) != distance[s[i]-'a']) return false;
            }
        }
        return true;  
        
    }
};