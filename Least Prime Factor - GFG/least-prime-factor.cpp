//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> leastPrimeFactor(int n) {
        vector<int> ans(n+1, 0);
        ans[1] = 1;
        ans[2] = 2;
        if(n == 2) return ans;
        for(int i=3; i<=n; i++){
            for (int j = 2; j * j <= i; j++) {
                if (i % j == 0) {
                    ans[i] = j; // Smallest prime factor found
                    break;
                }
            }
            if(ans[i] == 0) ans[i] = i;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        vector<int>ans = ob.leastPrimeFactor(n);
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;  
    }
    return 0;
}

// } Driver Code Ends