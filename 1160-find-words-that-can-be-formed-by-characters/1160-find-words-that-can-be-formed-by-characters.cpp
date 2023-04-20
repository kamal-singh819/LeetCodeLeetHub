class Solution {
public:
    bool possible(string str, unordered_map<char, int> mp){
        for(int i=0; i<str.length(); i++){
            if(mp.count(str[i]) && mp[str[i]] > 0) mp[str[i]]--;
            else return false;
        }
        return true;
    }
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> mp;
        for(int i=0; i<chars.length(); i++) mp[chars[i]]++;
        
        int ans = 0;
        for(int i=0; i<words.size(); i++){
            if(possible(words[i], mp)) ans += words[i].length();
        }
        return ans;
    }
};