class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        int last = 0;
        double ans = 0;
        for(int i=0; i<brackets.size(); i++){
            int tax = brackets[i][0]-last;
            if(income >= tax){
                ans += double(tax*brackets[i][1]/100.0);
                last = brackets[i][0];
                income -= tax;
            }
            else if(income < tax){
                ans += double(income*brackets[i][1]/100.0);
                income = 0;
                break;
            }
        }
        return ans;  
    }
};