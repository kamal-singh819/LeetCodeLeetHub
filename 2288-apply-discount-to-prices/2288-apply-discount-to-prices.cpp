class Solution {
public:
    string discountPrices(string sentence, int discount) {
        string ans = "";
        for(int i=0; i<sentence.length(); ){
            if((i == 0 && sentence[i] == '$') || (i > 0 && sentence[i-1] == ' ' && sentence[i] == '$')){
                ans += '$';
                string n = "";
                int j = i+1;
                while(isdigit(sentence[j])){
                    n += sentence[j];
                    j++;
                }
                if(sentence[j] == ' ' || j == sentence.length()){
                    if(n.length() > 0){
                        long long num = stol(n);
                        long double temp = num*1.0 - (long double)(num*discount)/100.0;
                        ans += to_string(temp);
                        ans.pop_back();
                        ans.pop_back();
                        ans.pop_back();
                        ans.pop_back();
                    }
                }
                else{
                    ans += n;
                }
                i = j;
            }
            else ans += sentence[i++];
        }
        return ans;
    }
};