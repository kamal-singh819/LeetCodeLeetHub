//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<string> CamelCase(int N, vector<string> Dictionary, string Pattern) {
        vector<string> ans;
        int m = Pattern.length();
        for(auto str : Dictionary){
            int n = str.length();
            int k = 0; //for traverse pattern string
            for(int j = 0; j<n; j++){
                if(isupper(str[j])){
                    if(k < m && Pattern[k] == str[j]) k++;
                    else break;
                }
            }
            if(k == m) ans.push_back(str);
        }
        if(ans.empty()) ans.push_back("-1");
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends