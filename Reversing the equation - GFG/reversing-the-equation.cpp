//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s)
    {
        int n = s.length();
        stack<string> st;
        unordered_set<char> uset;
        uset.insert('+');
        uset.insert('-');
        uset.insert('*');
        uset.insert('/');
        int i = 0;
        while(i < n){
            string str = "";
            while(i < n && !uset.count(s[i])){
                str += s[i];
                i++;
            }
            if(uset.count(s[i])){
                st.push(s[i]+str);
                i++;
            }
            if(i == n){
                st.push(str);
                break;
            }
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends