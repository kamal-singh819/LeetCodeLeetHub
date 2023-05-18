//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    vector<int>kthSmallestNum(int n, vector<vector<int>>&range, int q, vector<int>queries){
        // merge the intervals
        sort(range.begin(), range.end());
        vector<vector<int>> vec;
        for(auto v : range){
            if(!vec.empty() && v[0] <= vec.back()[1])
                vec.back()[1] = max(vec.back()[1], v[1]);
            else vec.push_back(v);
        }
        
        //now find the solution easily
        vector<int> ans;
        for(int i=0; i<q; i++){
            int x = queries[i];
            
            for(int j=0; j<vec.size(); j++){
                int cnt = vec[j][1] - vec[j][0] + 1;
                if(x <= cnt){
                    ans.push_back(vec[j][0] + x-1);
                }
                x -= cnt;
                if(x <= 0) break;
            }
            if(x > 0) ans.push_back(-1);
        }
        return ans;
    } 
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<vector<int>>range(n, vector<int>(2, 0));
	    for(int i = 0 ; i < n; i++){
	        cin >> range[i][0] >> range[i][1];
	    }
	    int q;
	    cin >> q;
	    vector<int>queries;
	    for(int i = 0 ; i < q; i++){
	        int x;
            cin >> x;
	        queries.push_back(x);
	    }
	    Solution ob;
	    vector<int>ans = ob.kthSmallestNum(n, range, q, queries);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout << endl;
	}
	return 0;
}

// } Driver Code Ends