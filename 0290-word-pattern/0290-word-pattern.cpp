class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mpp; //pattern->s
        unordered_map<string, char> mps; //s->pattern
        int n = s.length();
        int i = 0; //for string s
        int k = 0; //for string pattern
        while(i < n && k < pattern.length()){
            int j = i;
            string str = "";
            while(j < n && s[j] != ' '){
                str += s[j];
                j++;
            }
            i = j+1; //i represent to first char of next word in s
            
            if(!mpp.count(pattern[k]) && !mps.count(str)){
                mpp[pattern[k]] = str;
                mps[str] = pattern[k];
            }
            else if(mpp.count(pattern[k]) && mps.count(str)){
                if(mpp[pattern[k]] != str || mps[str] != pattern[k]) return false;
            }
            else return false;
            k++;
            
        }
        if(i == n+1 && k == pattern.length()) return true;
        return false; 
    }
};