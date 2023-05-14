//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class IntArray
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {

  public:
    using ll = long long int;
    /*  RECURSIVE (TLE) take (n-1)th or skip it and take (n-2)th NOW MEMOIZE IT___________
    long long fun(int n, vector<int> &arr){
        if(n <= 0) return 0;
        ll first = (ll)arr[n-1] + fun(n-1, arr);
        ll second = INT_MIN;
        if(n > 1) second = (ll)arr[n-2] + fun(n-2, arr);
        
        return max(first, second);
    }
    */
    
    long long memo(int n, vector<int> &arr, vector<ll> &dp){
        if(n <= 0) return 0;
        
        if(dp[n] != -1) return dp[n];
        
        
        ll first = (ll)arr[n-1] + memo(n-1, arr, dp); //take
        ll second = 0;
        if(n > 1) second = (ll)arr[n-2] + memo(n-2, arr, dp); //not take (n-1)th, take (n-2)th
        
        return dp[n] = max(first, second);
    }
    
    long long findMaxSubsetSum(int N, vector<int> &A) {
        // return fun(N, A); //RECURSIVE
        
        //MEMO
        vector<ll> dp(N+1, -1);
        return memo(N, A, dp);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        IntArray::input(A,N);
        
        Solution obj;
        long long res = obj.findMaxSubsetSum(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends