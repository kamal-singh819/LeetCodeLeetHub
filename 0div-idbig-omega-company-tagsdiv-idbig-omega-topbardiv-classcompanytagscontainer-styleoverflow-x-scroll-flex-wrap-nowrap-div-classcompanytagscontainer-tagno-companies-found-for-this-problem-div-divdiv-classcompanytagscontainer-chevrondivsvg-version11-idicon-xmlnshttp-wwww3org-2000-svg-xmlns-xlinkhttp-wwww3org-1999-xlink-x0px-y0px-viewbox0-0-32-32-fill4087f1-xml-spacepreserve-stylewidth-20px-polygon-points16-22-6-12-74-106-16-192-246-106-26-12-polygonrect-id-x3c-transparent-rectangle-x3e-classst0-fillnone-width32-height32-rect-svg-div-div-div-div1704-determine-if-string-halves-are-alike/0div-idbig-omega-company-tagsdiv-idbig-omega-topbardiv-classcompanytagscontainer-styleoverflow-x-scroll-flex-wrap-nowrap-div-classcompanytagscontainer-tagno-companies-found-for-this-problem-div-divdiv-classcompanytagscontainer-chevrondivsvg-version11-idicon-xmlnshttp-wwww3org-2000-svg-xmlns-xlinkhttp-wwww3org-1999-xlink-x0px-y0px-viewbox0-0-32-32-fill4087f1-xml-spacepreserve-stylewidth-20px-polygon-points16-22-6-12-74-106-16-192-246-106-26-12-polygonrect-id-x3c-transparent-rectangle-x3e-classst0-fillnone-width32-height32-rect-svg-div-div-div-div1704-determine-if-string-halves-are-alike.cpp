class Solution {
public:
    bool halvesAreAlike(string s) {
        int len = s.length();

        int x = 0;
        int y = 0;

        for(int i=0; i<len; i++){
            if(i<len/2 && (s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' ||
                  s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U')){
                x++;
            }

            else if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' ||
                  s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
                y++;
            }        
        }   
        if(x == y)
           return true;
        else return false;      
        
    }
};