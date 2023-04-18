class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string numm = to_string(num);
        int i=0, j=0;
        string div = "";
        int ans = 0;
        while(j < numm.length()){
            div += numm[j];
            if(j-i+1 == k){
                if(stoi(div) != 0 && num%stoi(div) == 0) ans++;
                div = div.substr(1, k-1);
                i++;
            }
            j++;
        }
        return ans;
    }
};