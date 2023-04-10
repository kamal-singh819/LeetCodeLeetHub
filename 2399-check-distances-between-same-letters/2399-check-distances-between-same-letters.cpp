//                    O(N) Time and O(N) Space

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

//             O(N*N) Time and O(1) Space
class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        unordered_map<char, int> mp;
        for(int i=0; i<s.length(); i++){
            for(int j=i+1; j<s.length(); j++){
                if(s[i] == s[j]){
                    if(j-i-1 != distance[s[i]-'a']) return false;
                }
            }
        }
        return true;    
    }
};
