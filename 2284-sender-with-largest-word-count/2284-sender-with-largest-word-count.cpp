class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string, int> mp; //stores sender and word count of corresponding message
        int n = senders.size();
        string ans = "";
        int wordCnt = 0;
        for(int i=0; i<n; i++){
            int cntSpaces = count(messages[i].begin(), messages[i].end(), ' ');
            //no. of words = no. of spaces +1
            mp[senders[i]] += (cntSpaces+1);
            if(wordCnt < mp[senders[i]]){
                ans = senders[i];
                wordCnt = mp[senders[i]];
            }
            //if wordCnt is equal of two senders, return lexicographically large name
            else if(wordCnt == mp[senders[i]]){
                if(senders[i] > ans) ans = senders[i];
            }
        }
        return ans;
    }
};