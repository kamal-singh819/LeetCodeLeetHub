class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char, char> mp;
        int n = key.length();
        int k = 0;
        for(int i=0; i<n; i++){
            if(key[i] == ' ') continue;
            else if(!mp.count(key[i])){
                mp[key[i]] = ('a'+k);
                k++;
            }
        }
        string ans = "";
        for(int i=0; i<message.length(); i++){
            if(message[i] == ' ') ans += ' ';
            else ans += mp[message[i]];
        }
        return ans;
    }
};