class Solution {
private:
    vector<int> convertToIntegers(string version) {
        vector<int> ver;
        string str = "";
        int i  = 0;
        while(i < version.length()) {
            if(version[i] == '.'){
                ver.push_back(stoi(str));
                str = "";
            }
            else str += version[i];
            i++;
        }
        if(str != "") ver.push_back(stoi(str));
        return ver;
    }
public:
    int compareVersion(string version1, string version2) {
        vector<int> ver1 = convertToIntegers(version1);
        vector<int> ver2 = convertToIntegers(version2);
        int i = 0, j = 0;
        while(i < ver1.size() || j < ver2.size()) {
            int a = i < ver1.size() ? ver1[i] : 0;
            int b = j < ver2.size() ? ver2[j] : 0;
            if(a < b) return -1;
            else if(a > b) return 1;
            i++;
            j++;
        }
        return 0;
    }
};