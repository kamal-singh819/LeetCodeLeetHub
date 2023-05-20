//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int N, int groupSize, vector<int> &hand) {
        map<int, int> mp;
        for(int x : hand) mp[x]++;
        
        for(auto x : mp){
            int y = x.first;
            if(mp[y] == 0) continue;
            mp[y]--;
            for(int i=1; i<groupSize; i++){
                int next = y+i;
                
                if(mp[next] == 0) return false;
                
                mp[next]--;
            }
        }
        
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends