//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string kthPermutation(int n, int k)
    {
        //Brute force solution is, generate all the possible permutations, then return kth
        //another approach is iterative
        string ans = "";
        string s = "";
        int fact = 1; //calculate factorial for each block (n-1 numbers of remaining sequence)
        for(int i=1; i<=n; i++){
            fact *= i;
            s += to_string(i);
        }
        fact = fact/n; // n = s.length()
        k = k-1; //0-based indexing
        while(true){
            int ind = k/fact;
            ans += s[ind];
            s.erase(s.begin()+ind);
            if(s.length() == 0) break;
            
            k = k%fact;
            fact = fact/s.length();
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends