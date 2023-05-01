//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        //create adjacency list
        vector<vector<pair<int, int>> > adj(N);
        for(auto edge : edges){
            adj[edge[0]].push_back({edge[1], edge[2]});
        }
        //store indegree of each node
        vector<int> indegree(N);
        for(int i=0; i<N; i++){
            for(int j=0; j<adj[i].size(); j++) indegree[adj[i][j].first]++;
        }
        //create topological sort vector 
        vector<int> topo;
        queue<int> q;
        for(int i=0; i<N; i++){
            if(indegree[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int fnt = q.front();
            q.pop();
            topo.push_back(fnt);
            for(auto x : adj[fnt]){
                indegree[x.first]--;
                if(indegree[x.first] == 0) q.push(x.first);
            }
        }
        //for(int i=0; i<topo.size(); i++) cout<<topo[i]<<" ";
        //now topo vector is created.................................
        //Now find min. distance vector 
        vector<int> ans(N, 1e5+1);
        ans[0] = 0;
        for(int u : topo){
            for(auto v : adj[u]){ //v is pair of  neighbour and dist
                if(ans[v.first] > ans[u] + v.second)
                    ans[v.first] = ans[u]+v.second;
            }
        }
        for(int i=0; i<ans.size(); i++){
            if(ans[i] == 1e5+1) ans[i] = -1;
        }
        return ans;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends