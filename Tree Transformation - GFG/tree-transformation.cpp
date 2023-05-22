//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    int solve(int N, vector<int> p){
        //first find out the degree of every node
        vector<int> degree(N, 0);
        for(int i=1; i<N; i++){
            degree[p[i]]++; //p[i] is the parent of i
            degree[i]++;
        }
        
        int mx = *max_element(degree.begin(), degree.end());
        int ans = 0;
        bool flag = true;
        for(int i=0; i<N; i++){
            if(flag && degree[i] == mx) flag = false;
            else if(degree[i] != 1) ans++;
        }
        return ans == N ? 0 : ans;
    }
};


//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<int> p(N);
        for(int i = 0; i < N; i++){
            cin >> p[i];
        }

        Solution obj;
        cout << obj.solve(N, p) << "\n";
    }
}   
// } Driver Code Ends