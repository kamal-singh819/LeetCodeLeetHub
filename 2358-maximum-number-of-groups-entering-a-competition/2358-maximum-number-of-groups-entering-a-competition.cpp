class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n = grades.size();
        sort(grades.begin(), grades.end());
        int ans = 0;
        for(int i=1; i<=n; i++){
            n = n-i;
            if(n < 0) return ans;
            ans++;
        }
        return ans;
    }
};