class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n = grades.size();
        sort(grades.begin(), grades.end());
        int x = 1;
        int y = 500; //approx n*(n+1)/2 = 10^5
        int mid = (x+y)/2;
        int ans = 1;
        while(x <= y){
            if((mid*(mid+1))/2 <= n){
                ans = mid;
                x = mid+1;
            }
            else y = mid-1;
            mid = (x+y)/2;
        }
        return ans;
    }
};