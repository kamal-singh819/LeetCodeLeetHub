class Solution {
private:
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;
        while(i < version1.length() || j < version2.length()) {
            string st1 = "", st2 = "";
            while(i < version1.length() && version1[i] != '.'){
                st1 += version1[i];
                i++;
            }
            while(j < version2.length() && version2[j] != '.'){
                st2 += version2[j];
                j++;
            }
            int a = st1 == "" ? 0 : stoi(st1);
            int b = st2 == "" ? 0 : stoi(st2);
            if(a < b) return -1;
            else if(a > b) return 1;
            i++;
            j++;
            st1 = "";
            st2 = "";
        }
        return 0;
    }
};