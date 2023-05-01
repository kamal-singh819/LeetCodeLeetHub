//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
using ll = long long int;
class Solution{
    private:
    bool possibleToDistribute(ll mid, vector<int> &sweet, int &n, int k){
        int cnt = 0;
        int i=0, j = 0;
        while(i < n){
            j = i;
            ll s = 0;
            while(j < n){
                s += sweet[j];
                j++;
                if(s >= mid) break;
            }
            if(s >= mid) cnt++;
            i = j;
        }
        return cnt >= k;
    }
    
    public:
    int maxSweetness(vector<int>& sweetness, int N, int K) {
        ll high = 0;
        for(int i=0; i<N; i++) high += (ll)sweetness[i];
        ll low = 1;
        //now we have low ans high
        if(K == 0) return (int)high;
        int ans = 0;
        while(low <= high){
            ll mid = low + (high-low)/2;
            if(possibleToDistribute(mid, sweetness, N, K+1)){
                ans = mid;
                low = mid+1;
            }
            else high = mid-1;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> sweetness(n);
        for (int i = 0; i < n; i++) {
            cin >> sweetness[i];
        }
          Solution ob;
          int res=ob.maxSweetness(sweetness, n, k);
        cout << res << endl;
    }
}
// } Driver Code Ends