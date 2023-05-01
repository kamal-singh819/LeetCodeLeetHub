//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
        void solve(string &s, int index, vector<string> &ans){
            if(index >= s.length()){
                ans.push_back(s);
                return;
            }
            for(int i=index; i<s.length(); i++){
                if(i > index && s[i] == s[i-1]) continue; //to remove duplicates
                swap(s[i], s[index]);
                solve(s, index+1, ans);
                swap(s[i], s[index]);
            }
        }
	public:
		vector<string>find_permutation(string S)
		{
		    vector<string> ans;
		    solve(S, 0, ans);
		    //sort the ans array lexicographically
		    sort(ans.begin(), ans.end());
		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends