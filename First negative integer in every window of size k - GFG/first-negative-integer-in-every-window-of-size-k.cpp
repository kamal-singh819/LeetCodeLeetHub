//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
                                                 
    // deque<long long int> dq;
    // vector<long long int> ans;
    
    // for(int i=0; i<K; i++){
    //     if(A[i] < 0)
    //         dq.push_back(i);
    // }
    
    // //store ans of first K size
    // if(dq.size() > 0)
    //     ans.push_back(A[dq.front()]);
    // else
    //     ans.push_back(0);
        
    // //now process remaining element
    
    // for(int i=K; i<N; i++){
    //     //remove front
    //     if(!dq.empty() && i-dq.front() >= K)
    //         dq.pop_front();
            
    //     //add at end
    //     if(A[i] < 0)
    //         dq.push_back(i);
        
    //     //store the answer    
    //     if(dq.size() > 0)
    //         ans.push_back(A[dq.front()]);
    //     else
    //         ans.push_back(0);    
    // }
    using ll = long long int;
    vector<ll> ans;
    queue<ll> q;
    ll i=0, j=0;
    while(j < N){
        if(A[j] < 0)
            q.push(A[j]);
        
        if(j-i+1 == K){
            if(q.empty())
               ans.push_back(0);
            else{
                ans.push_back(q.front());
                if(A[i] == q.front()) q.pop(); //coz we have to increment i to shift the window
            }  
            i++;
        }  
        j++;
    }
    return ans;
 }