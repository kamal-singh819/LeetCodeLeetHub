class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        int n = words.size();
        int i = 0;
        while(i < n-1 && words[i] != ""){
            ans.push_back(words[i]);
            sort(words[i].begin(), words[i].end());
            int j = i+1;
            while(j < n && words[j] != ""){
                string str = words[j];
                sort(str.begin(), str.end());
                if(words[i] == str) words[j] = "";
                else break;
                j++;
            }
            i = j;
        }
        if(words[n-1] != "") ans.push_back(words[n-1]);
        return ans;
    }
};