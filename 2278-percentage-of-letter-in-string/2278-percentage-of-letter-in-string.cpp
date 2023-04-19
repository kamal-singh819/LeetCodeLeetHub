class Solution {
public:
    int percentageLetter(string s, char letter) {
        int n = s.length();
        int occ = count(s.begin(), s.end(), letter);
        return (occ*100)/n;
    }
};