//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    bool makePalindrome(int n, vector<string> &arr){
        unordered_set<string> st;
        for(auto x : arr){
            string str = x;
            reverse(str.begin(), str.end());
            if(st.count(str)) st.erase(str);
            else if(!st.count(x)) st.insert(x); 
        }
        if(st.size() == 0) return true;
        if(st.size() == 1){
            string temp = *st.begin();
            int i=0;
            int j = temp.length()-1;
            while(i <= j){
                if(temp[i] != temp[j]) return false;
                i++;
                j--;
            }
            return true;
        }
        return false;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        if(ob.makePalindrome(n,arr)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
// } Driver Code Ends