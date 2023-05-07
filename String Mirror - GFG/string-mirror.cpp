//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    string stringMirror(string str){
        int n = str.length();
        if(n == 1) return (str+str);
        if(n >= 2 && str[0] == str[1]) return str.substr(0, 2);
        string temp = "";
        temp += str[0];
        for(int i=1; i<n; i++){
            if(temp[temp.length()-1] >= str[i]){
                temp += str[i];
            }
            else break;
        }
        string rev = temp;
        reverse(rev.begin(), rev.end());
        return temp+rev;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        Solution ob;
        string res=ob.stringMirror(str);
        cout<<res<<endl;
    }
}
// } Driver Code Ends