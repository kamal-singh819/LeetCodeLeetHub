class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        if(len1 != len2)
            return false;
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        vector<int> num1;
        vector<char> arr1;
        vector<int> num2;
        vector<char> arr2;

        for(int i=0; i<len1; i++){
            mp1[word1[i]]++;
            mp2[word2[i]]++;
        } 

        for(const auto &x : mp1){
            num1.push_back(x.second);
            arr1.push_back(x.first);
        }
        
        for(const auto &x : mp2){
            num2.push_back(x.second);
            arr2.push_back(x.first);
        }

        sort(num1.begin(), num1.end());
        sort(arr1.begin(), arr1.end());
        sort(num2.begin(), num2.end());
        sort(arr2.begin(), arr2.end());

        for(int i=0; i<num1.size(); i++){
            if(arr1[i] != arr2[i] || num1[i] != num2[i])
           return false;
        }
        return true; 
        
    }
};