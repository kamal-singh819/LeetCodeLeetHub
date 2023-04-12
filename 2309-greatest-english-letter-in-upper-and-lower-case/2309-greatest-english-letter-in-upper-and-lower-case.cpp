class Solution {
public:
    string greatestLetter(string s) {
        unordered_set<char> lower;
        for(int i=0; i<s.length(); i++){
            if(islower(s[i])){
                lower.insert(toupper(s[i]));
            }
        }
        char ans = ' ';
        for(int i=0; i<s.length(); i++){
            if(isupper(s[i]) && lower.count(s[i])){
                if(ans < s[i]) ans = s[i];
            }
        }
        if(ans == ' ') return "";
        string str(1, ans);
        
        return str;
    }
};