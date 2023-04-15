class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        int k = 0; //for string s
        for(int i=0; k < s.length() && i<words.size(); i++){
            if(words[i] == s.substr(k, words[i].length())){
                k += words[i].length();
            }
            else return false;
        }
        return k >= s.length() ? true : false;
    }
};