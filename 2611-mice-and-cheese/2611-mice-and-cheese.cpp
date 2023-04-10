class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n = reward1.size();
        vector<pair<int, pair<int,int> > > vp;
        for(int i=0; i<n; i++){
            vp.push_back({reward1[i]-reward2[i], {reward1[i], reward2[i]}});
        }
        sort(vp.begin(), vp.end(), greater<>());
        
        int score = 0;
        for(int i=0; i<vp.size(); i++){
            int mice1 = vp[i].second.first;
            int mice2 = vp[i].second.second;
            if(i < k) score += mice1;
            else score += mice2;
        }
        return score;
        
    }
};