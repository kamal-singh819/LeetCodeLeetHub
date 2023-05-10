//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int totalCuts(int N,int K,vector<int> &A){
        vector<int> maxStart(N);
        
        maxStart[0] = A[0];
        for(int i=1; i<N; i++) maxStart[i] = max(A[i], maxStart[i-1]);
        
        vector<int> minEnd(N);
        minEnd[N-1] = A[N-1];
        for(int i=N-2; i>= 0; i--) minEnd[i] = min(A[i], minEnd[i+1]);
        
        int ans = 0;
        for(int i=0;i<N-1; i++){
            if(maxStart[i]+minEnd[i+1] >= K) ans++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,K;
        cin>>N>>K;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        cout<<ob.totalCuts(N,K,A)<<endl;
    }
    return 0;
}
// } Driver Code Ends